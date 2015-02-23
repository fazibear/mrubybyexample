// c headers
#include <stdlib.h>
#include <stdio.h>

// include mruby header files
#include <mruby.h>
#include <mruby/compile.h>

// mruby additional headers
#include <mruby/string.h>
#include <mruby/numeric.h>
#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/variable.h>

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

  // ### nil value

  // create ruby nil value
  mrb_value ruby_nil = mrb_nil_value();

  // pass nil value to method
  mrb_value return_ruby_nil = mrb_funcall(mrb, mrb_top_self(mrb), "one_arg_method", 1, ruby_nil);

  // check if return value is nill
  if (mrb_nil_p(return_ruby_nil)) {
    printf("return_ruby_nil is nil!\n");
  }

  // ### string manipulation

  // create string value form c string
  mrb_value ruby_string = mrb_str_new_cstr(mrb, "some string");

  // pass string to method
  mrb_value return_ruby_string = mrb_funcall(mrb, mrb_top_self(mrb), "one_arg_method", 1, ruby_string);

  // convert ruby string value to c string
  const char *return_c_string = RSTRING_PTR(return_ruby_string);

  // print string value from c
  printf("retrun_c_string: %s\n", return_c_string);

  // ### float manipulation

  // create float value from c float
  mrb_value ruby_float = mrb_float_value(mrb, 3.14);

  // pass float to method
  mrb_value return_ruby_float = mrb_funcall(mrb, mrb_top_self(mrb), "one_arg_method", 1, ruby_float);

  // convert ruby float value to c float
  float return_c_float = mrb_float(return_ruby_float);

  // print float value from c
  printf("retrun_c_string: %g\n", return_c_float);

  // ### methods

  // check if not_existing_method exists ?
  if(mrb_respond_to(mrb, mrb_top_self(mrb), mrb_intern_lit(mrb, "not_existing_method"))){
    printf("not_existing_method exist!\n");
  }else{
    printf("not_existing_method not exist\n");
  }

  // check if invoke_me method exists ?
  if(mrb_respond_to(mrb, mrb_top_self(mrb), mrb_intern_lit(mrb, "invoke_me"))){
    printf("invoke_me method exist\n");
  }else{
    printf("invike_me method not exist!\n");
  }

  // ### classes

  // get ruby class
  mrb_value ruby_class = mrb_vm_const_get(mrb, mrb_intern_lit(mrb,"SomeClass"));

  // create new instance of ruby class
  mrb_value ruby_class_new = mrb_instance_new(mrb, ruby_class);

  // invoke method on instance
  mrb_value ruby_class_value = mrb_funcall(mrb, ruby_class_new, "value", 0);

  // convert and print value
  printf("ruby_class_value: %s\n", RSTRING_PTR(ruby_class_value));

}
