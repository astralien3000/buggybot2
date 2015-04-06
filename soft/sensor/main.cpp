#include <device/stream/uart_stream.hpp>

#include <util/twi.h>

UartStream<0> io("");

void error(const char* msg) {
  io << "Error : " << msg << "\n";
  while(1);
}

#define SLA_R (0b0011000 << 1 | 1)
#define REG_ADDR (0x04)

char i2c_read(void) {
  char ret = 0;

  // Send START
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  //// Wait TWINT
  while (!(TWCR & (1<<TWINT)));
  //// Check Status
  if ((TWSR & 0xF8) != TW_START) error("Not in START state !");

  // Send Slave Address (Read)
  TWDR = SLA_R;
  TWCR = (1<<TWINT) | (1<<TWEN);
  //// Wait TWINT
  while (!(TWCR & (1<<TWINT)));
  //// Check status
  if ((TWSR & 0xF8) != TW_MT_SLA_ACK) error("No SLA_ACK");
  
  // Send Register Address
  TWDR = REG_ADDR;
  TWCR = (1<<TWINT) | (1<<TWEN);
  //// Wait TWINT
  while (!(TWCR & (1<<TWINT)));
  //// Check Status
  if ((TWSR & 0xF8) != TW_MT_DATA_ACK) error("No DATA_ACK");
  
  // Read
  while (!(TWCR & (1<<TWINT)));
  ret = TWDR;

  // STOP
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

  return ret;
}

int main(int argc, char* argv[]) {

  PRR0 &= (0 << PRTWI);
  //DDRD = (1<<0) | (1<<1);
  
  while(1) {
    io << (u32)i2c_read() << "\n";
  }

  return 0;
}
