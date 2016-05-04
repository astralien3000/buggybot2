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

#include "robot_state.hpp"

#include "anim_walk.hpp"
#include "anim_stand.hpp"

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
      const uint32_t walk_time = 15;

      int32_t time = t2.tv_sec - t1.tv_sec;
      //cout << time << endl;
      if(0 <= time && time <= walk_time) {
          ret = 1;
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
  if(abs(t2.tv_usec - t1.tv_usec) > 1000000 / freq * 3) {
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

  zmq::socket_t sock_servo_out(ctx, ZMQ_PUB);
  sock_servo_out.connect("ipc://servo.out");

  zmq::socket_t sock_pwm_out(ctx, ZMQ_PUB);
  sock_pwm_out.connect("ipc://embed.pwm.out");

  zmq::socket_t sock_opto_in(ctx, ZMQ_SUB);
  sock_opto_in.connect("ipc://ik.opto.in");
  sock_opto_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_gp2_in(ctx, ZMQ_SUB);
  sock_gp2_in.connect("ipc://embed.gp2.in");
  sock_gp2_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_bumper_in(ctx, ZMQ_SUB);
  sock_bumper_in.connect("ipc://embed.bumper.in");
  sock_bumper_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  config_sock(sock_ik_out);
  config_sock(sock_servo_out);
  config_sock(sock_pwm_out);
  config_sock(sock_opto_in);
  config_sock(sock_gp2_in);
  config_sock(sock_bumper_in);

  Animation::sock_ik_out = &sock_ik_out;

  AnimWalk walk;
  AnimStand stand;

  map<string, OptoforceData> opto;

  RobotState robot_state;

  int prev_match_state = 0;
  int cur_match_state = 0;

  while(1) {

      cur_match_state = match(robot_state.tirette);
      if(prev_match_state != cur_match_state) {
          if(cur_match_state == -1) {
              cout << "tirette" << endl;
            }
          if(cur_match_state == 0) {
              cout << "none" << endl;
            }
          if(cur_match_state == 1) {
              cout << "match" << endl;
            }
          if(cur_match_state == 2) {
              cout << "funny" << endl;
            }
        }
      prev_match_state = cur_match_state;

      update_servo(sock_pwm_out, cur_match_state);
      if(cur_match_state != 1 ||
         detect(robot_state.left_gp2, robot_state.right_gp2)) {
          stand.update();
        }
      else {
          walk.update();
        }

      {
        zmq::message_t msg;
        if(sock_gp2_in.recv(&msg, ZMQ_NOBLOCK)) {
            IdValue iv;

            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());

            {
              cereal::BinaryInputArchive ar(ss);
              ar(iv);
            }

            //cout << iv.id << " \t" << iv.value << endl;
            if(iv.id == 1) {
                robot_state.right_gp2 = iv.value;
              }
            if(iv.id == 2) {
                robot_state.left_gp2 = iv.value;
              }
          }
      }

      {
        zmq::message_t msg;
        if(sock_bumper_in.recv(&msg, ZMQ_NOBLOCK)) {
            std::vector<bool> bumpers;

            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());

            {
              cereal::BinaryInputArchive ar(ss);
              ar(bumpers);
            }

            robot_state.tirette = (bumpers[4] == false);
            //            for(int i = 0 ; i < bumpers.size() ; i++) {
            //                cout << bumpers[i] << " \t";
            //              }
            //            cout << endl;
          }
      }

      {
        zmq::message_t msg;
        if(sock_opto_in.recv(&msg, ZMQ_NOBLOCK)) {
            vector<OptoforceData> ods;

            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());

            {
              cereal::BinaryInputArchive ar(ss);
              ar(ods);
            }

            for(auto it = ods.begin() ; it != ods.end() ; it++) {
                OptoforceData& od = *it;
                opto[od.label] = od;
              }
          }
      }

    }

  return 0;
}
