#include "buggybot_2015_mgd.hpp"
#include "utils.hpp"

#include <vector>

struct Buggybot2015MGD::PrivateData {
  std::vector<double> L;
};

void Buggybot2015MGD::addLeg(std::string prefix, double sx, double sy) {
  addConstantMatrix(prefix+".side",
		    "body",
		    scal(sx, sy, 1));
  
  addConstantMatrix(prefix+".shoulder.pos",
		    prefix+".side",
		    trans(_data->L[0], _data->L[1], _data->L[2]));

  addVariableMatrix(prefix+".shoulder",
		    prefix+"0",
		    prefix+".shoulder.pos",
		    [](double q) {
		      return rot_x(q);
		    });

  addConstantMatrix(prefix+".arm.pos",
		    prefix+".shoulder",
		    trans(_data->L[3], _data->L[4], -_data->L[5]));

  addVariableMatrix(prefix+".arm",
		    prefix+"1",
		    prefix+".arm.pos",
		    [](double q) {
		      return rot_x(-q);
		    });

  addConstantMatrix(prefix+".forearm.pos",
		    prefix+".arm",
		    trans(_data->L[6], -_data->L[9], -_data->L[7]));

  addVariableMatrix(prefix+".forearm",
		    prefix+"2",
		    prefix+".forearm.pos",
		    [](double q) {
		      return rot_x(-q);
		    });

  addConstantMatrix(prefix+".endpoint",
		    prefix+".forearm",
		    trans(_data->L[10], 0, -_data->L[8]));

  // Display
  addConstantMatrix(prefix+".base",
		    prefix+".shoulder.pos",
		    trans(-2,-19.5,13.5) * rot_z(180.0_deg) * rot_x(-90.0_deg));

  addConstantMatrix(prefix+".servo",
		    prefix+".shoulder.pos",
		    trans(-59.25,0,-1) * rot_x(-90.0_deg) * rot_z(-90.0_deg));

  addConstantMatrix(prefix+".shoulder.base",
		    prefix+".shoulder",
		    trans(0,10,-37.5) * rot_x(0.0_deg) * rot_z(180.0_deg));
  
  addConstantMatrix(prefix+".shoulder.servo",
		    prefix+".shoulder",
		    trans(0,-16,-33.8) * rot_x(0.0_deg) * rot_y(180.0_deg));

  addConstantMatrix(prefix+".arm.base",
		    prefix+".arm",
		    trans(0,9.5,-35) * rot_z(180.0_deg) * rot_y(180.0_deg));

  addConstantMatrix(prefix+".forearm.base",
		    prefix+".forearm",
		    trans(4.5,15,-23) * rot_z(180.0_deg) * rot_y(0.0_deg));

  addConstantMatrix(prefix+".forearm.servo",
		    prefix+".forearm",
		    trans(-16,0,0) * rot_z(-90.0_deg) * rot_y(0.0_deg));
}

Buggybot2015MGD::Buggybot2015MGD(void) {
  _data = new PrivateData;
  _data->L = {
    9.8_cm,
    5.0_cm,
    1.5_cm,
    0.0_cm,
    0.0_cm,
    3.3_cm,
    0.0_cm,
    7.0_cm,
    5.5_cm,
    2.1_cm,
    0.5_cm
  };
  
  addRootMatrix("body", Matrix::Identity());
  addConstantMatrix("blender_adapter", "body", rot_z(90.0_deg));
  addConstantMatrix("base", "blender_adapter", rot_z(-90.0_deg) * rot_x(90.0_deg));
  addLeg("lf",  1, 1);
  addLeg("lb", -1, 1);
  addLeg("rf",  1,-1);
  addLeg("rb", -1,-1);
}


Buggybot2015MGD::~Buggybot2015MGD(void) {
  delete _data;
}
