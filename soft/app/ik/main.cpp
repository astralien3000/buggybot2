#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/archives/json.hpp>

#include "robot_model.hpp"
#include "angles_converter.hpp"

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


int main(int, char**) {
  RobotModel bot(0.00325, 100, 1);
  AnglesConverter ac(bot);

  ac.setAngleConvertion(RobotModel::Leg::LF, 2, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::RF, 0, 0, -1);
  ac.setAngleConvertion(RobotModel::Leg::RF, 1, 0, -1);
  ac.setAngleConvertion(RobotModel::Leg::RF, 2, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::LB, 0, 0, -1);

  ac.setAngleConvertion(RobotModel::Leg::RB, 1, 0, -1);

  test(bot, ac, RobotModel::Leg::RB, 2, 3.1415/2);
  return 0;
}
