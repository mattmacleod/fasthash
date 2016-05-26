#include<stdio.h>
#include<ruby.h>

extern int rust_add(int, int);

VALUE add(VALUE x, VALUE y) {
    int result = rust_add(NUM2INT(x), NUM2INT(y));

    return INT2FIX(result);
}

void Init_fasthash(void) {
    VALUE fasthash = rb_define_module("Fasthash");
    printf("INIT\n");

    rb_define_singleton_method(fasthash, "add", add, 0);
}
