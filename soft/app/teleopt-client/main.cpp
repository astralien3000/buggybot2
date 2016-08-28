#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <array>

#include <unistd.h>
#include <sys/time.h>

#include <cereal/types/vector.hpp>

#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include <zmq.hpp>

#include <messages/servo_action.hpp>
#include <messages/endpoint_action.hpp>
#include <messages/optoforce_data.hpp>
#include <messages/id_value.hpp>

#include <filter/average.hpp>
#include <filter/limiter.hpp>
#include <filter/integral.hpp>
#include <filter/derivate.hpp>

using namespace std;

int state = 0;
int last_state = 0;

void config_sock(zmq::socket_t& sock) {
  int hwm = 1;
  int linger = 0;
  sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
}

int main(int, char**) {
  // IO config
  zmq::context_t ctx(1);

  zmq::socket_t sock_teleopt_out(ctx, ZMQ_PUB);
  //sock_teleopt_out.connect("ipc://teleopt.out");
  //sock_teleopt_out.connect("tcp://buggybot.local:3333");
  //sock_teleopt_out.connect("tcp://192.168.1.33:3333");
  sock_teleopt_out.connect("tcp://localhost:3333");

  config_sock(sock_teleopt_out);

  while(1) {

      char c = 0;
      read(1, &c, 1);

      switch(c) {
        case ' ':
          state = 0;
          break;
        case 'z':
          state = 1;
          break;
        case 'q':
          state = 2;
          break;
        case 'd':
          state = 3;
          break;
        case 'a':
          state = 4;
          break;
        }

      if(last_state != state) {
          stringstream oss;

          {
            cereal::JSONOutputArchive ar(oss);
            ar(CEREAL_NVP(state));
          }

          zmq::message_t msg(oss.str().size());
          oss.str().copy((char*)msg.data(), msg.size());

          sock_teleopt_out.send(msg, ZMQ_NOBLOCK);
        }

      last_state = state;
    }

  return 0;
}
