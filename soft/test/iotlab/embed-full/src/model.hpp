#ifndef MODEL_HPP
#define MODEL_HPP

#include <stream/riot/uart_stream.hpp>
#include <feetech/sc.hpp>
#include <stdint.h>

struct ServoAnglePosition {
  double angle = 0;
  uint16_t position = 0;

  inline ServoAnglePosition(void) {}
  inline ServoAnglePosition(double angle, uint16_t position)
    : angle(angle), position(position) {}
};

struct ServoConfig {
  ServoAnglePosition calib1;
  ServoAnglePosition calib2;

  inline ServoConfig(void) {}
  inline ServoConfig(ServoAnglePosition calib1, ServoAnglePosition calib2)
    : calib1(calib1), calib2(calib2) {}

  double pos2angle(uint16_t pos) {
    const double p = pos;
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((p2-p1) == 0) {
        return 0;
      }

    return ((p-p1)/(p2-p1))*(a2-a1)+a1;
  }

  uint16_t angle2pos(double angle) {
    const double a = angle;
    const double p1 = calib1.position;
    const double p2 = calib2.position;
    const double a1 = calib1.angle;
    const double a2 = calib2.angle;

    if((a2-a1) == 0) {
        return 0;
      }

    return (uint16_t)(((a-a1)/(a2-a1))*(p2-p1)+p1);
  }
};

struct Convert {
  double offset;
  double multiplier;

  inline Convert(void)
    : offset(0.0), multiplier(1.0) {}
  inline Convert(double offset, double multiplier)
    : offset(offset), multiplier(multiplier) {}

  double ik2angle(double angle) {
    return angle * multiplier + offset;
  }

  double angle2ik(double angle) {
    return angle / multiplier - offset;
  }
};

extern Aversive::Feetech::SC<RIOT::UARTStream<>> sc;

extern const char* labels[12];
extern uint8_t map[12];
extern ServoConfig config[12];
extern Convert convert[12];

#endif//MODEL_HPP
