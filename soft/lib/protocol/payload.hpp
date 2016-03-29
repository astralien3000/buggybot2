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

  struct ServoEnableTorque : Actuator {
    static constexpr u8 ID = 1;

    u8 id;
    bool enabled;

  } PACKED;

  struct ServoInfo : Actuator {
    static constexpr u8 ID = 2;

    u8 id;

    bool torque_enabled;
    s16 angle;
    s16 current;
    s16 voltage;
    s16 temperature;

  } PACKED;

}

#endif//PAYLOAD_HPP
