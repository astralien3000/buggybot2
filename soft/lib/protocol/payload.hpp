#ifndef PAYLOAD_HPP
#define PAYLOAD_HPP

#include <base/integer.hpp>

#define PACKED __attribute__((packed))

namespace Actuator {

  struct Actuator {
    static constexpr u8 CLS = 2;
  };

  struct ServoPosition : Actuator {
    static constexpr u8 ID = 0;

    u8 id;
    bool enabled;
    s16 position;

  } PACKED;

  struct ServoInfo : Actuator {
    static constexpr u8 ID = 2;

    u8 id;

    bool enabled;
    s16 position;
    s16 current;
    s16 voltage;
    s16 temperature;

  } PACKED;

}

#endif//PAYLOAD_HPP
