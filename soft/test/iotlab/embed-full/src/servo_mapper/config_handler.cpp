#include "config_handler.hpp"
#include "../model.hpp"
#include <stream/buffer_stream.hpp>
#include <stream/formatted_stream.hpp>
#include <stdio.h>

#include <xtimer.h>

static const char* _prefix = "feetech";

enum class ConfigReg {
  NONE,
  POSITION1,
  POSITION2,
  ANGLE1,
  ANGLE2,
};

static bool _is_uri_path(coap::OptionReader& opt) {
  return opt.getNum() == coap::OptionNum::URI_PATH;
}

static bool _is_uri_path(coap::OptionReader& opt, const char* str) {
  return _is_uri_path(opt) &&
      strncmp(str, (const char*)opt.getValue(), opt.getLength()) == 0;
}

static bool _get_request_params(const coap::PacketReader& req, uint8_t& id_out, ConfigReg& reg_out, coap::MethodCode& method_out) {
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
        Aversive::Stream::BufferStream<64> ss;
        Aversive::Stream::FormattedStreamDecorator<decltype(ss)>& fss = formatted(ss);
        ss.write((const char*)opt.getValue(), opt.getLength());
        ss.write((const char*)"\0", 1);
        fss >> id_out;
        state++;
      }
      else {
        return false;
      }
    }
    else if(state == 2) {
      if(_is_uri_path(opt, "calib1_position")) {
        reg_out = ConfigReg::POSITION1;
        state++;
      }
      else if(_is_uri_path(opt, "calib2_position")) {
        reg_out = ConfigReg::POSITION2;
        state++;
      }
      else if(_is_uri_path(opt, "calib1_angle")) {
        reg_out = ConfigReg::ANGLE1;
        state++;
      }
      else if(_is_uri_path(opt, "calib2_angle")) {
        reg_out = ConfigReg::ANGLE2;
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
  Aversive::Stream::BufferStream<16> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)>& fss = formatted(ss);

  fss << content;

  return res.makeResponse(req, code, coap::ContentType::TEXT_PLAIN, ss);
}

template<typename T>
static T _to_int(const uint8_t* str, size_t len) {
  Aversive::Stream::BufferStream<16> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)>& fss = formatted(ss);
  
  ss.write((const char*)str, (uint16_t)len);
  ss.write((const char*)"\0", 1);
  T ret = 0;
  fss >> ret;
  return ret;
}

static coap::ReturnCode _handle(const coap::PacketReader& req, coap::PacketBuilder& res, uint16_t& val, coap::MethodCode method) {
  if(method == coap::MethodCode::GET) {
    if(_content(req, res, coap::ResponseCode::CONTENT, val) == coap::Error::NONE) {
      return coap::ReturnCode::SEND;
    }
    else {
      return coap::ReturnCode::ERROR;
    }
  }
  else if(method == coap::MethodCode::PUT) {
    val = _to_int<uint16_t>(req.getPayload(), req.getPayloadLength());
    if(_content(req, res, coap::ResponseCode::CHANGED, val) == coap::Error::NONE) {
      return coap::ReturnCode::SEND;
    }
    else {
      return coap::ReturnCode::ERROR;
    }
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

static coap::ReturnCode _handle(const coap::PacketReader& req, coap::PacketBuilder& res, double& val, coap::MethodCode method) {
  const double coeff = 1000;
  if(method == coap::MethodCode::GET) {
    uint16_t tmp = (uint16_t)(val * coeff);
    if(_content(req, res, coap::ResponseCode::CONTENT, tmp) == coap::Error::NONE) {
      return coap::ReturnCode::SEND;
    }
    else {
      return coap::ReturnCode::ERROR;
    }
  }
  else if(method == coap::MethodCode::PUT) {
    uint16_t tmp = _to_int<uint16_t>(req.getPayload(), req.getPayloadLength());
    val = ((double)tmp) / coeff;
    if(_content(req, res, coap::ResponseCode::CHANGED, tmp) == coap::Error::NONE) {
      return coap::ReturnCode::SEND;
    }
    else {
      return coap::ReturnCode::ERROR;
    }
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

coap::ReturnCode ConfigHandler::handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
  uint8_t id = 0;
  ConfigReg sreg = ConfigReg::NONE;
  coap::MethodCode method = coap::MethodCode::GET;
  if(_get_request_params(req, id, sreg, method)) {
    for(int i = 0 ; i < 12 ; i++) {
      if(map[i] == id) {
        if(sreg == ConfigReg::POSITION1) {
          return _handle(req, res, config[i].calib1.position, method);
        }
        else if(sreg == ConfigReg::POSITION2) {
          return _handle(req, res, config[i].calib2.position, method);
        }
        else if(sreg == ConfigReg::ANGLE1) {
          return _handle(req, res, config[i].calib1.angle, method);
        }
        else if(sreg == ConfigReg::ANGLE2) {
          return _handle(req, res, config[i].calib2.angle, method);
        }
      }
    }
    return coap::ReturnCode::ERROR;
  }
  
  return coap::ReturnCode::NEXT_HANDLER;
}

static bool _try_add_page(char* &cur, size_t size, uint8_t i, const char* page) {
  Aversive::Stream::BufferStream<64> ss;
  Aversive::Stream::FormattedStreamDecorator<decltype(ss)>& fss = formatted(ss);
  
  fss << "</" << _prefix << "/" << (uint16_t)i << "/" << page << ">;ct=0,";
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
size_t SimpleDiscoveryInputStream<ConfigHandler>::read(char* buffer, size_t size) {
  char* cur = (char*)buffer;
  
  for(uint8_t i = 0 ; i < 15 ; i++) {
    if(sc.ping(i)) {
      if(!_try_add_page(cur, size, i, "calib1_position")) {
        return (size_t)((char*)cur - buffer);
      }

      if(!_try_add_page(cur, size, i, "calib1_angle")) {
        return (size_t)((char*)cur - buffer);
      }

      if(!_try_add_page(cur, size, i, "calib2_position")) {
        return (size_t)((char*)cur - buffer);
      }

      if(!_try_add_page(cur, size, i, "calib2_angle")) {
        return (size_t)((char*)cur - buffer);
      }


    }
    xtimer_usleep(200);
  }
  
  return (size_t)((char*)cur - buffer);
}
}
