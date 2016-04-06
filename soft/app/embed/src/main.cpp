#include <hal/uart.hpp>
#include <stream/hal/uart_stream.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

#include <feetech/sc.hpp>

using namespace HAL;

auto& MY_UART = UART0; // Choose the UART
auto& TX = E1;         // Choose the TX pin
auto& RX = E0;         // Choose the RX pin

struct SCSettings : Stream::HAL::DefaultUARTStreamSettings {
  static constexpr auto& uart = ::HAL::UART1;
  static constexpr auto& tx = ::HAL::D3;
  static constexpr auto& rx = ::HAL::D2;

  static constexpr auto baudrate = 1000000;
};

Stream::HAL::UARTStream<SCSettings> scio;
Feetech::SC<decltype(scio)> sc(scio);
u8 max_servo = 0;

Protocol::Parser<2, 128> parser;
u16 i = 0;

int main(int, char**) {
  UART::Settings settings;
  settings.baudrate = 38400;
  settings.parity = UART::Parity::NONE;
  settings.stop_bit = UART::StopBit::ONE_BIT;
  settings.word_size = 8;

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoPosition>([](const void* msg){
      auto pak = *(Protocol::Pack<Protocol::Message, Actuator::ServoPosition>*)msg;
      if(pak.message.payload.enabled) {
          sc.enableTorque(pak.message.payload.id);
          sc.setPosition(pak.message.payload.id, pak.message.payload.position);
        }
      else {
          sc.disableTorque(pak.message.payload.id);
        }
    }));

  UART::init(MY_UART, TX, RX, settings);
  UART::setHandler(MY_UART, UART::Event::RX_COMPLETE, [](){
          char c = UART::getChar(MY_UART);
          parser.parse((u8*)&c, 1);
    });

  ::HDL::sei();

  while(1) {
      if(0 == max_servo) {

          for(u8 i = 1 ; i < 0xfe ; i++) {
              if(sc.ping(i)) {
                  max_servo = i+1;
                }
            }

        }
      else {

          if(sc.ping(1)) {
              sc.setId(1, max_servo);
              max_servo++;
            }

          for(u8 i = 2 ; i < max_servo ; i++) {
              Protocol::Pack<Protocol::Message, Actuator::ServoPosition> pak;
              pak.message.payload.id = i;
              pak.message.payload.enabled = sc.isTorqueEnabled(i);
              pak.message.payload.position = sc.getPosition(i);
              u8* data = Protocol::pack(pak);
              UART::write(MY_UART, data, sizeof(pak));
            }

        }
    }

  return 0;
}
