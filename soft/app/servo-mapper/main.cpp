#include <iostream>
#include <cmath>
#include <functional>

#include <unistd.h>

#include <zmq.hpp>

#include <cereal/archives/binary.hpp>

using namespace std;

int main(int argc, char* argv[]) {
  zmq::context_t ctx(1);

  zmq::socket_t sock(ctx, ZMQ_PUB);

  while(1) {

      cout << "Connecting..." << endl;
      try {
        sock.connect("ipc://embed.servo_3.pos.out");

        cout << "Connected !" << endl;
        while(sock.connected()) {
            std::stringstream ss;
            cereal::BinaryOutputArchive ar(ss);
            ar((uint16_t)512);

            zmq::message_t msg(ss.str().size());
            ss.str().copy((char*)msg.data(), msg.size());

            sock.send(msg);
            sleep(1);
          }
      }
      catch(zmq::error_t e) {
        cout << e.what() << endl;
        sleep(5);
      }
    }

  return 0;
}

