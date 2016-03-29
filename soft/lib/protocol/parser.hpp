#ifndef AP_PARSER_HPP
#define AP_PARSER_HPP

#include "protocol.hpp"

#include <container/list.hpp>
#include <base/array.hpp>

#define min(a, b) ((a < b) ? a : b)

namespace Protocol {

  typedef bool (*predicate_func_t)(const void*);
  typedef void (*handle_func_t)(const void*);

  struct Handler {
    predicate_func_t predicate;
    handle_func_t handle;

    Handler(void)
      : predicate(static_cast<predicate_func_t>(0)),
        handle(static_cast<handle_func_t>(0)) {
    }

    template<typename TP, typename TH>
    Handler(TP predicate, TH handle)
      : predicate(static_cast<predicate_func_t>(predicate)),
        handle(static_cast<handle_func_t>(handle)) {
    }
  };


  static u16 check(const u8* buffer, u32 size) {
    u8 chk[2] = {0, 0};
    while(size != 0) {
      chk[1] = chk[1] + chk[0];
      chk[0] = chk[0] + *(buffer++);
      size--;
    }
    return chk[1] << 8 | chk[0];
  }

  template<template<class T> class MsgType, class Payload>
  static u8* pack(Pack<MsgType, Payload>& pack) {
    pack.sync = SYNC;
    pack.message.header.cls = Payload::CLS;
    pack.message.header.id = Payload::ID;
    pack.message.header.length = sizeof(pack.message.payload);
    pack.check = check((u8*)&pack.message, sizeof(pack.message));
    return (u8*)&pack;
  }

  template<template<class T> class MsgType, class Payload>
  struct DefaultHandler : Handler {
    static bool predicate(const void* data) {
      typedef Pack<MsgType, Payload> pack_t;
      auto pak = (pack_t*)data;
      bool ret = true;
      ret &= pak->message.header.cls == Payload::CLS;
      ret &= pak->message.header.id == Payload::ID;
      ret &= pak->message.header.length == sizeof(pak->message.payload);
      return ret;
    }

    DefaultHandler(handle_func_t handle)
      : Handler(predicate, handle) {
    }
  };

  template<u32 MAX_HANDLERS, u32 MAX_BUFFER_SIZE>
  class Parser {

  private:

    enum State {
      SYNC,
      LENGTH,
      CHECK,
      PREDICATE
    };

  private:

    Container::List<MAX_HANDLERS, Protocol::Handler> _handlers;
    u8 _buffer[MAX_BUFFER_SIZE];
    u32 _size;

    u8* cur = _buffer;
    State state = SYNC;
    u32 msg_length = 0;

  private:
    void unoffsetBuffer(u32 offset) {
      if(offset == 0) return;

      _size = _size - offset;

      for(u32 i = 0 ; i < _size ; i++) {
        _buffer[i] = _buffer[offset + i];
      }
    }

    u32 fillBuffer(const u8* buffer, u32 size) {
      u32 ret = 0;
      size += _size;
      while(_size < min(MAX_BUFFER_SIZE, size)) {
        _buffer[_size++] = *(buffer++);
        ret++;
      }
      return ret;
    }

  public:
    Parser(void)
      : _buffer{0}, _size(0) {}

    void addHandler(const Protocol::Handler& handler) {
      _handlers.append(handler);
    }

    void parse(const u8* buffer, u32 size) {
      bool wait_data = false;
      u32 remaining_size = _size - (cur - _buffer);

      do {
        u32 consumed = fillBuffer(buffer, size);
        size = size - consumed;
        buffer += consumed;
        remaining_size = _size - (cur - _buffer);

	if(state == SYNC) {
	  if(remaining_size >= sizeof(u16)) {
	    if(*((u16*)cur) == Protocol::SYNC) {
	      state = LENGTH;
	      unoffsetBuffer(cur - _buffer);
	      cur = _buffer;
	    }
	    else {
	      cur++;
	    }
	  }
	  else {
	    wait_data = true;
	  }
	}
	else if(state == LENGTH) {
	  msg_length = ((Pack<Message, Dummy>*)cur)->message.header.length;

	  if(remaining_size >= sizeof(Protocol::Header) + sizeof(u16)) {
	    if(msg_length >= MAX_BUFFER_SIZE) {
	      state = SYNC;
	      cur++;
	    }
	    else {
	      state = CHECK;
	    }
	  }
	  else {
	    wait_data = true;
	  }
	}
	else if(state == CHECK) {
	  if(remaining_size >= 2*sizeof(u16) + sizeof(Protocol::Header) + msg_length) {
	    const u8* msg = cur + sizeof(u16);
	    const u32 len = sizeof(Protocol::Header) + msg_length;
	    const u16* chk = (const u16*)(msg + len);

	    if(*chk == check(msg, len)) {
	      state = PREDICATE;
	    }
	    else {
	      state = SYNC;
	      cur++;
	    }
	  }
	  else {
	    wait_data = true;
	  }
	}
	else if(state == PREDICATE) {
	  _handlers.doForeach([&](const Handler& handler) {
	      void* msg = static_cast<void*>(cur);
	      if(handler.predicate && handler.predicate(msg)) {
		if(handler.handle) {
		  handler.handle(msg);
		}
	      }
	    });
	  state = SYNC;
	  cur += 2*sizeof(u16) + sizeof(Protocol::Header) + msg_length;
	}

      } while(!wait_data && remaining_size != 0);
    }

  };
}

#endif//AP_PARSER_HPP
