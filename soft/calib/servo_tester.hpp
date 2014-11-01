#ifndef SERVO_TESTER_HPP
#define SERVO_TESTER_HPP

#include <system/multipwm.hpp>
#include <device/other/pin.hpp>

static constexpr u32 MAX = 2000;
static constexpr u32 MIN = 600;

struct MyMultiPWMConfig : public DefaultMultiPWMConfig {  
  static constexpr u32 PERIOD = 16000;
};

template<u32 PIN_ID>
class ServoTester {
private:
  Pin<PIN_ID> _pin;
  MultiPWM<MyMultiPWMConfig>::Pin _servo;
  u32 _counter;
  u32 _dir;
  
public:
  ServoTester(void)
    : _pin(""),
      _servo(MultiPWM<MyMultiPWMConfig>::instance().createPin(_pin)) {
    
    _pin.setMode(PinMode::OUTPUT);
    
    _counter = MIN;
    _dir = 1;
    
    _servo.setValue(_counter);
  }
  
  void update(void) {
    _counter += _dir;
    if(_counter <= MIN || MAX <= _counter) _dir = -_dir;
    
    _servo.setValue(_counter);
  }

  void update(u32 cmd) {
    _servo.setValue(cmd);
  }
};

#endif//SERVO_TESTER_HPP
