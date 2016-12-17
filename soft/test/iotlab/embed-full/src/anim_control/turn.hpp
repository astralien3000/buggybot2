#ifndef ANIM_TURN_HPP
#define ANIM_TURN_HPP

#include "walk.hpp"

class AnimTurn {
  double Kp2 = -0.0 / 50.0;
  double Kp1 = -8.0 / 10.0;

  WalkConfig cfg;
  double _way = 1;

public:
  AnimTurn() {
    cfg.step_up_ratio = 0.5;
    cfg.move_ratio = 0.4;
    cfg.offset_y = 0;
  }

  LegConfig lfc = {
    cfg.half_esp_x+cfg.offset_x,
    cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rfc = {
    cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig lbc = {
    -cfg.half_esp_x+cfg.offset_x,
    cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rbc = {
    -cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  void goLeftWay(bool left) {
    if(left) {
        _way = 1;
      }
    else {
        _way = -1;
      }
  }

  const double default_ray = 160;
  const double round_divisor = 32;

  void get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z);
  void get_walk_pos_2(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z);

public:
  void update(LegAction& lf, LegAction& rf, LegAction& rb, LegAction& lb);
};

#endif//ANIM_TURN_HPP
