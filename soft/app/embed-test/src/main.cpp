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

#include <container/buffer.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

#include <feetech/sc.hpp>
#include "test.hpp"
#include "sc_switcher.hpp"

#include <avr/wdt.h>

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

int main(int, char**) {
  //*/
  write_u8(P_MAX_TORQUE_L, LOW(1023));
  write_u8(P_MAX_TORQUE_H, HIGH(1023));
  write_u8(P_IMAX_L, LOW(100));
  write_u8(P_IMAX_H, HIGH(100));

  write_u8(P_PUNCH_L, LOW(50));
  write_u8(P_PUNCH_H, HIGH(50));
  //*/
  print_u16_reg("max_torque", Feetech::Protocol::P_MAX_TORQUE);
  print_u8_reg("max lim volt", Feetech::Protocol::P_MAX_LIMIT_VOLTAGE);
  print_u8_reg("min lim volt", Feetech::Protocol::P_MIN_LIMIT_VOLTAGE);
  print_u16_reg("imax", Feetech::Protocol::P_IMAX);
  print_u16_reg("punch", Feetech::Protocol::P_PUNCH);
  print_u8_reg("lim temp", Feetech::Protocol::P_LIMIT_TEMPERATURE);
  //*/
  return 0;
}
