#include <device/stream/uart_stream.hpp>

#include <util/twi.h>

UartStream<0> io("");

// ADC8  -> MUX5
// ADC9  -> MUX5 | MUX0
// ADC10 -> MUX5 | MUX1
// ADC11 -> MUX5 | MUX1 | MUX0

u16 read_adc0(void) {
  u16 ret = 0;
  ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (0 << MUX0); 

  ADCSRA = (1 << ADEN) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
  ADCSRA |= (1 << ADSC);
  
  while(ADCSRA & (1 << ADSC));

  ret = ADCL;
  ret |= ((u16)ADCH) << 8;

  return ret;
}

u16 read_adc1(void) {
  u16 ret = 0;
  ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (1 << MUX0); 

  ADCSRA = (1 << ADEN) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
  ADCSRA |= (1 << ADSC);
  
  while(ADCSRA & (1 << ADSC));

  ret = ADCL;
  ret |= ((u16)ADCH) << 8;

  return ret;
}

u16 read_adc2(void) {
  u16 ret = 0;
  ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (0 << MUX0); 

  ADCSRA = (1 << ADEN) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
  ADCSRA |= (1 << ADSC);
  
  while(ADCSRA & (1 << ADSC));

  ret = ADCL;
  ret |= ((u16)ADCH) << 8;

  return ret;
}


u16 read_adc3(void) {
  u16 ret = 0;
  ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (1 << MUX0); 

  ADCSRA = (1 << ADEN) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
  ADCSRA |= (1 << ADSC);
  
  while(ADCSRA & (1 << ADSC));

  ret = ADCL;
  ret |= ((u16)ADCH) << 8;

  return ret;
}

int main(int argc, char* argv[]) {
  
  while(1) {
    io << read_adc0() << " ; " << read_adc1() << " ; " << read_adc2() << " ; " << read_adc3() << "\n";
    //io << "TEST\n";
  }

  return 0;
}
