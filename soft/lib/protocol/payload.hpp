#ifndef PAYLOAD_HPP
#define PAYLOAD_HPP

#include <base/integer.hpp>

#define PACKED __attribute__((packed))

namespace Actuator {

  struct Actuator {
    static constexpr u8 CLS = 2;
  };

  struct ServoAngle : Actuator {
    static constexpr u8 ID = 0;

    u8 id;
    s16 angle;

  } PACKED;

}

#endif//PAYLOAD_HPP
