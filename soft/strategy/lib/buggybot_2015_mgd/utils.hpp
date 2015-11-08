#include <Eigen/Core>
#include <Eigen/Geometry>

static constexpr long double PI = 3.14159265359;
constexpr long double operator"" _cm (long double val) {
  return val*10;
}

constexpr long double operator"" _deg (long double val) {
  return val*PI/180.0;
}

MGD::Matrix rot_x(double a) {
  using namespace Eigen;
  return Transform<double, 3, Affine>(AngleAxisd(a, Vector3d::UnitX())).matrix();
}

MGD::Matrix scal(double x, double y, double z) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(0,0) = x;
  ret(1,1) = y;
  ret(2,2) = z;
  return ret;
}

MGD::Matrix trans(double x, double y, double z) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(0,3) = x;
  ret(1,3) = y;
  ret(2,3) = z;
  return ret;
}

MGD::Matrix rot_y(double a) {
  using namespace Eigen;
  return Transform<double, 3, Affine>(AngleAxisd(a, Vector3d::UnitY())).matrix();
}

MGD::Matrix rot_z(double a) {
  using namespace Eigen;
  return Transform<double, 3, Affine>(AngleAxisd(a, Vector3d::UnitZ())).matrix();
}
