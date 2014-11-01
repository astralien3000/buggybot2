#include <aversive.hpp>
#include <system/multipwm.hpp>
#include <device/other/pin.hpp>

#include <hardware/interrupts.hpp>

#include <board/adm2560.hpp>

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

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  ServoTester<ADM2560::Pinmap::D10> test1; // D10
  ServoTester<ADM2560::Pinmap::D11> test2; // D11
  ServoTester<ADM2560::Pinmap::D12> test3; // D12

  ServoTester<ADM2560::Pinmap::D2> test4; // D2
  ServoTester<ADM2560::Pinmap::D3> test5; // D3
  ServoTester<ADM2560::Pinmap::D4> test6; // D4

  Interrupts::set();
  
  while(Aversive::sync()) {
    test1.update(800); // Right arm
    test2.update(400); // Left shoulder
    test3.update(1200); // Left forarm

    test4.update(800); // Left arm
    test5.update(450); // Right forarm
    test6.update(1200); // Right shoulder
    for(volatile u32 t = 0 ; t < 2 ; t++) {
    }
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
