#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <zmq.hpp>
#include <map>
using namespace std;

class Animation {
public:
  static zmq::socket_t* sock_ik_out;

public:
  virtual void update(void) {}
};

template<typename T>
void send(zmq::socket_t& sock_pub, T& ea) {
  stringstream oss;

  {
    cereal::BinaryOutputArchive ar(oss);
    ar(ea);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg, ZMQ_NOBLOCK);
}

#endif//ANIMATION_HPP
