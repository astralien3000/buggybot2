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

#include "devices.hpp"

using namespace HAL;

auto& MY_UART = UART0; // Choose the UART
auto& TX = E1;         // Choose the TX pin
auto& RX = E0;         // Choose the RX pin

u8 max_servo = 0;

Protocol::Parser<2, 128> parser;
u16 i = 0;

SCSwitcher sc;
//auto& sc = sc2;

Container::Buffer<512, char> inbuff;

void flush_inbuff(void) {
  while(!inbuff.isEmpty()) {
      char c = inbuff.head();
      parser.parse((u8*)&c, 1);
      inbuff.dequeue();
    }
}

bool toggle1 = false;
bool toggle2 = false;
bool toggle3 = false;

int main(int, char**) {
  wdt_enable(WDTO_120MS);

  UART::Settings settings;
  settings.baudrate = 57600;
  settings.parity = UART::Parity::NONE;
  settings.stop_bit = UART::StopBit::ONE_BIT;
  settings.word_size = 8;

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoPosition>([](const void* msg){
      led1.setValue(toggle1 = !toggle1);
      wdt_reset();
      auto pak = *(Protocol::Pack<Protocol::Message, Actuator::ServoPosition>*)msg;
      if(pak.message.payload.enabled) {
          sc.enableTorque(pak.message.payload.id);
          wdt_reset();
          sc.setPosition(pak.message.payload.id, pak.message.payload.position);
          wdt_reset();
        }
      else {
          sc.disableTorque(pak.message.payload.id);
          wdt_reset();
        }
    }));

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::PWM>([](const void* msg) {
      led2.setValue(toggle2 = !toggle2);
      wdt_reset();
      auto pak = *(Protocol::Pack<Protocol::Message, Actuator::PWM>*)msg;
      if(pak.message.payload.id == 1) {
          pwm1.setValue(pak.message.payload.value);
        }
      else if(pak.message.payload.id == 2) {
          pwm2.setValue(pak.message.payload.value);
        }
      else if(pak.message.payload.id == 3) {
          pwm3.setValue(pak.message.payload.value);
        }
      else if(pak.message.payload.id == 4) {
          pwm4.setValue(pak.message.payload.value);
        }
    }));

  UART::init(MY_UART, TX, RX, settings);
  UART::setHandler(MY_UART, UART::Event::RX_COMPLETE, [](){
      char c = UART::getChar(MY_UART);
      //parser.parse((u8*)&c, 1);
      if(!inbuff.enqueue(c)) {
          led3.setValue(toggle3 = !toggle3);
          inbuff.flush();
        }
    });

  pwm1.setValue(100);
  pwm2.setValue(100);
  pwm3.setValue(100);
  pwm4.setValue(100);

  {
    Protocol::Pack<Protocol::Message, Sensor::GP2> pak;
    {
      pak.message.payload.id = 0;
      pak.message.payload.value = 0xFFFF;
      u8* data = Protocol::pack(pak);
      UART::write(MY_UART, data, sizeof(pak));
    }
  }

  ::HDL::sei();

  while(1) {
      wdt_reset();
      flush_inbuff();

      // UPDATE servos
      if(0 == max_servo) {

          for(u8 i = 1 ; i < 0xfe ; i++) {
              wdt_reset();
              if(sc.ping(i)) {
                  max_servo = i+1;
                }
            }

        }
      else {

          if(sc.ping(1)) {
              sc.setId(1, max_servo);
              wdt_reset();
              max_servo++;
            }

          for(u8 i = 2 ; i < max_servo ; i++) {
              Protocol::Pack<Protocol::Message, Actuator::ServoPosition> pak;
              pak.message.payload.id = i;
              pak.message.payload.enabled = sc.isTorqueEnabled(i);
              wdt_reset();
              pak.message.payload.position = sc.getPosition(i);
              wdt_reset();
              u8* data = Protocol::pack(pak);
              UART::write(MY_UART, data, sizeof(pak));
              wdt_reset();
            }

        }

      wdt_reset();
      // UPDATE PWM
      {
        Protocol::Pack<Protocol::Message, Actuator::PWM> pak;
        {
          pak.message.payload.id = 1;
          pak.message.payload.value = pwm1.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }

        {
          pak.message.payload.id = 2;
          pak.message.payload.value = pwm2.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }

        {
          pak.message.payload.id = 3;
          pak.message.payload.value = pwm3.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }

        {
          pak.message.payload.id = 4;
          pak.message.payload.value = pwm4.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }
      }


      wdt_reset();
      // UPDATE GP2
      {
        Protocol::Pack<Protocol::Message, Sensor::GP2> pak;
        {
          pak.message.payload.id = 1;
          pak.message.payload.value = adc1.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }

        wdt_reset();
        {
          pak.message.payload.id = 2;
          pak.message.payload.value = adc2.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }

        wdt_reset();
        {
          pak.message.payload.id = 3;
          pak.message.payload.value = adc3.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }

        wdt_reset();
        {
          pak.message.payload.id = 4;
          pak.message.payload.value = adc4.getValue();
          u8* data = Protocol::pack(pak);
          UART::write(MY_UART, data, sizeof(pak));
        }
      }

      wdt_reset();
      // UPDATE Bumpers
      {
        Protocol::Pack<Protocol::Message, Sensor::Bumpers> pak;
        pak.message.payload.in1 = in1.getValue();
        pak.message.payload.in2 = in2.getValue();
        pak.message.payload.in3 = in3.getValue();
        pak.message.payload.in4 = in4.getValue();
        pak.message.payload.in5 = in5.getValue();
        u8* data = Protocol::pack(pak);
        UART::write(MY_UART, data, sizeof(pak));
      }
    }

  return 0;
}
