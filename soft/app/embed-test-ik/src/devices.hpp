#ifndef MY_DEVICES_HPP
#define MY_DEVICES_HPP

#ifdef AVERSIVE_TOOLCHAIN_AVR

#include <hal/uart.hpp>
#include <stream/hal/uart_stream.hpp>

using namespace HAL;

struct Settings : Stream::HAL::DefaultUARTStreamSettings {
  static constexpr auto& uart = UART0;
  static constexpr auto& tx = E1;
  static constexpr auto& rx = E0;  
};

extern Stream::HAL::UARTStream<Settings> io;
extern Stream::FormattedStreamDecorator<decltype(io)> cout;
static const char* endl = "\n";

Stream::FormattedStreamDecorator<decltype(io)>& operator<<(Stream::FormattedStreamDecorator<decltype(io)>& stream, double val);

#else

#include <iostream>
using namespace std;

#endif


#endif//MY_DEVICES_HPP
