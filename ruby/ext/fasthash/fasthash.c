#include<stdio.h>
#include<ruby.h>

extern int rust_parse(void *, size_t);

VALUE Fasthash = Qnil;
VALUE Fasthash_Hash = Qnil;

VALUE rb_fasthash_hash_len(VALUE self) {
    VALUE json = rb_iv_get(self, "@json");
    
    int result = rust_parse(StringValuePtr(json), RSTRING_LEN(json));

    return INT2FIX(result);
}

VALUE rb_fasthash_hash_initialize(VALUE self, VALUE json)
{
    Check_Type(json, T_STRING);

    rb_iv_set(self, "@json", json);

    return self;
}

void Init_fasthash(void) {
    Fasthash = rb_define_module("Fasthash");
    Fasthash_Hash = rb_define_class_under(Fasthash, "Hash", rb_cObject);

    rb_define_method(Fasthash_Hash, "initialize", rb_fasthash_hash_initialize, 1);
    rb_define_method(Fasthash_Hash, "len", rb_fasthash_hash_len, 0);
}

