#include "stand.hpp"

void AnimStand::update(LegAction& lf, LegAction& rf, LegAction& rb, LegAction& lb) {
  t = add_mod(t, 1.0/freq, cfg.period);

  lf.x = lfc.default_x;
  lf.y = lfc.default_y;
  lf.z = lfc.default_z;

  rf.x = rfc.default_x;
  rf.y = rfc.default_y;
  rf.z = rfc.default_z;

  rb.x = rbc.default_x;
  rb.y = rbc.default_y;
  rb.z = rbc.default_z;

  lb.x = lbc.default_x;
  lb.y = lbc.default_y;
  lb.z = lbc.default_z;
}
