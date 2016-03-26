#ifndef SERVO_CONFIG_HPP
#define SERVO_CONFIG_HPP

#include "servo_tester.hpp"

struct PWMConfig {
  u32 pwm;
  s32 angle;
};

struct ServoConfig {
  u32 pin;
  char name[32];

  u32 default_pwm;
  PWMConfig max;
  PWMConfig min;
};

struct Servo {
  GenericServoTester* dev;
  ServoConfig* conf;
};

extern Servo servos[];


#endif//SERVO_CONFIG_HPP
