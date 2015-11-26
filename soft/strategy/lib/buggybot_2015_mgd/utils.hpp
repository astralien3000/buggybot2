#ifndef BUGGYBOT_2015_MGD_UTILS
#define BUGGYBOT_2015_MGD_UTILS

#include <Eigen/Core>
#include <Eigen/Geometry>

static constexpr long double PI = 3.14159265359;
static constexpr long double operator"" _cm (long double val) {
  return val*10;
}

static constexpr long double operator"" _deg (long double val) {
  return val*PI/180.0;
}

static MGD::Matrix scal(double x, double y, double z) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(0,0) = x;
  ret(1,1) = y;
  ret(2,2) = z;
  return ret;
}

static MGD::Matrix trans(double x, double y, double z) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(0,3) = x;
  ret(1,3) = y;
  ret(2,3) = z;
  return ret;
}

static MGD::Matrix rot_x(double a) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(1,1) = cos(a);
  ret(1,2) = -sin(a);
  ret(2,1) = sin(a);
  ret(2,2) = cos(a);
  return ret;
}

static MGD::Matrix rot_y(double a) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(0,0) = cos(a);
  ret(0,2) = -sin(a);
  ret(2,0) = sin(a);
  ret(2,2) = cos(a);
  return ret;
}

static MGD::Matrix rot_z(double a) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(0,0) = cos(a);
  ret(0,1) = -sin(a);
  ret(1,0) = sin(a);
  ret(1,1) = cos(a);
  return ret;
}

#endif//BUGGYBOT_2015_MGD_UTILS
