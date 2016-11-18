#ifndef ROBOT_MODEL_HPP
#define ROBOT_MODEL_HPP

#include <base/matrix.hpp>

using namespace Aversive::Base;

class RobotModel {
private:
  double _gain;
  int _max_iter;
  double _stop_dist;
  double _angles[12];

public:
  enum class Leg {
    LF = 0,
    RF = 1,
    LB = 2,
    RB = 3,
    NONE = 4
  };

  inline RobotModel(double gain, int max_iter, double stop_dist)
    : _gain(gain), _max_iter(max_iter), _stop_dist(stop_dist) {
  }

  inline double getGradientMethodGain(void) {
    return _gain;
  }

  inline void setGradientMethodGain(double gain) {
    _gain = gain;
  }

  inline int getGradientMethodMaxIterations(void) {
    return _max_iter;
  }

  inline void setGradientMethodMaxIterations(int max) {
    _max_iter = max;
  }

  inline double getGradientMethodStopDistance(void) {
    return _stop_dist;
  }

  inline void setGradientMethodStopDistance(double dist) {
    _stop_dist = dist;
  }

  double getAngle(Leg leg, int id);
  void setAngle(Leg leg, int id, double angle);

  Matrix<double, 3,1> getEndpoint(Leg leg);
  bool setEndpoint(Leg leg, Matrix<double, 3,1> pos);

};

#endif//ROBOT_MODEL_HPP
