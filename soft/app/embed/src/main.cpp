#include <hal/uart.hpp>

using namespace HAL;

auto& MY_UART = UART0; // Choose the UART
auto& TX = E1;         // Choose the TX pin
auto& RX = E0;         // Choose the RX pin

u8 c = 'a';

int main(int, char**) {
  UART::Settings settings;
  settings.baudrate = 38400;
  settings.parity = UART::Parity::NONE;
  settings.stop_bit = UART::StopBit::ONE_BIT;
  settings.word_size = 8;

  UART::init(MY_UART, TX, RX, settings);
  UART::setHandler(MY_UART, UART::Event::RX_COMPLETE, [](){
          c = UART::getChar(MY_UART);
    });

  UART::setHandler(MY_UART, UART::Event::TX_COMPLETE, [](){
          UART::putChar(MY_UART, c);
    });

  ::HDL::sei();

  UART::putChar(MY_UART, c);

  while(1) {
    }

  return 0;
}
