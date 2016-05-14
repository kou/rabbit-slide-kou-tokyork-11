/* gcc -o gc $(pkg-config --cflags --libs ruby-2.3) -O0 -g3 gc.c */
/* ./gc -e '' */

#include <ruby.h>

int rb_objspace_marked_object_p(VALUE obj);

int
main(int argc, char **argv)
{
  ruby_sysinit(&argc, &argv);
  {
    RUBY_INIT_STACK;
    ruby_init();
    ruby_options(argc, argv);
    {
      VALUE object = rb_ary_new();
      VALUE options = rb_hash_new();
      rb_hash_aset(options, rb_id2sym(rb_intern("immediate_sweep")), Qfalse);
      rb_funcall(rb_mGC, rb_intern("start"), 1, options);
      printf("%s\n",
             rb_objspace_marked_object_p(object) ? "marked" : "not marked");
    }
  }
  {
    VALUE object = rb_ary_new();
    VALUE options = rb_hash_new();
    rb_hash_aset(options, rb_id2sym(rb_intern("immediate_sweep")), Qfalse);
    rb_funcall(rb_mGC, rb_intern("start"), 1, options);
    printf("%s\n",
           rb_objspace_marked_object_p(object) ? "marked" : "not marked");
  }

  return 0;
}
