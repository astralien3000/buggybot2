#ifndef ANIM_WALK_HPP
#define ANIM_WALK_HPP

constexpr double freq = 20; // hz

struct WalkConfig {
  double offset_x = 0;
  double half_esp_x = 120;

  double offset_y = 0;
  double half_esp_y = 90;

  double default_z = -190;
  double delta_z = 10;

  double period = 1;

  double step_up_ratio = 0.5;
  double move_ratio = 0.4;

  double step_size = 40;
};

struct LegConfig {
  double default_x;
  double default_y;
  double default_z;
};

struct LegAction {
  double x;
  double y;
  double z;
};

class AnimWalk {
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


  void get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z);
  void get_walk_pos_2(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z);

public:
  void update(LegAction& lf, LegAction& rf, LegAction& rb, LegAction& lb);
};

#endif//ANIM_WALK_HPP
