#include "anim_handler.hpp"
#include <stream/riot/uart_stream.hpp>
#include <feetech/sc.hpp>
#include <stream/string_stream.hpp>
#include <stream/formatted_stream.hpp>
#include <stdio.h>

extern Aversive::Feetech::SC<RIOT::UARTStream<>> sc;

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

static uint8_t map[12] = {2,3,4,5,6,7,8,9,10,11,12,13};

coap::Error AnimHandler::handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
  if(_opt_uri(req, "map")) {
    if((coap::Method)req.getCode() == coap::Method::POST) {
      if(sizeof(map) == req.getPayloadLength()) {
        for(size_t i = 0 ; i < 12 ; i++) {
          map[i] = req.getPayload()[i];
        }
        return res.makeResponse(req, coap::ResponseCode::CHANGED);
      }
    }
  }

  if(_opt_uri(req, "anim")) {
    if((coap::Method)req.getCode() == coap::Method::POST) {
      if(sizeof(uint16_t[12]) == req.getPayloadLength()) {
        uint16_t* servo = (uint16_t*)req.getPayload();
        for(size_t i = 0 ; i < 12 ; i++) {
          sc.enableTorque(map[i]);
          sc.setPosition(map[i], servo[i]);
        }
        return res.makeResponse(req, coap::ResponseCode::CHANGED);
      }
    }
  }
  
  return coap::Error::UNSUPPORTED;
}

static bool _try_add_page(char* &cur, size_t size, const char* page) {
  Aversive::Stream::StringStream<64> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);
  
  fss << "<" << page << ">;ct=0,";
  uint16_t s =  ss.readable();
  if(s < size) {
    ss.read((uint8_t*)cur, s);
    cur += s;
    size -= s;
  }
  else {
    return false;
  }
  return true;
}

namespace coap {
size_t SimpleDiscoveryInputStream<AnimHandler>::read(uint8_t* buffer, size_t size) {
  char* cur = (char*)buffer;

  if(!_try_add_page(cur, size, "/anim")) {
    return (size_t)((uint8_t*)cur - buffer);
  }
  
  if(!_try_add_page(cur, size, "/map")) {
    return (size_t)((uint8_t*)cur - buffer);
  }
  
  return (size_t)((uint8_t*)cur - buffer);
}
}
