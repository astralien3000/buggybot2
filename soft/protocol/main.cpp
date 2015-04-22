#include "ap.hpp"
#include "ap_parser.hpp"
#include <iostream>

using namespace AP;
using namespace std;

void test_handle(const void* test) {
  const Pack<Message, Actuator::ServoPWM>* pak = (const Pack<Message, Actuator::ServoPWM>*)test;
  cout << "miew ? [" << (int)pak->message.payload.servo.id << "]" << pak->message.payload.pwm << endl;
}

int main(int argc, char* argv[]) {
  AP::Parser<16, 128> parser;

  parser.addHandler(DefaultHandler<Message, Actuator::ServoPWM>(test_handle));

  parser.addHandler(DefaultHandler<PollRequest, Sensor::Bumper>(test_handle));

  Pack<PollRequest, Sensor::Bumper> msg = {0};

  cout << sizeof(msg.message) << endl;
  msg.message.payload.id = 2;
  u8* m = pack(msg);

  parser.parse(m, sizeof(msg));

  cout << "DUMP" << endl;
  for(int i = 0 ; i < sizeof(msg) ; i++) {
    cout << (u32)m[i] << endl;
  }

  return 0;
}
