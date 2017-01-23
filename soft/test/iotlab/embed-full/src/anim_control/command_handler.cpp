#include "command_handler.hpp"
#include "../model.hpp"
#include <stream/string_stream.hpp>
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

coap::ReturnCode CommandHandler::handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
  if(_opt_uri(req, "robot")) {
    if(req.getMethodCode() == coap::MethodCode::PUT) {
      if(sizeof(char) == req.getPayloadLength()) {
        command = req.getPayload()[0];
        if(res.makeResponse(req, coap::ResponseCode::CHANGED, coap::ContentType::TEXT_PLAIN, (uint8_t*)&command, 1) == coap::Error::NONE) {
          return coap::ReturnCode::SEND;
        }
        else {
          return coap::ReturnCode::ERROR;
        }
      }
    }
    if(req.getMethodCode() == coap::MethodCode::GET) {
      if(res.makeResponse(req, coap::ResponseCode::CONTENT, coap::ContentType::TEXT_PLAIN, (uint8_t*)&command, 1) == coap::Error::NONE) {
        return coap::ReturnCode::SEND;
      }
      else {
        return coap::ReturnCode::ERROR;
      }
    }
  }
  return coap::ReturnCode::NEXT_HANDLER;
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
size_t SimpleDiscoveryInputStream<CommandHandler>::read(uint8_t* buffer, size_t size) {
  char* cur = (char*)buffer;

  if(!_try_add_page(cur, size, "/robot")) {
    return (size_t)((uint8_t*)cur - buffer);
  }
  
  return (size_t)((uint8_t*)cur - buffer);
}
}
