#ifndef ANGLES_CONVERTER_HPP
#define ANGLES_CONVERTER_HPP

#include <map>
#include "robot_model.hpp"

class AnglesConverter {

  struct Convert {
    double offset = 0.0;
    double multiplier = 1.0;
  };

  RobotModel& _bot;
  std::map<RobotModel::Leg, std::map<int, Convert>> _data;

public:

  AnglesConverter(RobotModel& bot)
    : _bot(bot) {
  }

  void setAngleConvertion(RobotModel::Leg leg, int id, double offset, double multiplier) {
    Convert& conv = _data[leg][id];
    conv.offset = offset;
    conv.multiplier = multiplier;
  }

  double getAngle(RobotModel::Leg leg, int id) {
    double ret = _bot.getAngle(leg, id);
    Convert& conv = _data[leg][id];
    return ret * conv.multiplier + conv.offset;
  }

  void setAngle(RobotModel::Leg leg, int id, double angle) {
    Convert& conv = _data[leg][id];
    _bot.setAngle(leg, id, angle / conv.multiplier - conv.offset);
  }

};

#endif//ANGLES_CONVERTER_HPP
