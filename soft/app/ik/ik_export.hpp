namespace ik_export {
namespace armatures {
struct robot_armature {
static constexpr bool VARIABLE = false;
struct origin {
static constexpr bool VARIABLE = false;
using parent = void;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_front {
static constexpr bool VARIABLE = false;
using parent = origin;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_lf {
static constexpr bool VARIABLE = false;
using parent = spine_front;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-993,1024>,CAS::General<double, double>::Const::Rational<-248,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<9>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-248,1024>,CAS::General<double, double>::Const::Rational<993,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_shoulder_lf {
static constexpr bool VARIABLE = false;
using parent = spine_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Rational<284,1024>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-284,1024>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_arm_lf {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Rational<885,1024>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-885,1024>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_forearm_lf {
static constexpr bool VARIABLE = false;
using parent = joint_arm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_rf {
static constexpr bool VARIABLE = false;
using parent = spine_front;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<993,1024>,CAS::General<double, double>::Const::Rational<-248,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<9>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-248,1024>,CAS::General<double, double>::Const::Rational<-993,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_shoulder_rf {
static constexpr bool VARIABLE = false;
using parent = spine_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Rational<-284,1024>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<284,1024>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_arm_rf {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Rational<-885,1024>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<885,1024>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_forearm_rf {
static constexpr bool VARIABLE = false;
using parent = joint_arm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_back {
static constexpr bool VARIABLE = false;
using parent = origin;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_lb {
static constexpr bool VARIABLE = false;
using parent = spine_back;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<248,1024>,CAS::General<double, double>::Const::Rational<-993,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<9>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<993,1024>,CAS::General<double, double>::Const::Rational<248,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_shoulder_lb {
static constexpr bool VARIABLE = false;
using parent = spine_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Rational<284,1024>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-284,1024>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_arm_lb {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Rational<885,1024>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-885,1024>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_forearm_lb {
static constexpr bool VARIABLE = false;
using parent = joint_arm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_rb {
static constexpr bool VARIABLE = false;
using parent = spine_back;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<248,1024>,CAS::General<double, double>::Const::Rational<993,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<9>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-993,1024>,CAS::General<double, double>::Const::Rational<248,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_shoulder_rb {
static constexpr bool VARIABLE = false;
using parent = spine_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Rational<-284,1024>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<284,1024>,CAS::General<double, double>::Const::Rational<983,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_arm_rb {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Rational<-885,1024>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<885,1024>,CAS::General<double, double>::Const::Rational<514,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct joint_forearm_rb {
static constexpr bool VARIABLE = false;
using parent = joint_arm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
};
}
namespace objects {
struct Camera {
static constexpr bool VARIABLE = false;
using parent = void;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<702,1024>,CAS::General<double, double>::Const::Rational<-324,1024>,CAS::General<double, double>::Const::Rational<670,1024>,CAS::General<double, double>::Const::Rational<7660,1024>,CAS::General<double, double>::Const::Rational<745,1024>,CAS::General<double, double>::Const::Rational<319,1024>,CAS::General<double, double>::Const::Rational<-625,1024>,CAS::General<double, double>::Const::Rational<-6663,1024>,CAS::General<double, double>::Const::Rational<-11,1024>,CAS::General<double, double>::Const::Rational<916,1024>,CAS::General<double, double>::Const::Rational<455,1024>,CAS::General<double, double>::Const::Rational<5471,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct Lamp {
static constexpr bool VARIABLE = false;
using parent = void;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-297,1024>,CAS::General<double, double>::Const::Rational<-789,1024>,CAS::General<double, double>::Const::Rational<579,1024>,CAS::General<double, double>::Const::Rational<4174,1024>,CAS::General<double, double>::Const::Rational<978,1024>,CAS::General<double, double>::Const::Rational<-204,1024>,CAS::General<double, double>::Const::Rational<223,1024>,CAS::General<double, double>::Const::Rational<1029,1024>,CAS::General<double, double>::Const::Rational<-56,1024>,CAS::General<double, double>::Const::Rational<619,1024>,CAS::General<double, double>::Const::Rational<813,1024>,CAS::General<double, double>::Const::Rational<6045,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct robot_armature {
static constexpr bool VARIABLE = false;
using parent = void;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<10>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<10>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<10>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
struct bones {
struct origin : public armatures::robot_armature::origin {
static constexpr bool VARIABLE = false;
using parent = robot_armature;
using last = origin;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<6>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct spine_front : public armatures::robot_armature::spine_front {
static constexpr bool VARIABLE = false;
using parent = origin::last;
using last = spine_front;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<9>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct spine_lf : public armatures::robot_armature::spine_lf {
static constexpr bool VARIABLE = false;
using parent = spine_front::last;
using last = spine_lf;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_shoulder_lf : public armatures::robot_armature::joint_shoulder_lf {
static constexpr bool VARIABLE = false;
using parent = spine_lf::last;
struct ry {
static constexpr bool VARIABLE = true;
using parent = joint_shoulder_lf;
using matrix = CAS::General<double, double>::Space3D::RotationY;
};
using last = ry;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_arm_lf : public armatures::robot_armature::joint_arm_lf {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_lf::last;
struct rx {
static constexpr bool VARIABLE = true;
using parent = joint_arm_lf;
using matrix = CAS::General<double, double>::Space3D::RotationX;
};
using last = rx;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_forearm_lf : public armatures::robot_armature::joint_forearm_lf {
static constexpr bool VARIABLE = false;
using parent = joint_arm_lf::last;
struct rz {
static constexpr bool VARIABLE = true;
using parent = joint_forearm_lf;
using matrix = CAS::General<double, double>::Space3D::RotationZ;
};
using last = rz;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<9113,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct spine_rf : public armatures::robot_armature::spine_rf {
static constexpr bool VARIABLE = false;
using parent = spine_front::last;
using last = spine_rf;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_shoulder_rf : public armatures::robot_armature::joint_shoulder_rf {
static constexpr bool VARIABLE = false;
using parent = spine_rf::last;
struct ry {
static constexpr bool VARIABLE = true;
using parent = joint_shoulder_rf;
using matrix = CAS::General<double, double>::Space3D::RotationY;
};
using last = ry;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_arm_rf : public armatures::robot_armature::joint_arm_rf {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_rf::last;
struct rx {
static constexpr bool VARIABLE = true;
using parent = joint_arm_rf;
using matrix = CAS::General<double, double>::Space3D::RotationX;
};
using last = rx;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_forearm_rf : public armatures::robot_armature::joint_forearm_rf {
static constexpr bool VARIABLE = false;
using parent = joint_arm_rf::last;
struct rz {
static constexpr bool VARIABLE = true;
using parent = joint_forearm_rf;
using matrix = CAS::General<double, double>::Space3D::RotationZ;
};
using last = rz;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<9113,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct spine_back : public armatures::robot_armature::spine_back {
static constexpr bool VARIABLE = false;
using parent = origin::last;
using last = spine_back;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<9>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct spine_lb : public armatures::robot_armature::spine_lb {
static constexpr bool VARIABLE = false;
using parent = spine_back::last;
using last = spine_lb;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_shoulder_lb : public armatures::robot_armature::joint_shoulder_lb {
static constexpr bool VARIABLE = false;
using parent = spine_lb::last;
struct ry {
static constexpr bool VARIABLE = true;
using parent = joint_shoulder_lb;
using matrix = CAS::General<double, double>::Space3D::RotationY;
};
using last = ry;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_arm_lb : public armatures::robot_armature::joint_arm_lb {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_lb::last;
struct rx {
static constexpr bool VARIABLE = true;
using parent = joint_arm_lb;
using matrix = CAS::General<double, double>::Space3D::RotationX;
};
using last = rx;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<7167,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_forearm_lb : public armatures::robot_armature::joint_forearm_lb {
static constexpr bool VARIABLE = false;
using parent = joint_arm_lb::last;
struct rz {
static constexpr bool VARIABLE = true;
using parent = joint_forearm_lb;
using matrix = CAS::General<double, double>::Space3D::RotationZ;
};
using last = rz;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<9113,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct spine_rb : public armatures::robot_armature::spine_rb {
static constexpr bool VARIABLE = false;
using parent = spine_back::last;
using last = spine_rb;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1406,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_shoulder_rb : public armatures::robot_armature::joint_shoulder_rb {
static constexpr bool VARIABLE = false;
using parent = spine_rb::last;
struct ry {
static constexpr bool VARIABLE = true;
using parent = joint_shoulder_rb;
using matrix = CAS::General<double, double>::Space3D::RotationY;
};
using last = ry;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8695,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_arm_rb : public armatures::robot_armature::joint_arm_rb {
static constexpr bool VARIABLE = false;
using parent = joint_shoulder_rb::last;
struct rx {
static constexpr bool VARIABLE = true;
using parent = joint_arm_rb;
using matrix = CAS::General<double, double>::Space3D::RotationX;
};
using last = rx;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<7>,CAS::General<double, double>::Const::Integer<0>>;
};
};
struct joint_forearm_rb : public armatures::robot_armature::joint_forearm_rb {
static constexpr bool VARIABLE = false;
using parent = joint_arm_rb::last;
struct rz {
static constexpr bool VARIABLE = true;
using parent = joint_forearm_rb;
using matrix = CAS::General<double, double>::Space3D::RotationZ;
};
using last = rz;
struct endpoint {
static constexpr bool VARIABLE = false;
using parent = last;
using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<9113,1024>,CAS::General<double, double>::Const::Integer<0>>;
};
};
};
};
struct servo_arm1_lb {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_arm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-6160,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Rational<-3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm1_lf {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_arm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-6160,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Rational<-3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm1_rb {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_arm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-6160,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Rational<3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm1_rf {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_arm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-6160,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Rational<3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm2_lb {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-50>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm2_lf {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-50>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm2_rb {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-50>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_arm2_rf {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-50>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_handle_lb {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_shoulder_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-779,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Rational<10,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_handle_lf {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_shoulder_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-779,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Rational<10,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_handle_rb {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_shoulder_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-779,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Rational<-10,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_handle_rf {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_shoulder_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-779,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Rational<-10,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe1_lb {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<24063,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe1_lf {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-24064,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe1_rb {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-24064,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe1_rf {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<24064,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe2_lb {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-24064,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe2_lf {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<24063,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe2_rb {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<24064,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_axe2_rf {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-24064,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7680,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_lb {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_lf {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<-20479,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_rb {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm1_rf {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm2_lb {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm2_lf {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm2_rb {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct arm2_rf {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<-20>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm1_lb {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<2>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm1_lf {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<2>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm1_rb {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<2047,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm1_rf {
static constexpr bool VARIABLE = false;
using parent = servo_arm1_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<2>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm2_lb {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<2>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm2_lf {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<2>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm2_rb {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<2047,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct fix_arm2_rf {
static constexpr bool VARIABLE = false;
using parent = servo_arm2_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<2047,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_lb {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_forearm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-3293,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Rational<-3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_lf {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_forearm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-3293,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Rational<-3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_rb {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_forearm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-3293,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-102,1024>,CAS::General<double, double>::Const::Rational<3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_rf {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::joint_forearm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-3293,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Rational<3,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct robot {
static constexpr bool VARIABLE = false;
using parent = armatures::robot_armature::origin;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<102,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_axe_lb {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<19968,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_axe_lf {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<19968,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_axe_rb {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<19968,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_axe_rf {
static constexpr bool VARIABLE = false;
using parent = shoulder_handle_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<19968,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine {
static constexpr bool VARIABLE = false;
using parent = robot;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_back {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82432,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<1371,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct spine_front {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82432,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<1371,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct foot_lb {
static constexpr bool VARIABLE = false;
using parent = forearm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<32767,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct foot_lf {
static constexpr bool VARIABLE = false;
using parent = forearm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<32767,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct foot_rb {
static constexpr bool VARIABLE = false;
using parent = forearm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<32767,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct foot_rf {
static constexpr bool VARIABLE = false;
using parent = forearm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<32767,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe1_lb {
static constexpr bool VARIABLE = false;
using parent = forearm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-58367,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-24063,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe1_lf {
static constexpr bool VARIABLE = false;
using parent = forearm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-58367,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<24063,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe1_rb {
static constexpr bool VARIABLE = false;
using parent = forearm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-57>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<24063,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe1_rf {
static constexpr bool VARIABLE = false;
using parent = forearm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-57>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-24063,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe2_lb {
static constexpr bool VARIABLE = false;
using parent = forearm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-57>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<24063,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe2_lf {
static constexpr bool VARIABLE = false;
using parent = forearm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-58367,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-24064,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe2_rb {
static constexpr bool VARIABLE = false;
using parent = forearm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-57>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-24064,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_axe2_rf {
static constexpr bool VARIABLE = false;
using parent = forearm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<724,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-57>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<24063,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_handle_lb {
static constexpr bool VARIABLE = false;
using parent = forearm_lb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-50688,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_handle_lf {
static constexpr bool VARIABLE = false;
using parent = forearm_lf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-50688,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_handle_rb {
static constexpr bool VARIABLE = false;
using parent = forearm_rb;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-50688,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct forearm_handle_rf {
static constexpr bool VARIABLE = false;
using parent = forearm_rf;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-50688,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct power_battery_base {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<-45>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct rasp_base {
static constexpr bool VARIABLE = false;
using parent = power_battery_base;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-23040,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<17070,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_shoulder_lb {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<512,1024>,CAS::General<double, double>::Const::Rational<41575,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82431,1024>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Rational<-19675,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_shoulder_lf {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Rational<41575,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82432,1024>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Rational<-19675,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_shoulder_rb {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<511,1024>,CAS::General<double, double>::Const::Rational<-41575,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82432,1024>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Rational<-19675,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct servo_shoulder_rf {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Rational<-41575,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82431,1024>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Rational<-19675,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_bottom_lb {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<512,1024>,CAS::General<double, double>::Const::Rational<34919,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82431,1024>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Rational<-31204,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_bottom_lf {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Rational<34919,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82432,1024>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Rational<-31204,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_bottom_rb {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<511,1024>,CAS::General<double, double>::Const::Rational<-34919,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82432,1024>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Rational<-31204,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_bottom_rf {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Rational<-34919,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82431,1024>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Rational<-31204,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_top_lb {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<512,1024>,CAS::General<double, double>::Const::Rational<48231,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82431,1024>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Rational<-8147,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_top_lf {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Rational<48231,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82432,1024>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Rational<-8147,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_top_rb {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<511,1024>,CAS::General<double, double>::Const::Rational<-48231,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82432,1024>,CAS::General<double, double>::Const::Rational<-511,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Rational<-8147,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct shoulder_base_top_rf {
static constexpr bool VARIABLE = false;
using parent = spine;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-886,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Rational<-48231,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-82431,1024>,CAS::General<double, double>::Const::Rational<-512,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<886,1024>,CAS::General<double, double>::Const::Rational<-8147,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct adm_base {
static constexpr bool VARIABLE = false;
using parent = power_battery_base;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<23039,1024>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<17070,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct power_battery {
static constexpr bool VARIABLE = false;
using parent = power_battery_base;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1280,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct rasp {
static constexpr bool VARIABLE = false;
using parent = rasp_base;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-6881,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<378,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<4>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
struct adm {
static constexpr bool VARIABLE = false;
using parent = adm_base;
using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<4>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
};
}
}
