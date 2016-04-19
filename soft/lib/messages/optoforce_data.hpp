#ifndef LIB_MESSAGES_OPTOFORCE_DATA_HPP
#define LIB_MESSAGES_OPTOFORCE_DATA_HPP

#include <cereal/cereal.hpp>
#include <cereal/types/string.hpp>

struct OptoforceData {
  std::string label = "";
  double x = 0;
  double y = 0;
  double z = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(label));
    ar(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z));
  }
};

#endif//LIB_MESSAGES_OPTOFORCE_DATA_HPP
