#ifndef SERVO_HPP
#define SERVO_HPP

#include <device/input.hpp>
#include <device/output.hpp>

class _ServoBase : public Input<u32>, public Output<u32> {};

template<u32 PIN_ID>
class Servo : public _ServoBase {
private:
  u32 _cmd;

public:
  Servo(void) {
        static_assert(PIN_ID == -1, "Servo not available");
  }

  void setValue(u32 cmd) {
  }

  u32 getValue(void) {
    return _cmd;
  }
};

#include "servo_impl.hpp"

#endif//SERVO_HPP
