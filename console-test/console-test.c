
#include "ansi-codes/ansi-codes.h"
#include "bytes/bytes.h"
#include "c_fsio/include/fsio.h"
#include "c_greatest/greatest/greatest.h"
#include "c_string_buffer/include/stringbuffer.h"
#include "c_stringfn/include/stringfn.h"
#include "c_vector/vector/vector.h"
#include "console-test/console-test.h"
#include "log/log.h"
#include "ms/ms.h"
#include "timestamp/timestamp.h"
#include "console/console.h"
static char **_argv;
static int _argc;
TEST t_console_test2(){
  PASS();
}

TEST t_console_test1(){
  console_main(_argc,_argv);
  PASS();
}

SUITE(s_console_test) {
  RUN_TEST(t_console_test1);
  if (isatty(STDOUT_FILENO))
    RUN_TEST(t_console_test2);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  _argc=argc;
  _argv=argv;
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_console_test);
  GREATEST_MAIN_END();
}
