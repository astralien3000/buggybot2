#include "servo_handler.hpp"
#include <stream/riot/uart_stream.hpp>
#include <feetech/sc.hpp>
#include <stream/string_stream.hpp>
#include <stream/formatted_stream.hpp>
#include <stdio.h>

static RIOT::UARTStream<> _sc_uart(1, 1000000);
Aversive::Feetech::SC<RIOT::UARTStream<>> sc(_sc_uart);
static const char* _prefix = "feetech";

enum class ServoReg {
  NONE,
  POSITION,
  TORQUE_EN,
  ID,
};

static bool _is_uri_path(coap::OptionReader& opt) {
  return opt.getNum() == coap::OptionNum::URI_PATH;
}

static bool _is_uri_path(coap::OptionReader& opt, const char* str) {
  return _is_uri_path(opt) &&
      strncmp(str, (const char*)opt.getValue(), opt.getLength()) == 0;
}

static bool _get_request_params(const coap::PacketReader& req, uint8_t& id_out, ServoReg& reg_out, coap::Method& method_out) {
  int state = 0;
  
  method_out = (coap::Method)req.getCode();
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
      if(_is_uri_path(opt, "id")) {
        reg_out = ServoReg::ID;
        state++;
      }
      else if(_is_uri_path(opt, "torque_en")) {
        reg_out = ServoReg::TORQUE_EN;
        state++;
      }
      else if(_is_uri_path(opt, "position")) {
        reg_out = ServoReg::POSITION;
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
static coap::Error _content(const coap::PacketReader& req, coap::PacketBuilder& res, T content) {
  Aversive::Stream::StringStream<16> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);
  
  fss << content;
  
  return res.makeResponse(
        req,
        coap::ResponseCode::CONTENT,
        coap::ContentType::TEXT_PLAIN,
        ss
        );
}

template<typename T>
static coap::Error _changed(const coap::PacketReader& req, coap::PacketBuilder& res, T content) {
  Aversive::Stream::StringStream<16> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)> fss(ss);
  
  fss << content;
  
  return res.makeResponse(
        req,
        coap::ResponseCode::CHANGED,
        coap::ContentType::TEXT_PLAIN,
        ss
        );
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

coap::Error ServoHandler::handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
  uint8_t id = 0;
  ServoReg sreg = ServoReg::NONE;
  coap::Method method = coap::Method::GET;
  if(_get_request_params(req, id, sreg, method)) {
    if(sreg == ServoReg::ID) {
      if(method == coap::Method::GET) {
        return _content(req, res, id);
      }
    }
    else if(sreg == ServoReg::POSITION) {
      if(method == coap::Method::GET) {
        return _content(req, res, sc.getPosition(id));
      }
      else if(method == coap::Method::PUT) {
        uint16_t val = _to_int<uint16_t>(req.getPayload(), req.getPayloadLength());
        sc.setPosition(id, val);
        return _changed(req, res, (uint16_t)val);
      }
    }
    else if(sreg == ServoReg::TORQUE_EN) {
      if(method == coap::Method::GET) {
        return _content(req, res, (uint8_t)sc.isTorqueEnabled(id));
      }
      else if(method == coap::Method::PUT) {
        uint8_t val = _to_int<uint8_t>(req.getPayload(), req.getPayloadLength());
        if(val == 1) sc.enableTorque(id);
        else sc.disableTorque(id);
        return _changed(req, res, (uint8_t)val);
      }
    }
  }
  
  return coap::Error::UNSUPPORTED;
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
size_t SimpleDiscoveryInputStream<ServoHandler>::read(uint8_t* buffer, size_t size) {
  char* cur = (char*)buffer;
  
  for(uint8_t i = 0 ; i < 15 ; i++) {
    if(sc.ping(i)) {
      if(!_try_add_page(cur, size, i, "id")) {
        return (size_t)((uint8_t*)cur - buffer);
      }

      if(!_try_add_page(cur, size, i, "torque_en")) {
        return (size_t)((uint8_t*)cur - buffer);
      }

      if(!_try_add_page(cur, size, i, "position")) {
        return (size_t)((uint8_t*)cur - buffer);
      }
    }
  }
  
  return (size_t)((uint8_t*)cur - buffer);
}
}
