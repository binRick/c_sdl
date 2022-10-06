#pragma once
#include "sdl-app/sdl-app.h"
//////////////////////////////////////
#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
//////////////////////////////////////
#include "c_greatest/greatest/greatest.h"
#include "c_timer/include/c_timer.h"
#include "cargs/include/cargs.h"
#include "chan/src/chan.h"
#include "debug_print_h/include/debug_print.h"
#include "log/log.h"
#include "ms/ms.h"
#include "sdl-term-app-test/sdl-term-app-test.h"
#include "timestamp/timestamp.h"

typedef struct WORKER_T {
  int  delay_ms;
  int  thread_index;
  char msg[1024];
} worker_t;

int sdl_term_app_main(void);
void render_screen(void);
