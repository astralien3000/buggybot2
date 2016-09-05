#ifndef LIB_MESSAGES_SERVO_CONFIG_HPP
#define LIB_MESSAGES_SERVO_CONFIG_HPP

#include <cereal/cereal.hpp>

struct ServoAnglePosition {
  double angle = 0;
  uint16_t position = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(angle), CEREAL_NVP(position));
  }
};

struct ServoConfig {
  uint8_t id = 0;
  std::string label = "";

  ServoAnglePosition calib1;
  ServoAnglePosition calib2;

  double min_angle = 0;
  double max_angle = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(id), CEREAL_NVP(label));
    ar(CEREAL_NVP(calib1), CEREAL_NVP(calib2));
    ar(CEREAL_NVP(min_angle), CEREAL_NVP(max_angle));
  }

  bool ok(void) {
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((p2-p1) == 0) {
      return false;
    }
    if((a2-a1) == 0) {
      return false;
    }
    return true;
  }
  
  double pos2angle(uint16_t pos) {
    const double p = pos;
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((p2-p1) == 0) {
      return 0;
    }

    return ((p-p1)/(p2-p1))*(a2-a1)+a1;
  }

  uint16_t angle2pos(double angle) {
    const double a = angle;
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((a2-a1) == 0) {
      return 0;
    }

    return (uint16_t)(((a-a1)/(a2-a1))*(p2-p1)+p1);
  }
};


#endif//LIB_MESSAGES_SERVO_CONFIG_HPP
