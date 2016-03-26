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
		    "base",
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

MGD::Matrix Buggybot2015MGD::leg_matrix() {
  return trans(_data->L[0], _data->L[1], _data->L[2]);
}


MGD::Matrix Buggybot2015MGD::shoulder_matrix(double a) {
  MGD::Matrix ret = MGD::Matrix::Identity();
  ret(1,1) = cos(a);
  ret(1,2) = -sin(a);
  ret(2,1) = sin(a);
  ret(2,2) = cos(a);  
  return ret * rot_z(90.0_deg);
}

MGD::Matrix Buggybot2015MGD::arm_matrix(double a) {
  a = -a;
  MGD::Matrix ret = trans(_data->L[3], _data->L[4], -_data->L[5]);
  ret(1,1) = cos(a);
  ret(1,2) = -sin(a);
  ret(2,1) = sin(a);
  ret(2,2) = cos(a);
  return ret;
}

MGD::Matrix Buggybot2015MGD::forearm_matrix(double a) {
  MGD::Matrix ret = trans(_data->L[6], -_data->L[9], -_data->L[7]);
  ret(1,1) = cos(a);
  ret(1,2) = -sin(a);
  ret(2,1) = sin(a);
  ret(2,2) = cos(a);  
  return ret;
}

/*
def shoulder_matrix(bot, q0, q1, q2):
    return [
        [1,0,0,0],
        [0,np.cos(q0),-np.sin(q0),0],
        [0,np.sin(q0),np.cos(q0),0],
        [0,0,0,1]]

def arm_matrix(bot, q0, q1, q2):
    a = -q1
    return [
        [0,-np.cos(a),np.sin(a),bot.L[3]],
        [1,0,0,bot.L[4]],
        [0,np.sin(a),np.cos(a),-bot.L[5]],
        [0,0,0,1]]

def forearm_matrix(bot, q0, q1, q2):
    a = -q2
    return [
        [1,0,0,bot.L[6]],
        [0,np.cos(a),-np.sin(a),-bot.L[9]],
        [0,np.sin(a),np.cos(a),-bot.L[7]],
        [0,0,0,1]]

*/

void Buggybot2015MGD::addLeg2(std::string prefix) {
              // LEG_REF
            addConstantMatrix(prefix+".LegRef", 
			      prefix+".SideRef",
			      leg_matrix()); 
            // SHOULDER_BASE
            addConstantMatrix(prefix+".ShoulderBase", 
			      prefix+".LegRef",
			      trans(-2,-19.5,13.5) * rot_z(180.0_deg) * rot_x(-90.0_deg));
            // SERVO_BASE
            addConstantMatrix(prefix+".ServoBase", 
			      prefix+".LegRef",
			      trans(-59.25,0,-1) * rot_x(-90.0_deg) * rot_z(-90.0_deg));
            // SHOULDER_REF
            addVariableMatrix(prefix+".ShoulderRef",
			      prefix+"0",
			      prefix+".LegRef",
			      [this](double a) { return this->shoulder_matrix(a); });
	    //shoulder_matrix);
            // SHOULDER
            addConstantMatrix(prefix+".Shoulder", 
			      prefix+".ShoulderRef",
			      rot_z(-90.0_deg) * trans(0,10,-37.5) * rot_x(0.0_deg) * rot_z(180.0_deg));
            // SERVO_ARM
            addConstantMatrix(prefix+".ServoArm", 
			      prefix+".ShoulderRef",
			      rot_z(-90.0_deg) * trans(0,-16,-33.8) * rot_x(0.0_deg) * rot_y(180.0_deg));
            // ARM_REF
            addVariableMatrix(prefix+".ArmRef", 
			      prefix+"1", 
			      prefix+".ShoulderRef",
			      [this](double a) { return this->arm_matrix(a); });
			      //mgd.arm_matrix(LegConfig, *q));
            // ARM
            addConstantMatrix(prefix+".Arm", 
			      prefix+".ArmRef",
			      trans(0,9.5,-35) * rot_z(180.0_deg) * rot_y(180.0_deg));
            // FOREARM_REF
            addVariableMatrix(prefix+".ForearmRef", 
			      prefix+"2", 
			      prefix+".ArmRef",
			      [this](double a) { return this->forearm_matrix(a); });
			      //mgd.forearm_matrix(LegConfig, *q)); 
            // SERVO_FOREARM
            addConstantMatrix(prefix+".ServoForearm", 
			      prefix+".ForearmRef",
			      trans(-16,0,0) * rot_z(-90.0_deg) * rot_y(0.0_deg));
            // FOREARM
            addConstantMatrix(prefix+".Forearm", 
			      prefix+".ForearmRef",
			      trans(4.5,15,-23) * rot_z(180.0_deg) * rot_y(0.0_deg));
            // ENDPOINT
            addConstantMatrix(prefix+".Endpoint", 
			      prefix+".ForearmRef",
			      trans(_data->L[10],0,-_data->L[8])) ;
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

  // MINI
  addRootMatrix("Mini", scal(0.1,0.1,0.1));
  // ROBOT
  addConstantMatrix("Robot", 
		    "Mini",
		    rot_z(90.0_deg));
  // BASE
  addConstantMatrix("Base",
		    "Robot",
		    rot_z(-90.0_deg) * rot_x(90.0_deg));
  // SIDE_REF
  addConstantMatrix("LF.SideRef", 
		    "Robot",
		    scal(1,1,1));
  addConstantMatrix("RF.SideRef", 
		    "Robot",
		    scal(1,-1,1));
  addConstantMatrix("RB.SideRef", 
		    "Robot",
		    scal(-1,-1,1));
  addConstantMatrix("LB.SideRef", 
		    "Robot",
		    scal(-1,1,1));

  addLeg("lf",  1, 1);
  addLeg("lb", -1, 1);
  addLeg("rf",  1,-1);
  addLeg("rb", -1,-1);

  addLeg2("LF");
  addLeg2("LB");
  addLeg2("RF");
  addLeg2("RB");
}


Buggybot2015MGD::~Buggybot2015MGD(void) {
  delete _data;
}
