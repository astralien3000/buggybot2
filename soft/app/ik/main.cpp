#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/archives/json.hpp>

#include <zmq.hpp>

#include "robot_model.hpp"
#include "angles_converter.hpp"

#include <messages/servo_action.hpp>
#include <messages/endpoint_action.hpp>

using namespace std;

void test(RobotModel& bot, AnglesConverter& ac, RobotModel::Leg leg, int id, double val) {
  ac.setAngle(leg, id, val);
  //bot.setEndpoint(leg, Matrix<double, 3,1>(50.0, 50.0, -150.0));

  cout << ac.getAngle(leg, 0) << endl;
  cout << ac.getAngle(leg, 1) << endl;
  cout << ac.getAngle(leg, 2) << endl;
  cout << endl;

  auto pos = bot.getEndpoint(leg);

  cout << pos(0,0) << endl;
  cout << pos(1,0) << endl;
  cout << pos(2,0) << endl;
}

struct ServoUpdate {
  bool updated;
  bool enabled;
  double value;
};

void send_endpoint_action(zmq::socket_t& sock_pub, EndpointAction& ea) {
  stringstream oss;

  {
    cereal::JSONOutputArchive ar(oss);
    ar(ea);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg);
}

void send_servo_action(zmq::socket_t& sock_pub, ServoAction& sa) {
  stringstream oss;

  {
    cereal::JSONOutputArchive ar(oss);
    ar(sa);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg);
}

void on_update_leg(zmq::socket_t& sock_pub, RobotModel& bot, AnglesConverter& ac, map<string, ServoUpdate>& up, RobotModel::Leg leg, string leg_str) {
  if(up[leg_str+"0"].updated && up[leg_str+"1"].updated && up[leg_str+"2"].updated) {
      EndpointAction ea;
      ea.label = leg_str;
      ea.enable = up[leg_str+"0"].enabled && up[leg_str+"1"].enabled && up[leg_str+"2"].enabled;

      ac.setAngle(leg, 0, up[leg_str+"0"].value);
      ac.setAngle(leg, 1, up[leg_str+"1"].value);
      ac.setAngle(leg, 2, up[leg_str+"2"].value);

      auto pos = bot.getEndpoint(leg);

      ea.x = pos(0,0);
      ea.y = pos(1,0);
      ea.z = pos(2,0);

      send_endpoint_action(sock_pub, ea);
      up[leg_str+"0"].updated = false;
      up[leg_str+"1"].updated = false;
      up[leg_str+"2"].updated = false;
    }
}

void on_update(zmq::socket_t& sock_pub, RobotModel& bot, AnglesConverter& ac, map<string, ServoUpdate>& up) {
  on_update_leg(sock_pub, bot, ac, up, RobotModel::Leg::LF, "LF");
  on_update_leg(sock_pub, bot, ac, up, RobotModel::Leg::RF, "RF");
  on_update_leg(sock_pub, bot, ac, up, RobotModel::Leg::LB, "LB");
  on_update_leg(sock_pub, bot, ac, up, RobotModel::Leg::RB, "RB");
}

RobotModel::Leg lbl2leg(string lbl) {
  if(lbl == "LF") {
      return RobotModel::Leg::LF;
    }
  else if(lbl == "RF") {
      return RobotModel::Leg::RF;
    }
  else if(lbl == "LB") {
      return RobotModel::Leg::LB;
    }
  else if(lbl == "RB") {
      return RobotModel::Leg::RB;
    }
  return RobotModel::Leg::NONE;
}

int main(int, char**) {
  // Update config
  map<string, ServoUpdate> update;

  // Model config
  RobotModel bot(0.00325, 100, 1);
  AnglesConverter ac(bot);

  ac.setAngleConvertion(RobotModel::Leg::LF, 2, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::RF, 0, 0, -1);
  ac.setAngleConvertion(RobotModel::Leg::RF, 1, 0, -1);
  ac.setAngleConvertion(RobotModel::Leg::RF, 2, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::LB, 0, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::RB, 1, 0, -1);

  // IO config
  zmq::context_t ctx(5);

  zmq::socket_t sock_servo_in(ctx, ZMQ_SUB);
  sock_servo_in.connect("ipc://servo.in");
  sock_servo_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_servo_out(ctx, ZMQ_PUB);
  sock_servo_out.connect("ipc://servo.out");

  zmq::socket_t sock_ik_in(ctx, ZMQ_PUB);
  sock_ik_in.bind("ipc://ik.in");

  zmq::socket_t sock_ik_out(ctx, ZMQ_SUB);
  sock_ik_out.bind("ipc://ik.out");
  sock_ik_out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  while(1) {

      try {
        zmq::message_t msg;
        if(sock_servo_in.recv(&msg, ZMQ_NOBLOCK)) {
            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());
            cereal::JSONInputArchive ar(ss);
            ServoAction action;
            ar(action);

            ServoUpdate& up = update[action.label];
            up.updated = true;
            up.value = action.angle;
            up.enabled = action.enable;

            on_update(sock_ik_in, bot, ac, update);
          }
      }
      catch(zmq::error_t e) {
        cout << "zmq::error : " << e.what() << endl;
      }
      catch(cereal::RapidJSONException e) {
        cout << "cereal::error : " << e.what() << endl;
      }

      {
        zmq::message_t msg;
        if(sock_ik_out.recv(&msg, ZMQ_NOBLOCK)) {
            std::stringstream ss;
            ss.write((char*)msg.data(), msg.size());
            cereal::JSONInputArchive ar(ss);
            EndpointAction ea;
            ar(ea);

            Matrix<double, 3,1> pos(ea.x, ea.y, ea.z);
            bot.setEndpoint(lbl2leg(ea.label), pos);

            ServoAction sa;

            sa.label = ea.label+"0";
            sa.enable = ea.enable;
            sa.angle = ac.getAngle(lbl2leg(ea.label), 0);
            send_servo_action(sock_servo_out, sa);

            sa.label = ea.label+"1";
            sa.enable = ea.enable;
            sa.angle = ac.getAngle(lbl2leg(ea.label), 1);
            send_servo_action(sock_servo_out, sa);

            sa.label = ea.label+"2";
            sa.enable = ea.enable;
            sa.angle = ac.getAngle(lbl2leg(ea.label), 2);
            send_servo_action(sock_servo_out, sa);
          }
      }


    }

  return 0;
}
