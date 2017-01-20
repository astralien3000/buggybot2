#include "model.hpp"

static constexpr double _90deg = 1.57075;

static RIOT::UARTStream<> _sc_uart(1, 1000000);
Aversive::Feetech::SC<RIOT::UARTStream<>> sc(_sc_uart);

const char* labels[12] = {
  "LF0", "LF1", "LF2",
  "RF0", "RF1", "RF2",
  "RB0", "RB1", "RB2",
  "LB0", "LB1", "LB2",
};

uint8_t map[12] = {
  14, // LF0
  3,  // LF1
  4,  // LF2

  5,  // RF0
  6,  // RF1
  10, // RF2

  8,  // RB0
  9,  // RB1
  7,  // RB2

  11, // LB0
  12, // LB1
  13, // LB2
};

ServoConfig config[12] = {
  ServoConfig{ServoAnglePosition{0,486},ServoAnglePosition{_90deg,919}}, // LF0
  ServoConfig{ServoAnglePosition{0,373},ServoAnglePosition{_90deg,853}}, // LF1
  ServoConfig{ServoAnglePosition{0,649},ServoAnglePosition{_90deg,184}}, // LF2

  ServoConfig{ServoAnglePosition{0,507},ServoAnglePosition{_90deg,66}},  // RF0
  ServoConfig{ServoAnglePosition{0,299},ServoAnglePosition{_90deg,796}}, // RF1
  ServoConfig{ServoAnglePosition{0,484},ServoAnglePosition{_90deg,52}},  // RF2

  ServoConfig{ServoAnglePosition{0,493},ServoAnglePosition{_90deg,962}}, // RB0
  ServoConfig{ServoAnglePosition{0,368},ServoAnglePosition{_90deg,815}}, // RB1
  ServoConfig{ServoAnglePosition{0,295},ServoAnglePosition{_90deg,759}}, // RB2

  ServoConfig{ServoAnglePosition{0,556},ServoAnglePosition{_90deg,99}},  // LB0
  ServoConfig{ServoAnglePosition{0,374},ServoAnglePosition{_90deg,823}}, // LB1
  ServoConfig{ServoAnglePosition{0,417},ServoAnglePosition{_90deg,842}}, // LB2
};

Convert convert[12] = {
  Convert{},     // LF0
  Convert{},     // LF1
  Convert{0,-1}, // LF2

  Convert{0,-1}, // RF0
  Convert{0,-1}, // RF1
  Convert{0,-1}, // RF2

  Convert{},     // RB0
  Convert{0,-1}, // RB1
  Convert{},     // RB2

  Convert{0,-1}, // LB0
  Convert{},     // LB1
  Convert{},     // LB2
};

char command;
