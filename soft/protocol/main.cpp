#include "ap.hpp"
#include "ap_parser.hpp"
#include <iostream>

using namespace AP;
using namespace std;

bool test_predicate(const void* test) {
  (void)test;
  return ((const Pack<Message, Actuator::ServoAngle>*)test)->message.header.cls == Actuator::ServoAngle::CLS;
}

void test_handle(const void* test) {
  const Pack<Message, Actuator::ServoAngle>* pak = (const Pack<Message, Actuator::ServoAngle>*)test;
  cout << "miew ? " << pak->message.payload.angle << endl;
}

int main(int argc, char* argv[]) {
  AP::Parser<16, 128> parser;

  parser.addHandler(AP::Handler(test_predicate, test_handle));

  Pack<Message, Actuator::ServoAngle> msg = {0};

  msg.message.payload.angle = 42;
  u8* m = pack(msg);

  parser.parse(m, sizeof(msg)-5);
  parser.parse(m + sizeof(msg) - 5, 5);
  parser.parse(m, sizeof(msg));
  
  parser.parse(m, sizeof(msg)-2);
  
  msg.message.payload.angle = 666;
  m = pack(msg);

  parser.parse(m + sizeof(msg) - 2, 2);

  parser.parse(m, sizeof(msg));

  return 0;
}
