#include "servo_config.hpp"

#include <string.h>
#include <stdlib.h>
#include <base/alloc.hpp>
#include <board/adm2560.hpp>

Servo servos[] = {
#define MACRO_SERVO(name, pin) {new ServoTester<ADM2560::Pinmap::pin>, new ServoConfig},
  #include "servos.hpp"
  #undef MACRO_SERVO
  {NULL, NULL}
};

void init_servos(void) {
  u8 i = 0;
#define MACRO_SERVO(s_name, s_pin) \
  strcpy(servos[i].conf->name, s_name); \
  servos[i].conf->pin = ADM2560::Pinmap::s_pin; \
  servos[i].conf->max.pwm = servos[i].conf->min.pwm = servos[i].conf->default_pwm = 1000; \
  servos[i].conf->max.angle = servos[i].conf->min.angle = 0; \
  i++;
#include "servos.hpp"
#undef MACRO_SERVO
}
