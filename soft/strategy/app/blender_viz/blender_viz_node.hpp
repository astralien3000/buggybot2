#include "buggybotTypeSupportImpl.h"

class BlenderVizNode {
private:
  struct PrivateData;
  PrivateData* _data;

public:
  BlenderVizNode(int argc, char* argv[]);
  ~BlenderVizNode(void);

  void onJointAngles(Buggybot::JointAngles msg);

  void (*callback)(const char*);
};
