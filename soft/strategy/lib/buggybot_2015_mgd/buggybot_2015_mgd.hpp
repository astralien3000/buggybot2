#include <mgd.hpp>

class Buggybot2015MGD : public MGD {
private:
  struct PrivateData;
  PrivateData* _data;

  void addLeg(std::string prefix, double sx, double sy);
  
public:
  Buggybot2015MGD(void);
  ~Buggybot2015MGD(void);
};
