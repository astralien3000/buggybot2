#include "buggybotTypeSupportImpl.h"

class BodyPoseNode {
  private:
  struct PrivateData;
  PrivateData* _data;
  
  public:
  BodyPoseNode(int, char**);
  ~BodyPoseNode(void);

  void onJointAngles(Buggybot::JointAngles);
};
