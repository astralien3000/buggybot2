#ifndef ROBOT_STATE_HPP
#define ROBOT_STATE_HPP

#include <cstdint>

enum Side {
  PURPLE,
  GREEN
};

struct RobotState {
  bool tirette = false;
  Side side = PURPLE;

  uint32_t left_gp2 = 0;
  uint32_t right_gp2 = 0;
};

#endif//ROBOT_STATE_HPP
