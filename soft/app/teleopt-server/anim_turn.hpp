#ifndef ANIM_TURN_HPP
#define ANIM_TURN_HPP

#include "anim_walk.hpp"

#include <map>
using namespace std;

class AnimTurn : public Animation {
  struct timeval t1 = {0,0}, t2 = {0,0};

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

  void get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

    double t_step1_middle = cfg.period / 4.0;
    double t_step2_middle = cfg.period * 3.0 / 4.0;

    double dt_half_step = cfg.period / 4.0;

    double side = (45.0*3.1415/180);
    if(leg.default_y < 0) {
        side = ((180+45.0)*3.1415/180);
      }

    if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
        x = default_ray * cos(side + _way*t2*3.1415/round_divisor);
        y = default_ray * sin(side + _way*t2*3.1415/round_divisor);
      }
    else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
        x = default_ray * cos(side - _way*t2*3.1415/round_divisor);
        y = default_ray * sin(side - _way*t2*3.1415/round_divisor);
      }
    else if(abs(t - cfg.period/2.0) < dt_half_step) {
        x = default_ray * cos(side + _way*3.1415/round_divisor);
        y = default_ray * sin(side + _way*3.1415/round_divisor);
      }
    else if(abs(t - cfg.period/2.0) > dt_half_step) {
        x = default_ray * cos(side - _way*3.1415/round_divisor);
        y = default_ray * sin(side - _way*3.1415/round_divisor);
      }
    else {
        x = default_ray * cos(side);
        y = default_ray * sin(side);
      }

    x += cfg.offset_x;
    y += cfg.offset_y;

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
    double side = (135.0*3.1415/180);
    if(leg.default_y < 0) {
        side = ((180+135.0)*3.1415/180);
      }

    if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
        x = default_ray * cos(side - _way*t2*3.1415/round_divisor);
        y = default_ray * sin(side - _way*t2*3.1415/round_divisor);
      }
    else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
        double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
        x = default_ray * cos(side + _way*t2*3.1415/round_divisor);
        y = default_ray * sin(side + _way*t2*3.1415/round_divisor);
      }
    else if(abs(t - cfg.period/2.0) < dt_half_step) {
        x = default_ray * cos(side - _way*3.1415/round_divisor);
        y = default_ray * sin(side - _way*3.1415/round_divisor);
      }
    else if(abs(t - cfg.period/2.0) > dt_half_step) {
        x = default_ray * cos(side + _way*3.1415/round_divisor);
        y = default_ray * sin(side + _way*3.1415/round_divisor);
      }
    else {
        x = default_ray * cos(side);
        y = default_ray * sin(side);
      }

    x += cfg.offset_x;
    y += cfg.offset_y;

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

#endif//ANIM_TURN_HPP
