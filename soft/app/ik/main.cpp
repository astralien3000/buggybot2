#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/archives/json.hpp>

#include "robot_model.hpp"

using namespace std;

int main(int, char**) {
  RobotModel bot(0.00325, 100, 1);

  //bot.setAngle(RobotModel::Leg::LF, 0, -3.1415/2);
  bot.setEndpoint(RobotModel::Leg::LF, Matrix<double, 3,1>(-100.0, -84.8, -150.0));

  cout << bot.getAngle(RobotModel::Leg::LF, 0) << endl;
  cout << bot.getAngle(RobotModel::Leg::LF, 1) << endl;
  cout << bot.getAngle(RobotModel::Leg::LF, 2) << endl;
  cout << endl;

  auto pos = bot.getEndpoint(RobotModel::Leg::LF);

  cout << pos(0,0) << endl;
  cout << pos(1,0) << endl;
  cout << pos(2,0) << endl;
  return 0;
}
