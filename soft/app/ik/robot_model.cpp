#include "robot_model.hpp"

#include <chain_from_ik_export.hpp>
#include <ik_export.hpp>

template<typename Derivate>
struct Leg {
  static Matrix<double, 3,1>& anglesInstance(void) {
    static Matrix<double, 3,1> ret;
    return ret;
  }
};

struct LF : Leg<LF> {
  using endpoint = ik_export::objects::armature::bones::forearm_left_front::endpoint;
  using Chain = ChainFromIKExport<endpoint>::ChainBuilder::Chain;
};

struct RF : Leg<RF> {
  using endpoint = ik_export::objects::armature::bones::forearm_right_front::endpoint;
  using Chain = ChainFromIKExport<endpoint>::ChainBuilder::Chain;
};

struct LB : Leg<LB> {
  using endpoint = ik_export::objects::armature::bones::forearm_left_back::endpoint;
  using Chain = ChainFromIKExport<endpoint>::ChainBuilder::Chain;
};

struct RB : Leg<RB> {
  using endpoint = ik_export::objects::armature::bones::forearm_right_back::endpoint;
  using Chain = ChainFromIKExport<endpoint>::ChainBuilder::Chain;
};

template<typename Chain>
bool gradient_method(Matrix<double, 4,1> target, Matrix<double, 3, 1>& angles, double gain, uint16_t max_iter, double stop_dist) {
  auto position = Chain::forward(angles);
  uint16_t count = 0;

  while(norm(target-position) > stop_dist && count < max_iter) {
      auto dangles = Chain::inverseStep(target,angles);

      double coef = norm(target-position)*gain;
      angles = angles+dangles*coef;

      position = Chain::forward(angles);
      count++;
    }

  return norm(target-position) <= stop_dist;
}


double RobotModel::getAngle(Leg leg, int id) {
  if(leg == Leg::LF) {
      return LF::anglesInstance()(id, 0);
    }
  else if(leg == Leg::RF) {
      return RF::anglesInstance()(id, 0);
    }
  else if(leg == Leg::LB) {
      return LB::anglesInstance()(id, 0);
    }
  else if(leg == Leg::RB) {
      return RB::anglesInstance()(id, 0);
    }

  return 0;
}

void RobotModel::setAngle(Leg leg, int id, double angle) {
  if(leg == Leg::LF) {
      LF::anglesInstance()(id, 0) = angle;
    }
  else if(leg == Leg::RF) {
      RF::anglesInstance()(id, 0) = angle;
    }
  else if(leg == Leg::LB) {
      LB::anglesInstance()(id, 0) = angle;
    }
  else if(leg == Leg::RB) {
      RB::anglesInstance()(id, 0) = angle;
    }
}

Matrix<double, 3,1> RobotModel::getEndpoint(Leg leg) {
  Matrix<double, 4,1> ret(0.0,0.0,0.0,1.0);

  if(leg == Leg::LF) {
      ret = LF::Chain::forward(LF::anglesInstance());
    }
  else if(leg == Leg::RF) {
      ret = RF::Chain::forward(RF::anglesInstance());
    }
  else if(leg == Leg::LB) {
      ret = LB::Chain::forward(LB::anglesInstance());
    }
  else if(leg == Leg::RB) {
      ret = RB::Chain::forward(RB::anglesInstance());
    }

  return Matrix<double, 3,1>(ret(0,0), ret(1,0), ret(2,0));
}

bool RobotModel::setEndpoint(Leg leg, Matrix<double, 3,1> pos) {
  Matrix<double, 4,1> hpos(pos(0,0),pos(1,0),pos(2,0),1.0);

  if(leg == Leg::LF) {
      return gradient_method<LF::Chain>(hpos, LF::anglesInstance(), _gain, _max_iter, _stop_dist);
    }
  else if(leg == Leg::RF) {
      return gradient_method<RF::Chain>(hpos, RF::anglesInstance(), _gain, _max_iter, _stop_dist);
    }
  else if(leg == Leg::LB) {
      return gradient_method<LB::Chain>(hpos, LB::anglesInstance(), _gain, _max_iter, _stop_dist);
    }
  else if(leg == Leg::RB) {
      return gradient_method<RB::Chain>(hpos, RB::anglesInstance(), _gain, _max_iter, _stop_dist);
    }

  return false;
}
