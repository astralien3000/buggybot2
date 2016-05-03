#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <device/hal/input_digital_pin.hpp>
#include <device/hal/output_digital_pin.hpp>
#include <device/adc_pin.hpp>
#include <device/servo.hpp>

struct LedSettings : Device::HAL::DefaultOutputDigitalPinSettings {};
struct Led1Settings : LedSettings {
  static constexpr auto& pin = HAL::K3;
};
struct Led2Settings : LedSettings {
  static constexpr auto& pin = HAL::K4;
};
struct Led3Settings : LedSettings {
  static constexpr auto& pin = HAL::K5;
};
struct Led4Settings : LedSettings {
  static constexpr auto& pin = HAL::K6;
};
struct Led5Settings : LedSettings {
  static constexpr auto& pin = HAL::K7;
};

struct RegEnSettings : LedSettings {
  static constexpr auto& pin = HAL::E4;
};


struct InSettings : Device::HAL::DefaultInputDigitalPinSettings {};
#define DEFINE_IN(num, my_pin)  \
  struct In##num##Settings : InSettings { \
  static constexpr auto& pin = HAL:: my_pin; \
  }; \
  Device::HAL::InputDigitalPin<In##num##Settings> in##num;

DEFINE_IN(1, F6);
DEFINE_IN(2, F7);
DEFINE_IN(3, K0);
DEFINE_IN(4, K1);
DEFINE_IN(5, K2);

Device::HAL::OutputDigitalPin<Led1Settings> led1;
Device::HAL::OutputDigitalPin<Led2Settings> led2;
Device::HAL::OutputDigitalPin<Led3Settings> led3;
Device::HAL::OutputDigitalPin<Led4Settings> led4;
Device::HAL::OutputDigitalPin<Led5Settings> led5;

Device::HAL::OutputDigitalPin<RegEnSettings> reg_en;

ADCPin<ADM2560::Pinmap::A0> adc1;
ADCPin<ADM2560::Pinmap::A1> adc2;
ADCPin<ADM2560::Pinmap::A2> adc3;
ADCPin<ADM2560::Pinmap::A3> adc4;

Servo<ADM2560::Pinmap::D5> pwm1;
Servo<ADM2560::Pinmap::D6> pwm2;
Servo<ADM2560::Pinmap::D7> pwm3;
Servo<ADM2560::Pinmap::D8> pwm4;

#endif//DEVICES_HPP
