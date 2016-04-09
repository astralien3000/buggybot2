#ifndef ROBOT_MODEL_HPP
#define ROBOT_MODEL_HPP

#include <base/matrix.hpp>

class RobotModel {
public:
  enum class Leg { LF, RF, LB, RB };

  RobotModel();

  double getGradientMethodGain(void);
  void setGradientMethodGain(double gain);

  double getAngle(Leg leg, int id);
  void setAngle(Leg leg, int id, double angle);

  Matrix<double, 3,1> getEndpoint(Leg leg);
  void setEndpoint(Leg leg, Matrix<double, 3,1> pos);
};

#endif//ROBOT_MODEL_HPP
