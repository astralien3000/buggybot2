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

#include "robot_state.hpp"

#include "anim_walk.hpp"
#include "anim_stand.hpp"
#include "anim_turn.hpp"

#include "anim_walk3.hpp"

#include "anim_door.hpp"

using namespace std;

zmq::socket_t* Animation::sock_ik_out = 0;


void config_sock(zmq::socket_t& sock) {
  int hwm = 1;
  int linger = 0;
  sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
}

#define GP2_MIN 280
#define GP2_MAX 320
bool detect_helper(bool prev, uint32_t cur) {
  if(prev) {
      if(cur < GP2_MIN) return false;
      else return true;
    }
  else {
      if(cur > GP2_MAX) return true;
      else return false;
    }
}

bool detect(uint32_t left, uint32_t right) {
  static bool prev_left = false;
  static bool prev_right = false;


  prev_left = detect_helper(prev_left, left);
  prev_right = detect_helper(prev_right, right);

  return prev_left || prev_right;
}

int match(bool tirette) {
  static bool last_tirette = false;
  static struct timeval t1 = {0,0};
  static struct timeval t2 = {0,0};

  int ret = false;

  if(!tirette) {
      if(last_tirette == true) {
          gettimeofday(&t1, NULL);
        }

      gettimeofday(&t2, NULL);


      const uint32_t match_time = 90;
      const uint32_t door_time = 7;

      int32_t time = t2.tv_sec - t1.tv_sec;
      //cout << time << endl;
      if(0 <= time && time <= match_time-5-door_time) {
          ret = 1;
        }
      else if(match_time - 5 - door_time <= time && time <= match_time-5) {
          ret = 3;
        }
      else if(match_time < time && time <= match_time+5) {
          ret = 2;
        }
      else {
          ret = 0;
        }
    }
  else {
      ret = -1;
    }
  last_tirette = tirette;
  return ret;
}

void update_servo(zmq::socket_t& sock_pwm_out, int cur_match_state) {

  static struct timeval t1 = {0,0};
  static struct timeval t2 = {0,0};

  gettimeofday(&t2, NULL);
  if(abs(t2.tv_usec - t1.tv_usec) > 1000000/4) {
      t1.tv_sec = t2.tv_sec;
      t1.tv_usec = t2.tv_usec;

      if(cur_match_state == 2) {
          IdValue iv;
          iv.id = 1;
          iv.value = 50;
          send(sock_pwm_out, iv);
        }
      else {
          IdValue iv;
          iv.id = 1;
          iv.value = 100;
          send(sock_pwm_out, iv);
        }
    }
}

int main(int, char**) {
  // IO config
  zmq::context_t ctx(6);

  zmq::socket_t sock_ik_out(ctx, ZMQ_PUB);
  sock_ik_out.connect("ipc://ik.out");

  zmq::socket_t sock_teleopt_out(ctx, ZMQ_SUB);
  sock_teleopt_out.bind("ipc://teleopt.out");
  sock_teleopt_out.bind("tcp://*:3333");
  sock_teleopt_out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  config_sock(sock_ik_out);
  config_sock(sock_teleopt_out);

  Animation::sock_ik_out = &sock_ik_out;

  AnimWalk walk;
  AnimStand stand;
  AnimTurn turn;

  AnimWalk3 walk3;

  AnimDoor door;

  map<string, OptoforceData> opto;

  RobotState robot_state;

  int prev_match_state = 0;
  int cur_match_state = 0;

  int state = 0;

  while(1) {

      switch(state) {
        case 0:
          stand.update();
          break;
        case 1:
          walk.update();
          break;
        case 2:
          turn.goLeftWay(true);
          turn.update();
          break;
        case 3:
          turn.goLeftWay(false);
          turn.update();
          break;
        case 4:
          door.update();
          break;
        }

      try {
        zmq::message_t msg;
        if(sock_teleopt_out.recv(&msg, ZMQ_NOBLOCK)) {
            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());
            cereal::JSONInputArchive ar(ss);

            ar(CEREAL_NVP(state));

            switch(state) {
              case 0:
                cout << "stand" << endl;
                break;
              case 1:
                cout << "walk" << endl;
                break;
              case 2:
                cout << "turn left" << endl;
                break;
              case 3:
                cout << "turn right" << endl;
                break;
              case 4:
                cout << "door" << endl;
                break;
              }

          }
      }
      catch(zmq::error_t e) {
        cout << "config error : " << e.what() << endl;
      }
      catch(cereal::RapidJSONException e) {
        cout << "config error : " << e.what() << endl;
      }

    }

  return 0;
}
