/*
--max_torque
1023
1023
1023
1023
1023
1023
0
0
0
0
0
0
-----------------------
--max lim volt
90
90
90
90
90
90
0
0
0
0
0
0
-----------------------
--min lim volt
45
45
45
45
45
45
0
0
0
0
0
0
-----------------------
--imax
100
100
100
100
100
100
0
0
0
0
0
0
-----------------------
--punch
50
50
50
50
50
50
0
0
0
0
0
0
-----------------------
--lim temp
80
80
80
80
80
80
0
0
0
0
0
0
-----------------------

*/

#include <hal/uart.hpp>
#include <stream/hal/uart_stream.hpp>

#include <device/hal/output_digital_pin.hpp>
#include <device/hal/input_digital_pin.hpp>

#include <container/buffer.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

#include <feetech/sc.hpp>
#include "test.hpp"
#include "sc_switcher.hpp"

#include <avr/wdt.h>

#include <device/adc_pin.hpp>
#include <device/servo.hpp>

using namespace HAL;

struct MySettings : Stream::HAL::DefaultUARTStreamSettings {
  static constexpr auto& uart = UART0;
  static constexpr auto& tx = E1;
  static constexpr auto& rx = E0;
};

Stream::HAL::UARTStream<MySettings> io;
Stream::FormattedStreamDecorator<decltype(io)> cout(io);

SCSwitcher sc;

Feetech::ServoMapStreamDecorator<128, decltype(scio1)> smap1(scio1);
Feetech::ServoMapStreamDecorator<128, decltype(scio2)> smap2(scio2);

void print_u16_reg(const char* title, u8 reg) {
  cout << "--" << title << "\r\n";

  for(int i = 2 ; i < 14 ; i++) {
      u8 buff[2] = {0,0};

      smap1.setServo(i);
      smap1.seek(reg);
      smap1.read(buff, 2);

      u16 val = buff[1] + buff[0]*256;
      cout << val << "\r\n";
    }

  cout << "-----------------------" << "\r\n";
}

void print_u8_reg(const char* title, u8 reg) {
  cout << "--" << title << "\r\n";

  for(int i = 2 ; i < 14 ; i++) {
      smap1.setServo(i);
      smap1.seek(reg);
      u8 c = smap1.getChar();
      cout << c << "\r\n";
    }

  cout << "-----------------------" << "\r\n";
}

template<typename SMap>
void _write_u8(SMap& smap, u8 reg, u8 val) {
  for(int i = 2 ; i < 14 ; i++) {
      smap.setServo(i);

      smap.seek(Feetech::Protocol::P_LOCK);
      smap.putChar(0);

      smap.seek(reg);
      smap.putChar(val);

      smap.seek(Feetech::Protocol::P_LOCK);
      smap.putChar(1);
    }
}

void write_u8(u8 reg, u8 val) {
  _write_u8(smap1, reg, val);
  _write_u8(smap2, reg, val);
}

using namespace Feetech::Protocol;

u8 LOW(u16 val) {
  return val / 256;
}

u8 HIGH(u16 val) {
  return val % 256;
}

struct LedSettings : Device::HAL::DefaultOutputDigitalPinSettings {};
struct Led1Settings : LedSettings {
  static constexpr auto& pin = HAL::K3;
};
struct Led2Settings : LedSettings {
  static constexpr auto& pin = HAL::K4;
};
struct Led3Settings : LedSettings {
  static constexpr auto& pin = HAL::K5;
};
struct Led4Settings : LedSettings {
  static constexpr auto& pin = HAL::K6;
};
struct Led5Settings : LedSettings {
  static constexpr auto& pin = HAL::K7;
};

struct InSettings : Device::HAL::DefaultInputDigitalPinSettings {};
#define DEFINE_IN(num, my_pin)  \
  struct In##num##Settings : InSettings { \
  static constexpr auto& pin = HAL:: my_pin; \
  }; \
  Device::HAL::InputDigitalPin<In##num##Settings> in##num;

DEFINE_IN(1, F6);
DEFINE_IN(2, F7);
DEFINE_IN(3, K0);
DEFINE_IN(4, K1);
DEFINE_IN(5, K2);

Device::HAL::OutputDigitalPin<Led1Settings> led1;
Device::HAL::OutputDigitalPin<Led2Settings> led2;
Device::HAL::OutputDigitalPin<Led3Settings> led3;
Device::HAL::OutputDigitalPin<Led4Settings> led4;
Device::HAL::OutputDigitalPin<Led5Settings> led5;

ADCPin<ADM2560::Pinmap::A0> adc1;

Servo<ADM2560::Pinmap::D5> servo1;
Servo<ADM2560::Pinmap::D6> servo2;
Servo<ADM2560::Pinmap::D7> servo3;
Servo<ADM2560::Pinmap::D8> servo4;

int main(int, char**) {

//  PORTF |= 1<<6;
//  PORTF |= 1<<7;
//  PORTK |= 1<<0;
//  PORTK |= 1<<1;
//  PORTK |= 1<<2;

#if 0
  while(1) {
      cout << in1.getValue() << "\t";
      cout << in2.getValue() << "\t";
      cout << in3.getValue() << "\t";
      cout << in4.getValue() << "\t";
      cout << in5.getValue() << "\t";
      cout << "\n\r";
    }
#endif

#define MIN 50
#define MAX 150

#if 1
  u8 val = 0;
  while(1) {
      cout << "Num ?\n\r";
      val = cout.getChar();
      if(val == '1') {
          servo1.setValue(MAX);
        }
      else if(val == '0') {
          servo1.setValue(MIN);
        }
    }
#endif

#if 0
  while(1) {
      for(int i = MIN ; i < MAX ; i++) {
          servo1.setValue(i);
          for(volatile u32 i = 0 ; i < 0x2fff ; i++);
        }
      for(int i = MAX ; i > MIN ; i--) {
          servo1.setValue(i);
          for(volatile u32 i = 0 ; i < 0x2fff ; i++);
        }
    }
#endif

#if 0
  while(1) {
      cout << adc1.getValue() << "\n\r";
    }
#endif

#if 0
  while(1) {
      for(volatile u32 i = 0 ; i < 0xffff ; i++);
      led1.setValue(false);
      led2.setValue(false);
      led3.setValue(false);
      led4.setValue(false);
      led5.setValue(false);
      for(volatile u32 i = 0 ; i < 0xffff ; i++);
      led1.setValue(true);
      led2.setValue(true);
      led3.setValue(true);
      led4.setValue(true);
      led5.setValue(true);
    }
#endif

#if 0
  write_u8(P_MAX_TORQUE_L, LOW(1023));
  write_u8(P_MAX_TORQUE_H, HIGH(1023));
  write_u8(P_IMAX_L, LOW(100));
  write_u8(P_IMAX_H, HIGH(100));

  write_u8(P_PUNCH_L, LOW(50));
  write_u8(P_PUNCH_H, HIGH(50));
#endif

#if 0
  print_u16_reg("max_torque", Feetech::Protocol::P_MAX_TORQUE);
  print_u8_reg("max lim volt", Feetech::Protocol::P_MAX_LIMIT_VOLTAGE);
  print_u8_reg("min lim volt", Feetech::Protocol::P_MIN_LIMIT_VOLTAGE);
  print_u16_reg("imax", Feetech::Protocol::P_IMAX);
  print_u16_reg("punch", Feetech::Protocol::P_PUNCH);
  print_u8_reg("lim temp", Feetech::Protocol::P_LIMIT_TEMPERATURE);
#endif
  return 0;
}
