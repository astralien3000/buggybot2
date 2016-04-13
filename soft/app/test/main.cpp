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
      double default_x = 100;
      double offset_x = -20;
      double default_y = 100;
      double offset_y = 0;
      double default_z = 180;
      double circle_r = 30;

      a += 0.08;
      EndpointAction ea;

      ea.label = "LF";
      ea.enable = true;
      ea.x = default_x + offset_x + circle_r*cos(a);
      ea.y = default_y + offset_y + circle_r*sin(a);
      ea.z = -default_z;
      send(sock_ik_out, ea);

      ea.label = "RF";
      ea.enable = true;
      ea.x = default_x + offset_x + circle_r*cos(a);
      ea.y = -default_y + offset_y + circle_r*sin(a);
      ea.z = -default_z;
      send(sock_ik_out, ea);

      ea.label = "LB";
      ea.enable = true;
      ea.x = -default_x + offset_x + circle_r*cos(a);
      ea.y = default_y + offset_y + circle_r*sin(a);
      ea.z = -default_z;
      send(sock_ik_out, ea);

      ea.label = "RB";
      ea.enable = true;
      ea.x = -default_x + offset_x + circle_r*cos(a);
      ea.y = -default_y + offset_y + circle_r*sin(a);
      ea.z = -default_z;
      send(sock_ik_out, ea);

      //cout << ea.x << " " << ea.y << " " << ea.z << endl;

    }

  return 0;
}
