#include "anim_handler.hpp"
#include "../model.hpp"
#include <stream/buffer_stream.hpp>
#include <stream/formatted_stream.hpp>
#include <stdio.h>

#include <xtimer.h>

static bool _is_uri_path(coap::OptionReader& opt) {
  return opt.getNum() == coap::OptionNum::URI_PATH;
}

static bool _is_uri_path(coap::OptionReader& opt, const char* str) {
  return _is_uri_path(opt) &&
      strncmp(str, (const char*)opt.getValue(), opt.getLength()) == 0;
}

static bool _opt_uri(const coap::PacketReader& req, const char* uri) {
  for(auto it = req.getOptionsBegin() ; it != req.getOptionsEnd() ; it++) {
    auto opt = *it;
    if(_is_uri_path(opt)) {
      if(_is_uri_path(opt, uri)) {
        return true;
      }
      else {
        return false;
      }
    }
  }
  return false;
}

coap::ReturnCode AnimHandler::handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
  if(_opt_uri(req, "map")) {
    if(req.getMethodCode() == coap::MethodCode::POST) {
      if(sizeof(map) == req.getPayloadLength()) {
        for(size_t i = 0 ; i < 12 ; i++) {
          map[i] = req.getPayload()[i];
        }
        return coap::ReturnCode::NOSEND;
      }
    }
  }

  if(_opt_uri(req, "anim")) {
    if(req.getMethodCode() == coap::MethodCode::POST) {
      if(sizeof(uint16_t[12]) == req.getPayloadLength()) {
        uint16_t* servo = (uint16_t*)req.getPayload();
        for(size_t i = 0 ; i < 12 ; i++) {
          sc.enableTorque(map[i]);
          xtimer_usleep(200);
          sc.setPosition(map[i], servo[i]);
          xtimer_usleep(200);
        }
        return coap::ReturnCode::NOSEND;
      }
    }
  }
  
  return coap::ReturnCode::NEXT_HANDLER;
}

static bool _try_add_page(char* &cur, size_t size, const char* page) {
  Aversive::Stream::BufferStream<64> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss = formatted(ss);
  
  fss << "<" << page << ">;ct=0,";
  uint16_t s =  ss.readable();
  if(s < size) {
    ss.read((char*)cur, s);
    cur += s;
    size -= s;
  }
  else {
    return false;
  }
  return true;
}

namespace coap {
size_t SimpleDiscoveryInputStream<AnimHandler>::read(char* buffer, size_t size) {
  char* cur = (char*)buffer;

  if(!_try_add_page(cur, size, "/anim")) {
    return (size_t)((char*)cur - buffer);
  }
  
  if(!_try_add_page(cur, size, "/map")) {
    return (size_t)((char*)cur - buffer);
  }
  
  return (size_t)((char*)cur - buffer);
}
}
