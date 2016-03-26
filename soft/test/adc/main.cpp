#include <device/stream/uart_stream.hpp>

#include <util/twi.h>
#include <adc_pin.hpp>

UartStream<0> io("");

// ADC8  -> MUX5
// ADC9  -> MUX5 | MUX0
// ADC10 -> MUX5 | MUX1
// ADC11 -> MUX5 | MUX1 | MUX0


int main(int argc, char* argv[]) {
  ADCPin<ADM2560::Pinmap::A8> gp2a;
  ADCPin<ADM2560::Pinmap::A9> gp2b;
  ADCPin<ADM2560::Pinmap::A10> gp2c;
  ADCPin<ADM2560::Pinmap::A11> gp2d;
  
  while(1) {
    io << gp2a.getValue() << " ; ";
    io << gp2b.getValue() << " ; ";
    io << gp2c.getValue() << " ; ";
    io << gp2d.getValue() << "\n";
  }

  return 0;
}
