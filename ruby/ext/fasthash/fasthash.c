#include<stdio.h>
#include<ruby.h>

struct Result {
  size_t len;
  int32_t *data;
};

extern struct Result* rust_fetch(int);

VALUE Fasthash = Qnil;
VALUE Fasthash_Hash = Qnil;

VALUE rb_fasthash_hash_fetch(VALUE self, VALUE id) {    
    // int result = rust_parse(StringValuePtr(json), RSTRING_LEN(json));
  FIXNUM_P(id);
  struct Result *result = rust_fetch(NUM2INT(id));
  int len = result->len;
  VALUE values[len];
  for(int i = 0; i < len; i++) {
    values[i] = INT2NUM(result->data[i]);
  }
  return rb_ary_new4(len, values);

}

// TODO: create and store a Rust postgres connection
// VALUE rb_fasthash_hash_initialize(VALUE self, VALUE json)
// {
//     Check_Type(json, T_STRING);

//     rb_iv_set(self, "@json", json);

//     return self;
// }

void Init_fasthash(void) {
    Fasthash = rb_define_module("Fasthash");
    Fasthash_Hash = rb_define_class_under(Fasthash, "Hash", rb_cObject);

    // rb_define_method(Fasthash_Hash, "initialize", rb_fasthash_hash_initialize, 0);
    rb_define_method(Fasthash_Hash, "fetch", rb_fasthash_hash_fetch, 1);
}

