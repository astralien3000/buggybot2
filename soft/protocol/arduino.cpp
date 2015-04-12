#include "ap_parser.hpp"

#include <device/stream/uart_stream.hpp>

UartStream<0> io("test");  

void write(u8* buff, u32 size) {
  while(size != 0) {
    io.setValue(*(buff++));
    size--;
  }
}

void read(u8* buff, u32 size) {
  while(size != 0) {
    *(buff++) = io.getValue();
    size--;
  }
}

using namespace AP;

bool ack_predicate(const void* msg) {
  typedef Pack<Message, Protocol::Ack> pack_t;
  auto pak = (pack_t*)msg;
  bool ret = pak->message.header.cls == Protocol::Ack::CLS;
  ret &= pak->message.header.id == Protocol::Ack::ID;
  return ret;
}

void ack_handle(const void* msg) {
  typedef Pack<Message, Protocol::Ack> pack_t;
  auto pak = (pack_t*)msg;

  io << "test\n";
}

int main(int argc, char* argv[]) {
  Parser<1, 128> parser;

  parser.addHandler(Handler(ack_predicate, ack_handle));

  while(1) {
    u8 c = io.getValue();
    parser.parse(&c, 1);
    //io.setValue(c);
  }

  return 0;
}
