#include "label_handler.hpp"
#include "../model.hpp"
#include <stream/string_stream.hpp>
#include <stream/formatted_stream.hpp>
#include <stdio.h>

#include <xtimer.h>

static const char* _prefix = "feetech";

const char* _labels[12] = {
  "LF0", "LF1", "LF2",
  "RF0", "RF1", "RF2",
  "RB0", "RB1", "RB2",
  "LB0", "LB1", "LB2",
};

static bool _is_uri_path(coap::OptionReader& opt) {
  return opt.getNum() == coap::OptionNum::URI_PATH;
}

static bool _is_uri_path(coap::OptionReader& opt, const char* str) {
  return _is_uri_path(opt) &&
      strncmp(str, (const char*)opt.getValue(), opt.getLength()) == 0;
}

static bool _get_request_params(const coap::PacketReader& req, uint8_t& id_out, coap::MethodCode& method_out) {
  int state = 0;

  method_out = req.getMethodCode();
  for(auto it = req.getOptionsBegin() ; it != req.getOptionsEnd() ; it++) {
    auto opt = *it;
    if(state == 0) {
      if(_is_uri_path(opt, _prefix)) {
        state++;
      }
    }
    else if(state == 1) {
      if(_is_uri_path(opt)) {
        Aversive::Stream::StringStream<64> ss;
        Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);
        ss.write((uint8_t*)opt.getValue(), opt.getLength());
        ss.write((uint8_t*)"\0", 1);
        fss >> id_out;
        state++;
      }
      else {
        return false;
      }
    }
    else if(state == 2) {
      if(_is_uri_path(opt, "label")) {
        state++;
      }
      else {
        return false;
      }
    }
    else {
      if(_is_uri_path(opt)) {
        return false;
      }
      else {
        return true;
      }
    }
  }
  return state == 3;
}

template<typename T>
static coap::Error _content(const coap::PacketReader& req, coap::PacketBuilder& res, coap::ResponseCode code, T content) {
  Aversive::Stream::StringStream<16> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);

  fss << content;

  return res.makeResponse(req, code, coap::ContentType::TEXT_PLAIN, ss);
}

template<typename T>
static T _to_int(const uint8_t* str, size_t len) {
  Aversive::Stream::StringStream<16> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);

  ss.write((uint8_t*)str, (uint16_t)len);
  ss.write((uint8_t*)"\0", 1);
  T ret = 0;
  fss >> ret;
  return ret;
}

coap::ReturnCode _rc(coap::Error err) {
  if(err == coap::Error::NONE) {
    return coap::ReturnCode::SEND;
  }
  return coap::ReturnCode::ERROR;
}

coap::ReturnCode LabelHandler::handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
  uint8_t servo = 0;
  coap::MethodCode method = coap::MethodCode::GET;
  if(_get_request_params(req, servo, method)) {
    if(method == coap::MethodCode::GET) {
      for(int i = 0 ; i < 12 ; i++) {
        if(servo == map[i]) {
          return _rc(res.makeResponse(req, coap::ResponseCode::CONTENT, coap::ContentType::TEXT_PLAIN, (const uint8_t*)_labels[i], strlen(_labels[i])));
        }
      }
      return _rc(res.makeResponse(req, coap::ResponseCode::CONTENT, coap::ContentType::TEXT_PLAIN, (const uint8_t*)"", strlen("")));
    }
    else if(method == coap::MethodCode::PUT) {
      for(int i = 0 ; i < 12 ; i++) {
        if(servo == map[i]) {
          map[i] = 0;
        }
        if(strncmp(_labels[i], (const char*)req.getPayload(), req.getPayloadLength()) == 0) {
          map[i] = servo;
          return _rc(res.makeResponse(req, coap::ResponseCode::CHANGED, coap::ContentType::TEXT_PLAIN, (const uint8_t*)_labels[i], strlen(_labels[i])));
        }
      }
      if(strncmp("", (const char*)req.getPayload(), req.getPayloadLength()) == 0) {
        return _rc(res.makeResponse(req, coap::ResponseCode::CHANGED, coap::ContentType::TEXT_PLAIN, (const uint8_t*)"", strlen("")));
      }
      return _rc(res.makeResponse(req, coap::ResponseCode::NOT_ACCEPTABLE, coap::ContentType::TEXT_PLAIN, (const uint8_t*)"", strlen("")));
    }
    else {
      if(res.makeResponse(req, coap::ResponseCode::METHOD_NOT_ALLOWED) == coap::Error::NONE) {
        return coap::ReturnCode::SEND;
      }
      else {
        return coap::ReturnCode::ERROR;
      }
    }
  }

  return coap::ReturnCode::NEXT_HANDLER;
}

static bool _try_add_page(char* &cur, size_t size, uint8_t i, const char* page) {
  Aversive::Stream::StringStream<64> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);

  fss << "</" << _prefix << "/" << (uint16_t)i << "/" << page << ">;ct=0,";
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
size_t SimpleDiscoveryInputStream<LabelHandler>::read(uint8_t* buffer, size_t size) {
  char* cur = (char*)buffer;

  for(uint8_t i = 0 ; i < 15 ; i++) {
    if(sc.ping(i)) {
      if(!_try_add_page(cur, size, i, "label")) {
        return (size_t)((uint8_t*)cur - buffer);
      }
    }
    xtimer_usleep(200);
  }

  return (size_t)((uint8_t*)cur - buffer);
}
}
