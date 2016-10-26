#include <iostream>
#include <cmath>

#include <cereal/types/vector.hpp>

#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include <zmq.hpp>

#include <messages/servo_action.hpp>
#include <messages/endpoint_action.hpp>
#include <messages/optoforce_data.hpp>

#include <unistd.h>

using namespace std;

template<typename T>
void send(zmq::socket_t& sock_pub, T& sa) {
  stringstream oss;

  {
    cereal::BinaryOutputArchive ar(oss);
    ar(sa);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg, ZMQ_NOBLOCK);
}

void config_sock(zmq::socket_t& sock) {
  int hwm = 1;
  int linger = 0;
  sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
}

template<typename T>
void debug(string name, T& msg) {
  cereal::JSONOutputArchive ar(cout);
  ar(cereal::make_nvp(name, msg));
}

int main(int, char**) {
  // IO config
  zmq::context_t ctx(6);

  zmq::socket_t sock_servo_in(ctx, ZMQ_PUB);
  sock_servo_in.connect("ipc://debug.servo.in");

  zmq::socket_t sock_servo_out(ctx, ZMQ_SUB);
  sock_servo_out.connect("ipc://debug.servo.out");
  sock_servo_out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_ik_in(ctx, ZMQ_SUB);
  sock_ik_in.connect("ipc://ik.in");
  sock_ik_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_ik_out(ctx, ZMQ_PUB);
  sock_ik_out.connect("ipc://ik.out");

  config_sock(sock_ik_in);
  config_sock(sock_ik_out);
  config_sock(sock_servo_in);
  config_sock(sock_servo_out);

  // WAIT
  sleep(2);
  
  // Test
  const char* lbls[] = {
    "LF0", "LF1", "LF2", 
    "RF0", "RF1", "RF2", 
    "LB0", "LB1", "LB2", 
    "RB0", "RB1", "RB2", 
  };

  const double angles[] = {
    1, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
  };

  ServoAction action;
  action.enable = true;

  for(int i = 0 ; i < 12 ; i++) {
    action.label = lbls[i];
    action.angle = angles[i] * 90;
    send(sock_servo_in, action);
    debug("send", action);
  }

  for(int i = 0 ; i < 4 ; i++) {
    zmq::message_t msg;
    sock_ik_in.recv(&msg);
    std::stringstream ss;
    ss.write((char*)msg.data(), msg.size());
    EndpointAction eas;
    
    cereal::BinaryInputArchive ar(ss);
    ar(eas);
    debug("recv", eas);
  }
  
  return 0;
}
