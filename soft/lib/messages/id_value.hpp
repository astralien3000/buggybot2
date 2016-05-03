#ifndef LIB_MESSAGES_ID_VALUE_HPP
#define LIB_MESSAGES_ID_VALUE_HPP

#include <cereal/cereal.hpp>

struct IdValue {
  uint16_t id = 0;
  uint16_t value = 0;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(id), CEREAL_NVP(value));
  }
};

#endif//LIB_MESSAGES_ID_VALUE_HPP
