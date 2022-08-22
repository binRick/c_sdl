#pragma once
#include "sdl-app.h"
//////////////////////////////////////
#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
//////////////////////////////////////
#include "cargs/include/cargs.h"
#include "sdl-term-app-test.h"
#include "submodules/c_deps/submodules/c_darwin/active-app/active-app.h"
#include "submodules/c_greatest/greatest/greatest.h"
#include "submodules/c_timer/include/c_timer.h"
#include "submodules/chan/src/chan.h"
#include "submodules/debug_print_h/include/debug_print.h"
#include "submodules/log.h/log.h"
#include "submodules/ms/ms.h"
//#include "submodules/SDL_DBGP/SDL_DBGP.h"
#include "submodules/timestamp/timestamp.h"

typedef struct WORKER_T {
  int  delay_ms;
  int  thread_index;
  char msg[1024];
} worker_t;

int sdl_term_app_main(void);
void render_screen(void);
