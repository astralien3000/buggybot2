#ifndef ANIM_WALK_HPP
#define ANIM_WALK_HPP

#include "animation.hpp"

#include <map>
using namespace std;

double t = 0;
double freq = 20; // hz

struct WalkConfig {
  double offset_x = -10 - 20;
  double half_esp_x = 120;

  double offset_y = 0;
  double half_esp_y = 120;

  double default_z = -180;
  double delta_z = 40;

  double period = 2;

  double step_up_ratio = 0.25;
  double move_ratio = 0.2;

  double step_size = 40;
};

struct LegConfig {
  double default_x;
  double default_y;
  double default_z;
};

double add_mod(double val, double add, double mod) {
  if(val + add > mod) {
      return val+add-mod;
    }
  return val+add;
}

class AnimWalk : public Animation {
  struct timeval t1 = {0,0}, t2 = {0,0};

  double Kp2 = -0.0 / 50.0;
  double Kp1 = -8.0 / 10.0;

  WalkConfig cfg;

  LegConfig lf = {
    cfg.half_esp_x+cfg.offset_x,
    cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rf = {
    cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig lb = {
    -cfg.half_esp_x+cfg.offset_x,
    cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rb = {
    -cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };


  void get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

    double t_step1_middle = cfg.period / 4.0;
    double t_step2_middle = cfg.period * 3.0 / 4.0;

    double dt_half_step = cfg.period / 4.0;

    y = leg.default_y;

    if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
        x = leg.default_x + t2*cfg.step_size/2.0;
      }
    else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
        x = leg.default_x - t2*cfg.step_size/2.0;
      }
    else if(abs(t - cfg.period/2.0) < dt_half_step) {
        x = leg.default_x + cfg.step_size/2.0;
      }
    else if(abs(t - cfg.period/2.0) > dt_half_step) {
        x = leg.default_x - cfg.step_size/2.0;
      }
    else {
        x = leg.default_x;
      }

    if(abs(t - t_step1_middle) < dt_half_step * cfg.step_up_ratio) {
        z = leg.default_z+cfg.delta_z;
      }
    else if(abs(t - t_step2_middle) < dt_half_step * cfg.step_up_ratio) {
        z = leg.default_z;
      }
    else {
        z = leg.default_z;
      }

  }

  void get_walk_pos_2(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

    double t_step1_middle = cfg.period / 4.0;
    double t_step2_middle = cfg.period * 3.0 / 4.0;

    double dt_half_step = cfg.period / 4.0;

    y = leg.default_y;

    if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
        x = leg.default_x - t2*cfg.step_size/2.0;
      }
    else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
        x = leg.default_x + t2*cfg.step_size/2.0;
      }
    else if(abs(t - cfg.period/2.0) < dt_half_step) {
        x = leg.default_x - cfg.step_size/2.0;
      }
    else if(abs(t - cfg.period/2.0) > dt_half_step) {
        x = leg.default_x + cfg.step_size/2.0;
      }
    else {
        x = leg.default_x;
      }

    if(abs(t - t_step1_middle) < dt_half_step * cfg.step_up_ratio) {
        z = leg.default_z;
      }
    else if(abs(t - t_step2_middle) < dt_half_step * cfg.step_up_ratio) {
        z = leg.default_z+cfg.delta_z;
      }
    else {
        z = leg.default_z;
      }

  }

public:
  virtual void update(void) {
    gettimeofday(&t2, NULL);
    if(abs(t2.tv_usec - t1.tv_usec) > 1000000 / freq) {
        t1.tv_sec = t2.tv_sec;
        t1.tv_usec = t2.tv_usec;

        //t = 7.5;
        t = add_mod(t, 1.0/freq, cfg.period);
        EndpointAction ea;
        vector<EndpointAction> eas;

        ea.label = "LF";
        ea.enable = true;
        get_walk_pos_1(cfg, lf, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "RF";
        ea.enable = true;
        get_walk_pos_2(cfg, rf, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "LB";
        ea.enable = true;
        get_walk_pos_2(cfg, lb, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "RB";
        ea.enable = true;
        get_walk_pos_1(cfg, rb, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        //cout << ea.x << " " << ea.y << " " << ea.z << endl;
        send(*sock_ik_out, eas);
      }
  }
};

#endif//ANIM_WALK_HPP
