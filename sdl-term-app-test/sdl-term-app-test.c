#define DEBUG_WORKERS      true
#define WINDOW_TITLE       "Application Title"
#define WINDOW_X_OFFSET    400
#define WINDOW_Y_OFFSET    50
#define WIN_WIDTH          800
#define WIN_HEIGHT         300
#define GLYPHS_PER_LINE    (256 / 8)
#define SDL_WINDOW_OPTIONS                        \
  SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI \
  | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP
/////////////////////////////////////////////////////////////////
#include <assert.h>
#include <ctype.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
/////////////////////////////////////////////////////////////////
#include "sdl-term-app-test/sdl-term-app-test.h"
#include "submodules/c_darwin/active-app/active-app.h"
#include "submodules/c_darwin/window-utils/window-utils.h"
/////////////////////////////////////////////////////////////////
#define L    log_debug
#define I    log_info
#define E    log_error
/////////////////////////////////////////////////////////////////
int sdl_term_app_main(void);

/////////////////////////////////////////////////////////////
SDL_Renderer    *renderer;
int             should_quit = 0;
char            msg[1024 * 4];
volatile size_t keypresses = 0;
SDL_Event       event;
DBGP_Font       unscii8;
DBGP_Font       unscii16;
char            *iso_string;
SDL_Window      *window;
/////////////////////////////////////////////////////////////
volatile int    processed_jobs_qty = 0, processed_qtys[1024];
char            msg0[1024 * 2];


/////////////////////////////////////////////////////////////


void window_init(){
  int i = get_focused_pid();

  fprintf(stderr, "found focused pid to be %d.....\n", i);
}


int main(int argc, char **argv) {
  return(sdl_term_app_main());
}


void screenshot(SDL_Renderer *renderer, const char *filename) {
  int width  = 0;
  int height = 0;

  SDL_GetRendererOutputSize(renderer, &width, &height);

  SDL_Surface *screenshot = SDL_CreateRGBSurface(
    0, width, height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

  SDL_RenderReadPixels(
    renderer, NULL, SDL_PIXELFORMAT_ARGB8888, screenshot->pixels,
    screenshot->pitch);
  SDL_SaveBMP(screenshot, filename);
  SDL_FreeSurface(screenshot);
}


void render_screen(void){
  SDL_SetRenderDrawColor(renderer, 0x30, 0x30, 0x30, 0xff);
  SDL_RenderClear(renderer);

  if (strlen(msg0) > 0) {
    DBGP_Print(&unscii16, renderer, 0, 15 * 16, DBGP_DEFAULT_COLORS, msg0);
  }
  if (strlen(msg) > 0) {
    DBGP_Print(&unscii16, renderer, 0, 13 * 16, DBGP_DEFAULT_COLORS, msg);
  }

  DBGP_Print(
    &unscii16, renderer, 40 * 8, 0 * 16, 0x0f,
    "$00    $10    $20    $30    $40    $50    $60    $70");
  DBGP_Print(
    &unscii16, renderer, 40 * 8, 1 * 16, 0x0f,
    "$80    $90    $A0    $B0    $C0    $D0    $E0    $F0");

  DBGP_Print(&unscii16, renderer, 0, 0, 0x5f, "@ SDL_DBGP! @");
  DBGP_Print(
    &unscii16, renderer, 0, 1 * 16, 0x0f,
    "Color can be changed with\n"
    "$09e$0As$0Bc$0Ca$0Dp$0Ee$0F"
    " codes too.");
  DBGP_Print(
    &unscii16, renderer, 0 * 8, 3 * 16, 0x1f, "abcdefghijkl0123456789");
  DBGP_Print(
    &unscii16, renderer, 0 * 8, 4 * 16, 0x3f, "Something $F3somethinG");

  DBGP_Printf(
    &unscii16, renderer, 0, 5 * 16, DBGP_DEFAULT_COLORS,
    "A string with accents: $74%s", iso_string);

  DBGP_Printf(
    &unscii8, renderer, 0, 7 * 16, DBGP_DEFAULT_COLORS,
    "Default fonts include the entire ISO-8859-1 charset:");
  for (int i = 0; i < 256; i++) {
    int x = (8 * 1) + (i % 32) * DBGP_UNSCII8_WIDTH;
    int y = (8 * 16) + (i / 32) * DBGP_UNSCII8_HEIGHT;
    DBGP_Printf(&unscii8, renderer, x, y, DBGP_DEFAULT_COLORS, "%c", i);
  }

  SDL_RenderPresent(renderer);
} /* render_screen */


int sdl_term_app_main(void) {
  static int set_focus_qty = 0;
  static int focused_pid   = -1;

  focused_pid = get_focused_pid();
  log_debug("found focused pid to be %d.....\n", focused_pid);
  pthread_t th;

  iso_string = SDL_iconv_string("ISO-8859-1", "UTF-8", "Ébène", sizeof("Ébène"));
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialise SDL2: %s", SDL_GetError());
    return(1);
  }
  SDL_SetHint(SDL_HINT_BMP_SAVE_LEGACY_FORMAT, "1");

  window = SDL_CreateWindow(
    WINDOW_TITLE,
    WINDOW_X_OFFSET, WINDOW_Y_OFFSET,
    WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPTIONS
    );

  if (window == NULL) {
    SDL_Log("Unable to create window: %s", SDL_GetError());
    return(1);
  }
  renderer = SDL_CreateRenderer(
    window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    SDL_Log("unable to create renderer: %s", SDL_GetError());
    return(1);
  }
  SDL_RenderSetLogicalSize(renderer, WIN_WIDTH, WIN_HEIGHT);

  if (DBGP_OpenFont(
        &unscii16, renderer, DBGP_UNSCII16, sizeof(DBGP_UNSCII16),
        DBGP_UNSCII16_WIDTH, DBGP_UNSCII16_HEIGHT) != 0) {
    SDL_Log("Unable to initialise DBGP_UNSCII16: %s", SDL_GetError());
    return(1);
  }


  if (DBGP_OpenFont(
        &unscii8, renderer, DBGP_UNSCII8, sizeof(DBGP_UNSCII8),
        DBGP_UNSCII8_WIDTH, DBGP_UNSCII8_HEIGHT) != 0) {
    SDL_Log("Unable to initialise DBGP_UNSCII8: %s", SDL_GetError());
    return(1);
  }


  fprintf(stderr,
          "\n**OPTIONS**\n\n"
          "Screenshot: s\n"
          "\n"
          );
  while (!should_quit) {
    while (SDL_PollEvent(&event)) {
      if (should_quit) {
        break;
      }
      keypresses++;
      sprintf(msg0,
              "keypress %s%s$0F%s%lu$0F: |%stype$0F:%d$0F|"
              "     "
              " %sWHITE$0F "
              " %sBLUE$0F "
              " %sGREEN$0F "
              " %sRED$0F "
              " %sCYAN$0F "
              " %sYELLOW$0F "
              " %sTEST$0F ",
              "$20", "#",
              "$E0", keypresses,
              "$04", event.type,
              "$F0",
              "$10",
              "$20",
              "$40",
              "$A0",
              "$E0",
              "$3F"
              );
      fprintf(stderr, "%s\n", msg0);

      switch (event.type) {
      case SDL_QUIT: should_quit = 1; break;

      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_q) {
          log_debug("quitting........");
          should_quit = 1;
          break;
        }
        if (event.key.keysym.sym == SDLK_g) {
          log_debug("focus pid........%d", focused_pid);
          break;
        }
        if (event.key.keysym.sym == SDLK_f) {
          log_debug("found focused pid to be %d.....\n", focused_pid);
          break;
        }
        if (event.key.keysym.sym == SDLK_s) {
          screenshot(renderer, "screenshot.bmp");
          log_debug("screenshot..");
        }
        break;
      }
    }
    render_screen();
  }

  SDL_free(iso_string);
  DBGP_CloseFont(&unscii8);
  DBGP_CloseFont(&unscii16);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return(0);
} /* sdl_term_app_main */
