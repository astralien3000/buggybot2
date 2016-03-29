#ifndef AP_HPP
#define AP_HPP

#include <base/integer.hpp>

#define PACKED __attribute__((packed))
AP_HPP
namespace Protocol {
  constexpr u16 SYNC = 0xA572;

  struct Dummy {
  };

  struct Header {
    u8 cls;
    u8 id;
    u8 length;
  } PACKED;

  template<class Payload>
  struct Message {
    Header header;
    Payload payload;
  } PACKED;

  template<class Payload>
  struct PollRequest {
    Header header;
    typename Payload::Poll payload;
  } PACKED;

  template<template<class T> class MsgType, class Payload>
  struct Pack {
    u16 sync;
    MsgType<Payload> message;
    u16 check;
  } PACKED;

}

#endif//AP_HPP
