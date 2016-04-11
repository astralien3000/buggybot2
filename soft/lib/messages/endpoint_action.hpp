#ifndef LIB_MESSAGES_ENDPOINT_ACTION_HPP
#define LIB_MESSAGES_ENDPOINT_ACTION_HPP

#include <cereal/cereal.hpp>
#include <cereal/types/string.hpp>

struct EndpointAction {
  std::string label = "";
  uint8_t enable = 0;
  double x = 0;
  double y = 0;
  double z = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(label), CEREAL_NVP(enable));
    ar(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z));
  }
};

#endif//LIB_MESSAGES_ENDPOINT_ACTION_HPP
