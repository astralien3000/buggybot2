#include <messages/servo_action.hpp>
#include <messages/servo_config.hpp>

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
#include <cereal/archives/binary.hpp>

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

  sock_pub.send(msg);
}

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

uint8_t find_config_by_label(map<uint8_t, ServoConfig>& configs, string label) {
  for(auto it = configs.begin() ; it != configs.end() ; it++) {
      if(it->second.label == label) {
          return it->first;
        }
    }
  return 0xFF;
}

int main(int argc, char* argv[]) {
  zmq::context_t ctx(5);
  map<uint8_t, ServoConfig> configs;

  load_configs(configs);
  if(configs.empty()) cout << "empty" << endl;

  zmq::socket_t sock_embed_in(ctx, ZMQ_SUB);
  sock_embed_in.connect("ipc://embed.in");
  sock_embed_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_embed_out(ctx, ZMQ_PUB);
  sock_embed_out.connect("ipc://embed.out");

  zmq::socket_t sock_servo_in(ctx, ZMQ_PUB);
  sock_servo_in.bind("ipc://servo.in");

  zmq::socket_t sock_servo_out(ctx, ZMQ_SUB);
  sock_servo_out.bind("ipc://servo.out");
  sock_servo_out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_config(ctx, ZMQ_REP);
  sock_config.bind("ipc://servo-mapper.config");

  {
    int hwm = 2;
    sock_embed_in.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
    sock_embed_out.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
    sock_servo_in.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
    sock_servo_out.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  }

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

            HardwareServoAction hsa;

            {
              cereal::BinaryInputArchive ar(ss);
              ar(hsa);
            }

            if(!configs.count(hsa.id)) {
                configs[hsa.id] = ServoConfig();
                configs[hsa.id].id = hsa.id;
              }

            try {
              ServoConfig& config = configs[hsa.id];
              stringstream oss;

              ServoAction action;
              action.label = config.label;
              action.enable = false;
              action.angle = config.pos2angle(hsa.position);

              {
                cereal::BinaryOutputArchive ar(oss);
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

      {
        zmq::message_t msg;
        if(sock_servo_out.recv(&msg, ZMQ_NOBLOCK)) {
            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());

            vector<HardwareServoAction> hsas;
            vector<ServoAction> sas;

            {
              cereal::BinaryInputArchive ar(ss);
              ar(sas);
            }

            for(auto it = sas.begin() ; it != sas.end() ; it++) {
                ServoAction& sa = *it;
                //ar(sa);

                uint8_t id = find_config_by_label(configs, sa.label);
                if(id != 0xFF) {
                    ServoConfig& config = configs[id];

                    HardwareServoAction hsa;
                    hsa.id = config.id;
                    hsa.enable= sa.enable;
                    hsa.position = config.angle2pos(sa.angle);

                    hsas.push_back(hsa);
                  }
              }
            send(sock_embed_out, hsas);
          }
      }
    }

  return 0;
}

