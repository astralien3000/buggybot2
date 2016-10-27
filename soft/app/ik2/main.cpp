#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <QMatrix4x4>

#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/types/vector.hpp>

#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include <zmq.hpp>

#include "robot_model.hpp"
#include "angles_converter.hpp"

#include <messages/servo_action.hpp>
#include <messages/endpoint_action.hpp>
#include <messages/optoforce_data.hpp>

#include <sys/time.h>

#include <cas/function.hpp>

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

    send(sock_pub, ea);
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

void config_sock(zmq::socket_t& sock) {
  int hwm = 1;
  int linger = 0;
  sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
}

int main(int, char**) {
  // Update config
  map<string, ServoUpdate> servo_update;

  // Model config
  RobotModel bot(0.003, 100, 1);
  AnglesConverter ac(bot);

  ac.setAngleConvertion(RobotModel::Leg::LF, 2, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::RF, 0, 0, -1);
  ac.setAngleConvertion(RobotModel::Leg::RF, 1, 0, -1);
  ac.setAngleConvertion(RobotModel::Leg::RF, 2, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::LB, 0, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::RB, 1, 0, -1);

  ac.setAngle(RobotModel::Leg::LF, 2, 3.1415/2);
  ac.setAngle(RobotModel::Leg::RF, 2, 3.1415/2);
  ac.setAngle(RobotModel::Leg::LB, 2, 3.1415/2);
  ac.setAngle(RobotModel::Leg::RB, 2, 3.1415/2);

  // IO config
  zmq::context_t ctx(6);

  zmq::socket_t sock_servo_in(ctx, ZMQ_SUB);
  sock_servo_in.connect("ipc://servo.in");
  sock_servo_in.bind("ipc://debug.servo.in");
  sock_servo_in.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  zmq::socket_t sock_servo_out(ctx, ZMQ_PUB);
  sock_servo_out.connect("ipc://servo.out");
  sock_servo_out.bind("ipc://debug.servo.out");

  zmq::socket_t sock_ik_in(ctx, ZMQ_PUB);
  sock_ik_in.bind("ipc://ik.in");

  zmq::socket_t sock_ik_out(ctx, ZMQ_SUB);
  sock_ik_out.bind("ipc://ik.out");
  sock_ik_out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  config_sock(sock_ik_in);
  config_sock(sock_ik_out);
  config_sock(sock_servo_in);
  config_sock(sock_servo_out);

  struct timeval t1 = {0,0}, t2 = {0,0};

  while(1) {
    gettimeofday(&t2, NULL);
    if(abs(t2.tv_usec - t1.tv_usec) > 30000) {
      on_update(sock_ik_in, bot, ac, servo_update);
      t1.tv_sec = t2.tv_sec;
      t1.tv_usec = t2.tv_usec;
    }

    try {
      zmq::message_t msg;
      if(sock_servo_in.recv(&msg, ZMQ_NOBLOCK)) {
	//cout << "SERVO_IN" << endl;
	std::stringstream ss;
	ss.write((char*)msg.data(), msg.size());
	cereal::BinaryInputArchive ar(ss);
	ServoAction action;
	ar(action);

	ServoUpdate& up = servo_update[action.label];
	up.updated = true;
	up.value = action.angle;
	up.enabled = action.enable;
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
	//cout << "IK_OUT" << endl;
	std::stringstream ss;
	ss.write((char*)msg.data(), msg.size());
	cereal::BinaryInputArchive ar(ss);

	vector<ServoAction> sas;

	vector<EndpointAction> eas;
	ar(eas);

	//cout << "test \t" << t1.tv_usec << endl;
	for(auto it = eas.begin() ; it != eas.end() ; it++) {

	  EndpointAction& ea = *it;
	  //ar(ea);

	  Matrix<double, 3,1> pos(ea.x, ea.y, ea.z);
	  bot.setEndpoint(lbl2leg(ea.label), pos);
	  //cout << "test \t" << t2.tv_usec << "\t" << ea.label << endl;

	  ServoAction sa;

	  sa.label = ea.label+"0";
	  sa.enable = ea.enable;
	  sa.angle = ac.getAngle(lbl2leg(ea.label), 0);
	  //send(sock_servo_out, sa);
	  sas.push_back(sa);

	  sa.label = ea.label+"1";
	  sa.enable = ea.enable;
	  sa.angle = ac.getAngle(lbl2leg(ea.label), 1);
	  //send(sock_servo_out, sa);
	  sas.push_back(sa);

	  sa.label = ea.label+"2";
	  sa.enable = ea.enable;
	  sa.angle = ac.getAngle(lbl2leg(ea.label), 2);
	  //send(sock_servo_out, sa);
	  sas.push_back(sa);

	}
	//cout << sas.size() << endl;
	send(sock_servo_out, sas);
      }
    }

  }

  return 0;
}
