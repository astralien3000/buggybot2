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
    ar(CEREAL_NVP(label), CEREAL_NVP(enable), CEREAL_NVP(angle));
  }
};

struct ServoAnglePosition {
  double angle = 0;
  uint16_t position = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(angle), CEREAL_NVP(position));
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
    ar(CEREAL_NVP(id), CEREAL_NVP(label));
    ar(CEREAL_NVP(calib1), CEREAL_NVP(calib2));
    ar(CEREAL_NVP(min_angle), CEREAL_NVP(max_angle));
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


void sync_map_id(map<uint8_t, ServoConfig>& configs) {
  for(auto it = configs.begin() ; it != configs.end() ; it++) {
      if(it->first != it->second.id) {
          it->second.id = it->first;
          cout << "invalid id -> changing" << endl;
        }
    }
}

void load_configs(map<uint8_t, ServoConfig>& configs) {
  configs.clear();

  try {
    ifstream ifs("servo-mapper.json", ios_base::in);

    cereal::JSONInputArchive ar(ifs);
    ar(CEREAL_NVP(configs));
    sync_map_id(configs);
  }
  catch(cereal::RapidJSONException e) {
    cout << "load : " << e.what() << endl;
  }
  catch(cereal::Exception e) {
    cout << "load : " << e.what() << endl;
  }
}

void save_configs(map<uint8_t, ServoConfig>& configs) {
  sync_map_id(configs);
  ofstream ofs("servo-mapper.json", ios_base::out);
  cereal::JSONOutputArchive ofar(ofs);
  ofar(CEREAL_NVP(configs));
}

template<typename T>
void answer(zmq::socket_t& sock_config, string action, T data) {
  stringstream oss;

  {
    cereal::JSONOutputArchive ar(oss);
    ar(CEREAL_NVP(action), CEREAL_NVP(data));
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_config.send(msg);
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

  zmq::socket_t sock_config(ctx, ZMQ_REP);
  sock_config.bind("ipc://servo-mapper.config");

  while(1) {

      try {
        zmq::message_t msg;
        if(sock_config.recv(&msg, ZMQ_NOBLOCK)) {
            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());
            cereal::JSONInputArchive ar(ss);

            string action;
            ar(CEREAL_NVP(action));

            if(action == string("getall")) {
                cout << "config : getall" << endl;

                answer(sock_config, action, configs);
              }
            else if(action == string("get")) {
                cout << "config : get" << endl;

                uint16_t id = 0;
                ar(CEREAL_NVP(id));

                if(configs.count(id)) {
                    answer(sock_config, action, configs[id]);
                  }
                else {
                    answer(sock_config, string("error"), string("none"));
                  }
              }
            else if(action == string("set")) {
                cout << "config : set" << endl;

                ServoConfig config;
                ar(CEREAL_NVP(config));
                configs[config.id] = config;

                answer(sock_config, action, string("ok"));
                save_configs(configs);
              }
            else {
                answer(sock_config, string("error"), string(""));
              }
          }
      }
      catch(zmq::error_t e) {
        cout << "config error : " << e.what() << endl;
        answer(sock_config, string("error"), string(e.what()));
      }
      catch(cereal::RapidJSONException e) {
        cout << "config error : " << e.what() << endl;
        answer(sock_config, string("error"), string(e.what()));
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
                bool enabled;
                uint16_t pos;
                ar(id, pos, enabled);

                if(!configs.count(id)) {
                    configs[id] = ServoConfig();
                    configs[id].id = id;
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
                  //cout << "servo[" << (uint16_t)id << "] : " << msg << endl;
                }
              }
          }
      }

    }

  return 0;
}

