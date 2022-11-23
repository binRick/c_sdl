#pragma once
#ifndef CONSOLE_C
#define CONSOLE_C
#define CONSOLE_TITLE "my title"
#define CONSOLE_WINDOW_WIDTH 640
#define CONSOLE_WINDOW_HEIGHT 480
#define CONSOLE_TIMESTAMP_INTERVAL_MS 100
#define LOCAL_DEBUG_MODE    CONSOLE_DEBUG_MODE
#define CONSOLE_FONT_SIZE 20
#define container_of(ptr, type, member) ({ \
                        const typeof( ((type*)0)->member ) \
                        * __mptr = ((void*)(ptr)); \
                        (type*)( (char*)__mptr - \
                        offsetof(type, member) ); \
                        })
////////////////////////////////////////////
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include "console/console.h"
////////////////////////////////////////////
#include "ansi-codes/ansi-codes.h"
#include "bytes/bytes.h"
#include "tempdir.c/tempdir.h"
#define ROWS        40
#define COLS        80
#include "libtmt/tmt.h"
#include "c_fsio/include/fsio.h"
#include "c_string_buffer/include/stringbuffer.h"
#include "c_stringfn/include/stringfn.h"
#include "clamp/clamp.h"
#include "c_vector/vector/vector.h"
#include "log/log.h"
#include "ms/ms.h"
#include "timestamp/timestamp.h"
#include "incbin/incbin.h"
INCBIN(font_glasstty,"assets/Glass_TTY_VT220.ttf");
INCBIN(cmatrix_ansi,"assets/cmatrix.ansi");
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
////////////////////////////////////////////
struct console_event_t {
  SDL_Event event;
  char *text;
  int x, y,qty;
  int r,g,b;
};
static unsigned int callbacks_qty;
static size_t CONSOLE_EVENTS_QTY = 21;
static struct console_event_t **events;
static pthread_mutex_t events_mutex;
static size_t events_qty;
static struct Vector *events_v =NULL;
static char *text;
static TMT *vt;
static int qty;
static bool CONSOLE_DEBUG_MODE = false;
static void __attribute__((constructor)) __constructor__console(void);
static int TimestampThread(void *ptr);
static SDL_Thread *thread;
static SDL_Window *window;
static SDL_Renderer *renderer;
static void tmt_callback(tmt_msg_t m, TMT *vt, const void *a, void *p);
static void printTerminal(TMT *vt);
int console_main(int argc, char *args[]);
////////////////////////////////////////////
static int TimestampThread(void *ptr){
  events_qty=0;
  while(1) {
    struct console_event_t *e = calloc(1,sizeof(struct console_event_t));
    asprintf(&(e->text),"%lld",timestamp());
    pthread_mutex_lock(&events_mutex);

    while(vector_size(events_v)>=CONSOLE_EVENTS_QTY){
      free(vector_pop(events_v));
    }
    e->qty=qty;
    e->x=5;
    e->y=clamp(vector_size(events_v)*CONSOLE_FONT_SIZE, 0, CONSOLE_WINDOW_HEIGHT-CONSOLE_FONT_SIZE);
//    if(e->y>=CONSOLE_WINDOW_HEIGHT-CONSOLE_FONT_SIZE){
//      e->y=0;
//    }
 //   e->y=clamp(qty*15, 0, vector_size(events_v)*10);
    e->r=clamp(qty+35, 0, 256);
    e->g=clamp(qty+75, 0, 256);
    e->b=clamp(qty+65, 0, 256);
    ((SDL_Event*)ptr)->user.data1 = (void*)e;
    SDL_PushEvent((SDL_Event *)ptr);
    qty++;
    vector_push(events_v,(void*)e);
    pthread_mutex_unlock(&events_mutex);
    usleep(1000*CONSOLE_TIMESTAMP_INTERVAL_MS);
    events_qty++;
  }
}

void do_tmt(void *ptr){
  while(1){
    char *in;
    vt= tmt_open(ROWS, COLS, tmt_callback, NULL, NULL);
    asprintf(&in,"\033[0;0H\033[2J%s", (char*)gcmatrix_ansiData);
    tmt_write(vt, in, 0);
    tmt_close(vt);
    free(in);
    sleep(10);
  }
}

int console_main(int argc, char *args[]) {
  struct console_event_t *ee, *e;
  int width, height;
  Uint32 USER_EVENT_TYPE1;
  struct console_event_t event;
  char *tf;
  TTF_Init();
  TTF_Font *font;
  CONSOLE_EVENTS_QTY=CONSOLE_WINDOW_HEIGHT/CONSOLE_FONT_SIZE;
  {
    events_v=vector_new();
  }
  {
    asprintf(&tf,"%s%d%lld",gettempdir(),getpid(),timestamp());
    fsio_write_binary_file(tf,(char*)gfont_glassttyData,gfont_glassttySize);
    assert(fsio_file_size(tf) == gfont_glassttySize);
    font = TTF_OpenFont(tf, CONSOLE_FONT_SIZE);
    fsio_remove(tf);
  }
  {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(CONSOLE_TITLE,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, CONSOLE_WINDOW_HEIGHT, CONSOLE_WINDOW_WIDTH, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  }

  USER_EVENT_TYPE1 = SDL_RegisterEvents(1);
  SDL_memset(&event, 0, sizeof(struct console_event_t));
  event.event.type = USER_EVENT_TYPE1;
  event.event.user.data1=NULL;
  thread = SDL_CreateThread(do_tmt, "tmt", (void *)&event);
//  thread = SDL_CreateThread(TimestampThread, "TimestampThread", (void *)&event);
  while (1) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT) {
      break;
    }else if (event.type == USER_EVENT_TYPE1) {
      log_info("event user");
      pthread_mutex_lock(&events_mutex);
      SDL_RenderClear(renderer);
      SDL_Surface *surface;
      SDL_Texture *texture;
      e=(struct console_event_t*)event.user.data1;
      if(true)
        log_info("adding %lu events",vector_size(events_v));
      unsigned long ts=timestamp(),dur=0;
      for(size_t i=0;i<vector_size(events_v);i++){
        ee=(struct console_event_t*)vector_get(events_v,i);
        log_info("adding event #%lu/%lu @ %dx%d: %s",i+1,vector_size(events_v),ee->x,ee->y,ee->text);
        surface = TTF_RenderText_Solid(font, ee->text, (SDL_Color){ee->r,ee->g,ee->b});
        texture= SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);  
        SDL_RenderFillRect(renderer, &((SDL_Rect){ee->x,ee->y,width,height}));
        SDL_RenderCopy(renderer, texture, NULL, &((SDL_Rect){ee->x,ee->y,width,height}));
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
      }
      dur=timestamp()-ts;
      Ds(milliseconds_to_string(dur));
      SDL_RenderPresent(renderer);
      pthread_mutex_unlock(&events_mutex);
    }
  }
  printf("Exited event loop.\n"); fflush(stdout);
  TTF_CloseFont(font);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
  return 0;
}
static void __attribute__((constructor)) __constructor__console(void){
  if (getenv("DEBUG") != NULL || getenv("DEBUG_console") != NULL) {
    log_debug("Enabling console Debug Mode");
    CONSOLE_DEBUG_MODE = true;
  }
}


void tmt_callback(tmt_msg_t m, TMT *vt, const void *a, void *p){
  callbacks_qty++;
  Ds("callback");
  const TMTSCREEN *s = tmt_screen(vt);
  const TMTPOINT  *c = tmt_cursor(vt);

  switch (m) {
    case TMT_MSG_CURSOR:
      break;
      case TMT_MSG_BELL:
    printf(
      AC_RESETALL AC_BRIGHT_RED "Bell Rang!\n" AC_RESETALL
      );
    break;
  case TMT_MSG_ANSWER:
    printf("Terminal answered %s\n", (const char *)a);
    break;

  case TMT_MSG_MOVED:
    printf(
      AC_RESETALL AC_BRIGHT_RED "Cursor is now at %zdx%zd\n" AC_RESETALL,
      c->r + 1,
      c->c + 1
      );
    break;
    case TMT_MSG_UPDATE:printTerminal(vt);break;
  }
}

static void printTerminal(TMT *vt){
  const TMTSCREEN *s                = tmt_screen(vt);
  const TMTPOINT  *c                = tmt_cursor(vt);
  unsigned int    qty_cells_printed = 0;

  for (size_t r = 0; r < s->nline; r++) {
    struct console_event_t *e = calloc(1,sizeof(struct console_event_t));
    char *line="";
    for (size_t c = 0; c < s->ncol; c++) {
      asprintf(&line,"%s%c",line,s->lines[r]->chars[c].c);
    }
    pthread_mutex_lock(&events_mutex);
    vector_set(events_v,r,(void*)line);
    pthread_mutex_unlock(&events_mutex);

    if (!s->lines[r]->dirty)
      continue;

    for (size_t c = 0; c < s->ncol; c++) {
     if(false){
      printf(
        AC_RESETALL AC_REVERSED AC_BLUE "Contents of" AC_RESETALL
        AC_RESETALL " " AC_RESETALL
        AC_RESETALL AC_BRIGHT_BLUE "%zdx%zd: " AC_RESETALL
        AC_RESETALL AC_BRIGHT_YELLOW "%c" AC_RESETALL
        AC_RESETALL " " AC_RESETALL
        AC_RESETALL "(%s|%s underline|%s reverse|%s dim)" AC_RESETALL
        AC_RESETALL "(fg:%d|bg:%d)\n" AC_RESETALL,
        r + 1, c + 1,
        s->lines[r]->chars[c].c,
        s->lines[r]->chars[c].a.bold ? AC_RESETALL AC_REVERSED AC_GREEN "Bold" AC_RESETALL : AC_RESETALL AC_WHITE "Unbold" AC_RESETALL,
        s->lines[r]->chars[c].a.underline ? "is" : "is not",
        s->lines[r]->chars[c].a.reverse ? "is" : "is not",
        s->lines[r]->chars[c].a.dim ? "is" : "is not",
        (int)(s->lines[r]->chars[c].a.fg),
        (int)(s->lines[r]->chars[c].a.bg)
        );
     }
      qty_cells_printed++;
    }
  }
  if(false){
  printf(
    AC_RESETALL AC_BRIGHT_GREEN AC_REVERSED "%d %s" AC_RESETALL
    AC_RESETALL "\n" AC_RESETALL,
    qty_cells_printed,
    "x"

    );
  }
  e->event.type = SDL_RegisterEvents(1);
  e->event.user.data1=NULL;
  SDL_PushEvent((SDL_Event *)&(e->event));
  tmt_clean(vt);
}
#undef LOCAL_DEBUG_MODE
#endif
