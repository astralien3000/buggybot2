#include <hal/uart.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

using namespace HAL;

auto& MY_UART = UART0; // Choose the UART
auto& TX = E1;         // Choose the TX pin
auto& RX = E0;         // Choose the RX pin

Protocol::Parser<1, 128> parser;
u16 i = 0;

int main(int, char**) {
  UART::Settings settings;
  settings.baudrate = 38400;
  settings.parity = UART::Parity::NONE;
  settings.stop_bit = UART::StopBit::ONE_BIT;
  settings.word_size = 8;

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoAngle>([](const void* msg){
      auto pak = *(Protocol::Pack<Protocol::Message, Actuator::ServoAngle>*)msg;
      i = pak.message.payload.angle;
    }));

  UART::init(MY_UART, TX, RX, settings);
  UART::setHandler(MY_UART, UART::Event::RX_COMPLETE, [](){
          char c = UART::getChar(MY_UART);
          parser.parse((u8*)&c, 1);
    });

  ::HDL::sei();

  //UART::putChar(MY_UART, c);

  while(1) {
      Protocol::Pack<Protocol::Message, Actuator::ServoAngle> pak;
      pak.message.payload.angle = i++;
      u8* data = Protocol::pack(pak);
      UART::write(MY_UART, data, sizeof(pak));

      for(volatile u32 i = 0 ; i < 0xf ; i++);
    }

  return 0;
}
