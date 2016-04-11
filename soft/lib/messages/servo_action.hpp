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

#endif//LIB_MESSAGES_SERVO_ACTION_HPP
