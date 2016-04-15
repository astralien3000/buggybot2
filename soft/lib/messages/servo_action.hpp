#ifndef LIB_MESSAGES_SERVO_ACTION_HPP
#define LIB_MESSAGES_SERVO_ACTION_HPP

#include <cereal/cereal.hpp>
#include <cereal/types/string.hpp>

struct ServoAction {
  std::string label = "";
  bool enable = false;
  double angle = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(label), CEREAL_NVP(enable), CEREAL_NVP(angle));
  }
};

struct HardwareServoAction {
  uint16_t id = 0;
  bool enable = false;
  uint16_t position = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(id), CEREAL_NVP(enable), CEREAL_NVP(position));
  }
};

#endif//LIB_MESSAGES_SERVO_ACTION_HPP
