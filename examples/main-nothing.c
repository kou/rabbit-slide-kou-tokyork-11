/* gcc -o main-nothing $(pkg-config --cflags --libs ruby-2.3) -O0 -g3 main-nothing.c */
/* ./main-nothing */

#include <ruby.h>

int
main(void)
{
  char *argv_raw[] = {
    "milter-manager",
    "-e",
    "''"
  };
  int argc;
  char **argv;

  argc = sizeof(argv_raw) / sizeof(char *);
  argv = argv_raw;
  ruby_sysinit(&argc, &argv);
  {
    RUBY_INIT_STACK;
    ruby_init();
    return ruby_run_node(ruby_process_options(argc, argv));
  }
}
