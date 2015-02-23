// c headers
#include <stdlib.h>
#include <stdio.h>

// include mruby header files
#include <mruby.h>
#include <mruby/compile.h>

// string conversion header
#include <mruby/string.h>
// number conversion header
#include <mruby/numeric.h>
// array header
#include <mruby/array.h>

int main(void)
{

  // initialize mruby
  mrb_state *mrb = mrb_open();

  // load ruby script
  FILE *file = fopen("mruby_script.rb", "r");
  mrb_load_file(mrb, file);
  fclose(file);

  // invoke method from ruby script,
  // don't pass any arguments to method,
  // ignore return value
  mrb_funcall(mrb, mrb_top_self(mrb), "invoke_me", 0);

  // ### string manipulation

  // create string value form c string
  mrb_value ruby_string = mrb_str_new_cstr(mrb, "some string");

  // pass string to method
  mrb_value return_ruby_string = mrb_funcall(mrb, mrb_top_self(mrb), "one_arg_method", 1, ruby_string);

  // convert ruby string value to c string
  const char *return_c_string = RSTRING_PTR(return_ruby_string);

  // print string value from c
  printf("retrun_c_string: %s\n", return_c_string );

  // ### float manipulation

  // create float value from c float
  mrb_value ruby_float = mrb_float_value(mrb, 3.14);

  // pass float to method
  mrb_value return_ruby_float = mrb_funcall(mrb, mrb_top_self(mrb), "one_arg_method", 1, ruby_float);

  // convert ruby float value to c float
  float return_c_float = mrb_float(return_ruby_float);

  // print float value from c
  printf("retrun_c_string: %g\n", return_c_float );

}
