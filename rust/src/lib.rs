#![feature(lang_items)]

extern crate libc;
extern crate rustc_serialize;

use std::slice;
use std::str;
use rustc_serialize::json;
use std::collections::BTreeMap;

// use std::collections::HashMap;
// use rustc_serialize::json::Json;

#[no_mangle]
pub extern "C" fn rust_parse(json: *const u8, len: libc::size_t) -> usize {

  let s = unsafe {
      let slice = slice::from_raw_parts(json, len);
      str::from_utf8(slice)
  };

  //100004\
  let json : BTreeMap<String, Vec<i32>> = json::decode(s.unwrap()).unwrap();
  json.len()
}

#[no_mangle]
pub extern "C" fn fasthash_init() { }
