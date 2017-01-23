#ifndef ANIM_STAND_HPP
#define ANIM_STAND_HPP

#include "walk.hpp"

class AnimStand {
  double Kp2 = -0.0 / 50.0;
  double Kp1 = -8.0 / 10.0;

  WalkConfig cfg;

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

public:
  void update(LegAction& lf, LegAction& rf, LegAction& rb, LegAction& lb);
};

#endif//ANIM_STAND_HPP
