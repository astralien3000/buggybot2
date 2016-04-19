#ifndef PARSER_HPP
#define PARSER_HPP

#include <container/buffer.hpp>
#include <functional>

class Parser {
private:
  Container::Buffer<64, u8> _buff;
  std::function<void(u8*, u16)> _func;

  u16 _sum = 0;
  u16 _crc = 0;

public:
  Parser(std::function<void(u8*, u16)> func)
    : _func(func) {
  }

  void parse(u8 c) {
    _buff.enqueue(c);
    _sum += c;

    while(_buff.head() != 0xAA && !_buff.isEmpty()) {
        _sum -= _buff.head();
        _buff.dequeue();
      }

    if(_buff.usedSpace() == 33) {
        _crc = c;
      }
    else if(_buff.usedSpace() == 34) {
        u16 sum = _sum - (_crc + c);

        _crc = _crc * 256 + c;
        if(_crc != sum) {
            _sum -= _buff.head();
            _buff.dequeue();
          }
        else {
            u8 buffer[34] = {0};
            u16 s = 0;
            while(!_buff.isEmpty()) {
                buffer[s++] = _buff.head();
                _sum -= _buff.head();
                _buff.dequeue();
              }
            _func(buffer, s);
          }
      }
  }
};

#endif//PARSER_HPP
