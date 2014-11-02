#ifndef SERVO_TESTER_HPP
#define SERVO_TESTER_HPP

#include <system/multipwm.hpp>
#include <device/other/pin.hpp>


struct MyMultiPWMConfig : public DefaultMultiPWMConfig {  
  static constexpr u32 PERIOD = 21000;
};


class GenericServoTester : public Input<u32>, public Output<u32> {};

template<u32 PIN_ID>
class ServoTester : public GenericServoTester {
private:
  Pin<PIN_ID> _pin;
  MultiPWM<MyMultiPWMConfig>::Pin _servo;

  u32 _cmd;

public:
  ServoTester(void)
    : _pin(""),
      _servo(MultiPWM<MyMultiPWMConfig>::instance().createPin(_pin)) {
    
    _pin.setMode(PinMode::OUTPUT);

    _cmd = 1000;
    _servo.setValue(_cmd);
  }

  void setValue(u32 cmd) {
    _cmd = cmd;
    _servo.setValue(cmd);
  }

  u32 getValue(void) {
    return _cmd;
  }
};

//////////////////////////////////////////////////////////////////////////
// Tests

#include <board/adm2560.hpp>
#include <hardware/architecture.hpp>
#include <hardware/timer.hpp>

template <>
class ServoTester<ADM2560::Pinmap::D2> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR3BL = cmd & 0xFF;
    OCR3BH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR3A = (1 << COM3B1) | (1 << WGM30); // Mode PWM, COMB
    TCCR3B = (1 << CS32); // prescaler 256
    DDRE = (1<<4);
    _cmd = 800;
    setValue(800);
  }
};

template <>
class ServoTester<ADM2560::Pinmap::D3> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR3CL = cmd & 0xFF;
    OCR3CH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR3A |= (1 << COM3C1);
    DDRE |= (1<<5);
    _cmd = 800;
    setValue(800);
  }
};

template <>
class ServoTester<ADM2560::Pinmap::D6> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR4AL = cmd & 0xFF;
    OCR4AH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR4A = (1 << COM4A1) | (1 << WGM40); // Mode PWM, COMB
    TCCR4B = (1 << CS42); // prescaler 256
    DDRH |= (1<<3);
    _cmd = 800;
    setValue(800);
  }
};

template <>
class ServoTester<ADM2560::Pinmap::D7> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR4BL = cmd & 0xFF;
    OCR4BH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR4A |= (1 << COM4B1);
    DDRH |= (1<<4);
    _cmd = 800;
    setValue(800);
  }
};

template <>
class ServoTester<ADM2560::Pinmap::D8> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR4CL = cmd & 0xFF;
    OCR4CH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR4A |= (1 << COM4C1);
    DDRH |= (1<<5);
    _cmd = 800;
    setValue(800);
  }
};

template <>
class ServoTester<ADM2560::Pinmap::D9> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR2B = cmd & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR2A = (1 << COM2B1) | (1 << WGM20); // Mode PWM, COMB
    TCCR2B = (1 << CS22)|(1 << CS21); // prescaler 256
    DDRH |= (1<<6);
    _cmd = 30;
    setValue(30);
  }
};

template <>
class ServoTester<ADM2560::Pinmap::D11> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR1AL = cmd & 0xFF;
    OCR1AH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR1A = (1 << COM1A1) | (1 << WGM10); // Mode PWM, COMB
    TCCR1B = (1 << CS12); // prescaler 256
    DDRB = (1<<5);
    _cmd = 800;
    setValue(800);
  }
};


template <>
class ServoTester<ADM2560::Pinmap::D12> : public GenericServoTester {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR1BL = cmd & 0xFF;
    OCR1BH = (cmd >> 8) & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  ServoTester(void) {
    TCCR1A |= (1 << COM1B1);
    DDRB |= (1<<6);
    _cmd = 800;
    setValue(800);
  }
};

#endif//SERVO_TESTER_HPP
