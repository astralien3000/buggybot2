#include "ap.hpp"
#include <iostream>

using namespace AP;
using namespace std;

#include <container/list.hpp>
#include <base/array.hpp>

namespace AP{
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


  u16 check(const u8* buffer, u32 size) {
    u8 chk[2] = {0, 0};
    while(size != 0) {
      chk[1] = chk[1] + chk[0];
      chk[0] = chk[0] + *(buffer++);
      size--;
    }
    return chk[1] << 8 | chk[0];
  }

  template<template<class T> class MsgType, class Payload>
  u8* pack(Pack<MsgType, Payload>& pack) {
    pack.sync = SYNC;
    pack.message.header.cls = Payload::CLS;
    pack.message.header.id = Payload::ID;
    pack.message.header.length = sizeof(Payload);
    pack.check = check((u8*)&pack.message, sizeof(pack.message));
    return (u8*)&pack;
  }


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

    List<MAX_HANDLERS, AP::Handler> _handlers;
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
  
    void addHandler(const AP::Handler& handler) {
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
	    if(*((u16*)cur) == AP::SYNC) {
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

	  if(remaining_size >= sizeof(AP::Header) + sizeof(u16)) {
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
	  if(remaining_size >= 2*sizeof(u16) + sizeof(AP::Header) + msg_length) {
	    const u8* msg = cur + sizeof(u16);
	    const u32 len = sizeof(AP::Header) + msg_length;
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
	  cur += 2*sizeof(u16) + sizeof(AP::Header) + msg_length;
	}

      } while(!wait_data && remaining_size != 0);
    }

  };
}

bool test_predicate(const void* test) {
  (void)test;
  return ((const Pack<Message, Actuator::ServoAngle>*)test)->message.header.cls == Actuator::ServoAngle::CLS;
}

void test_handle(const void* test) {
  const Pack<Message, Actuator::ServoAngle>* pak = (const Pack<Message, Actuator::ServoAngle>*)test;
  cout << "miew ? " << pak->message.payload.angle << endl;
}

int main(int argc, char* argv[]) {
  AP::Parser<16, 128> parser;

  parser.addHandler(AP::Handler(test_predicate, test_handle));

  Pack<Message, Actuator::ServoAngle> msg = {0};

  msg.sync = AP::SYNC;
  msg.message.header.cls = Actuator::ServoAngle::CLS;
  msg.message.header.id = Actuator::ServoAngle::ID;
  msg.message.header.length = sizeof(msg.message.payload);

  msg.message.payload.angle = 42;
  msg.check = AP::check((const u8*)&(msg.message), sizeof(msg.message));  

  u8* m = pack(msg);

  parser.parse((const u8*)&msg, sizeof(msg)-5);
  parser.parse((((const u8*)&msg) + sizeof(msg) - 5), 5);
  parser.parse((const u8*)&msg, sizeof(msg));

  parser.parse((const u8*)&msg, sizeof(msg)-2);

  msg.message.payload.angle = 666;
  msg.check = AP::check((const u8*)&(msg.message), sizeof(msg.message));  

  parser.parse((((const u8*)&msg) + sizeof(msg) - 2), 2);

  parser.parse((const u8*)&msg, sizeof(msg));

  return 0;
}
