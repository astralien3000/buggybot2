#ifndef SERVO_HPP
#define SERVO_HPP

#include <device/input.hpp>
#include <device/output.hpp>

template<typename Derived>
class _ServoBase : public Device::Input<u32, _ServoBase<Derived>>, public Device::Output<u32, _ServoBase<Derived>> {};

template<u32 PIN_ID>
class Servo : public _ServoBase<Servo<PIN_ID>> {
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

#endif//SERVO_HPP

#ifndef SERVO_IMPL_HPP
#define SERVO_IMPL_HPP

#include <device/hal/output_digital_pin.hpp>
#include "board/adm2560.hpp"

////////////////////////////////////////////////////////////////
// Public Macros

#define CFG_16B_TIMER(n) \
  TCCR##n##A = (1 << COM##n##A1) | (1 << COM##n##B1) | (1 << COM##n##C1) | (1 << WGM##n##1) | (1 << WGM##n##0); \
  TCCR##n##B = (1 << WGM##n##2) | (1 << CS##n##2) | (0 << CS##n##1) | (0 << CS##n##0); \

#define SET_16B_COM(timer, com, cmd) \
  OCR##timer##com##L = cmd & 0xFF; \
  OCR##timer##com##H = (cmd >> 8) & 0xFF;


////////////////////////////////////////////////////////////////
// Impl

template <>
class Servo<ADM2560::Pinmap::D2> : public _ServoBase<Servo<ADM2560::Pinmap::D2>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(3, B, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(3);
    //    TCCR3A = (1 << COM3B1) | (1 << WGM31) | (1 << WGM30); // Mode PWM 10b, COMB
    //    TCCR3B = (1 << WGM32) | (1 << CS32) | (0 << CS31) | (0 << CS30); // prescaler 256
    DDRE |= (1<<4);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D3> : public _ServoBase<Servo<ADM2560::Pinmap::D3>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(3, C, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(3);
    DDRE |= (1<<5);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D4> : public _ServoBase<Servo<ADM2560::Pinmap::D4>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR0B = cmd & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    TCCR0A = (1 << COM0B1) | (1 << WGM00); // Mode PWM, COMB
    TCCR0B = (1 << CS02); // prescaler 256
    DDRG |= (1<<5);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D5> : public _ServoBase<Servo<ADM2560::Pinmap::D5>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(3, A, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(3);
    DDRE |= (1<<3);
    setValue(0);
  }
};


template <>
class Servo<ADM2560::Pinmap::D6> : public _ServoBase<Servo<ADM2560::Pinmap::D6>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(4, A, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(4);
    DDRH |= (1<<3);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D7> : public _ServoBase<Servo<ADM2560::Pinmap::D7>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(4, B, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(4);
    DDRH |= (1<<4);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D8> : public _ServoBase<Servo<ADM2560::Pinmap::D8>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(4, C, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(4);
    DDRH |= (1<<5);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D9> : public _ServoBase<Servo<ADM2560::Pinmap::D9>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR2B = cmd & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    TCCR2A = (1 << COM2B1) | (1 << WGM21); // Mode PWM, COMB
    TCCR2B = (1 << CS22)|(1 << CS21); // prescaler 256
    DDRH |= (1<<6);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D10> : public _ServoBase<Servo<ADM2560::Pinmap::D10>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    OCR2A = cmd & 0xFF;
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    TCCR2A |= (1 << COM2A1); // Mode PWM, COMA
    DDRB |= (1<<4);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D46> : public _ServoBase<Servo<ADM2560::Pinmap::D46>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(5, A, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(5);
    DDRL |= (1<<3);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D45> : public _ServoBase<Servo<ADM2560::Pinmap::D45>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(5, B, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(5);
    DDRL |= (1<<4);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D44> : public _ServoBase<Servo<ADM2560::Pinmap::D44>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(5, C, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(5);
    DDRL |= (1<<5);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D11> : public _ServoBase<Servo<ADM2560::Pinmap::D11>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(1, A, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(1);
    DDRB |= (1<<5);
    setValue(0);
  }
};


template <>
class Servo<ADM2560::Pinmap::D12> : public _ServoBase<Servo<ADM2560::Pinmap::D12>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(1, B, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(1);
    DDRB |= (1<<6);
    setValue(0);
  }
};

template <>
class Servo<ADM2560::Pinmap::D13> : public _ServoBase<Servo<ADM2560::Pinmap::D13>> {
  u32 _cmd;

public:
  void setValue(u32 cmd) {
    SET_16B_COM(1, C, cmd);
    _cmd = cmd;
  }


  u32 getValue(void) {
    return _cmd;
  }

  Servo(void) {
    CFG_16B_TIMER(1);
    DDRB |= (1<<7);
    setValue(0);
  }
};

////////////////////////////////////////////////////////////////
// UNDEF Public Macros

#undef CFG_16B_TIMER
#undef SET_16B_COM

#endif//SERVO_IMPL_HPP

