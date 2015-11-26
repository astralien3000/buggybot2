#include <mgd.hpp>

class Buggybot2015MGD : public MGD {
private:
  struct PrivateData;
  PrivateData* _data;

  MGD::Matrix leg_matrix();
  MGD::Matrix shoulder_matrix(double);
  MGD::Matrix arm_matrix(double);
  MGD::Matrix forearm_matrix(double);
  
  void addLeg(std::string prefix, double sx, double sy);
  void addLeg2(std::string prefix);
  
public:
  Buggybot2015MGD(void);
  ~Buggybot2015MGD(void);
};
