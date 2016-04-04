#include <iostream>
#include <cmath>
#include <functional>
#include <map>
#include <fstream>

#include <unistd.h>

#include <zmq.hpp>

#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/complex.hpp>

#include <cereal/archives/json.hpp>

using namespace std;

struct ServoAction {
  string label = "";
  bool enable = 0;
  double angle = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(label, enable, angle);
  }
};

struct ServoAnglePosition {
  double angle = 0;
  uint16_t position = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(angle, position);
  }
};

struct ServoConfig {
  uint8_t id = 0;
  string label = "";

  ServoAnglePosition calib1;
  ServoAnglePosition calib2;

  double min_angle = 0;
  double max_angle = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(id, label);
    ar(calib1, calib2);
    ar(min_angle, max_angle);
  }

  double pos2angle(uint16_t pos) {
    const double p = pos;
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((p2-p1) == 0) {
        throw("configuration error !");
      }

    return ((p-p1)/(p2-p1))*(a2-a1)+a1;
  }

  uint16_t angle2pos(double angle) {
    const double a = angle;
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((a2-a1) == 0) {
        throw("configuration error !");
      }

    return (uint16_t)(((a-a1)/(a2-a1))*(p2-p1)+p1);
  }
};

void load_configs(map<uint8_t, ServoConfig>& configs) {
  configs.clear();

  try {
    ifstream ifs("servo-mapper.json", ios_base::in);

    cereal::JSONInputArchive ar(ifs);
    ar(configs);
  }
  catch(cereal::RapidJSONException e) {
    cout << "load : " << e.what() << endl;
  }
}

void save_configs(map<uint8_t, ServoConfig>& configs) {
  ofstream ofs("servo-mapper.json", ios_base::out);
  cereal::JSONOutputArchive ofar(ofs);
  ofar(configs);
}

int main(int argc, char* argv[]) {
  zmq::context_t ctx(5);
  map<uint8_t, ServoConfig> configs;

  load_configs(configs);
  if(configs.empty()) cout << "empty" << endl;

  zmq::socket_t sock_embed_in(ctx, ZMQ_SUB);
  sock_embed_in.connect("ipc://embed.in");
  sock_embed_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  //zmq::socket_t sock_embed_out(ctx, ZMQ_PUB);
  //sock_embed_out.connect("ipc://embed.out");

  zmq::socket_t sock_servo_in(ctx, ZMQ_PUB);
  sock_servo_in.bind("ipc://servo.in");

  //zmq::socket_t sock_servo_out(ctx, ZMQ_SUB);
  //sock_servo_out.bind("ipc://servo.out");

  //zmq::socket_t sock_config(ctx, ZMQ_REP);
  //sock_config.bind("ipc://servo-mapper.config");

  while(1) {

      {
        zmq::message_t msg;
        if(sock_config.recv(&msg, ZMQ_NOBLOCK)) {
            cout << "config request begin" << endl;
          }
      }

      {
        zmq::message_t msg;
        if(sock_embed_in.recv(&msg, ZMQ_NOBLOCK)) {
            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());
            cereal::JSONInputArchive ar(ss);

            string topic;
            ar(topic);

            if(topic == string("pos")) {
                uint8_t id;
                uint16_t pos;
                ar(id, pos);

                if(!configs.count(id)) {
                    configs[id] = ServoConfig();
                  }

                try {
                  ServoConfig& config = configs[id];
                  stringstream oss;

                  ServoAction action;
                  action.label = config.label;
                  action.enable = false;
                  action.angle = config.pos2angle(pos);

                  {
                    cereal::JSONOutputArchive ar(oss);
                    ar(action);
                  }

                  zmq::message_t msg(oss.str().size());
                  oss.str().copy((char*)msg.data(), msg.size());

                  sock_servo_in.send(msg);
                }
                catch(const char* msg) {
                  cout << "servo[" << (uint16_t)id << "] : " << msg << endl;
                }
              }
          }
      }

    }

  return 0;
}

