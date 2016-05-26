// extern crate rustc_serialize;
// use std::collections::HashMap;
// use rustc_serialize::json::Json;

#![feature(lang_items)]

#[no_mangle]
pub extern "C" fn rust_add(x: i32, y: i32) -> i32 {
  x + y
}

#[no_mangle]
pub extern "C" fn fasthash_init() { }
