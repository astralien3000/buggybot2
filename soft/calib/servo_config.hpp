#ifndef SERVO_CONFIG_HPP
#define SERVO_CONFIG_HPP

struct PWMConfig {
  u32 pwm;
  u32 angle;
};

struct ServoConfig {
  char name[32];
  u32 pin;

  u32 default_pwm;
  PWMConfig max;
  PWMConfig min;
};

#endif//SERVO_CONFIG_HPP
