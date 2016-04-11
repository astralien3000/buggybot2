#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <unistd.h>

#include <cereal/archives/json.hpp>

#include <zmq.hpp>

#include <messages/servo_action.hpp>
#include <messages/endpoint_action.hpp>

using namespace std;

template<typename T>
void send(zmq::socket_t& sock_pub, T& ea) {
  stringstream oss;

  {
    cereal::JSONOutputArchive ar(oss);
    ar(ea);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg);
}

int main(int, char**) {
  // IO config
  zmq::context_t ctx(5);

  zmq::socket_t sock_ik_out(ctx, ZMQ_PUB);
  sock_ik_out.connect("ipc://ik.out");

  zmq::socket_t sock_servo_out(ctx, ZMQ_PUB);
  sock_servo_out.connect("ipc://servo.out");

  double a = 0;
  while(1) {
      usleep(50000);

      a += 0.08;
      EndpointAction ea;

      ea.label = "LF";
      ea.enable = true;
      ea.x = 150 + 40*cos(a);
      ea.y = 150 + 40*sin(a);
      ea.z = -120;

      cout << ea.x << " " << ea.y << " " << ea.z << endl;

      send(sock_ik_out, ea);
    }

  return 0;
}
