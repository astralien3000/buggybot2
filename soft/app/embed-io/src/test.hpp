#ifndef TEST_HPP
#define TEST_HPP

#include <stream/hal/uart_stream.hpp>
#include <feetech/sc.hpp>

struct SCSettings2 : Stream::HAL::DefaultUARTStreamSettings {
  static constexpr auto& uart = ::HAL::UART2;
  static constexpr auto& tx = ::HAL::H1;
  static constexpr auto& rx = ::HAL::H0;

  static constexpr auto baudrate = 1000000;
};

extern Stream::HAL::UARTStream<SCSettings2> scio2;
extern Feetech::SC<decltype(scio2)> sc2;

struct SCSettings : Stream::HAL::DefaultUARTStreamSettings {
  static constexpr auto& uart = ::HAL::UART1;
  static constexpr auto& tx = ::HAL::D3;
  static constexpr auto& rx = ::HAL::D2;

  static constexpr auto baudrate = 1000000;
};

extern Stream::HAL::UARTStream<SCSettings> scio1;
extern Feetech::SC<decltype(scio1)> sc1;

#endif//TEST_HPP
