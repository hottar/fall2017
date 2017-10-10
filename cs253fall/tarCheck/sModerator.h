#ifndef STRMODERATOR_H
#define STRMODERATOR_H

#include "sScaler.h"

#include "sReader.h"

#include "sDivider.h"

class sModerator{
public:
  sModerator(string fname) : r(fname){}
  ~sModerator() {}
  void scale();
  inline void result() {s.output(); }
private:
  sReader r;
  sScaler s;
  sDivider d;
};

#endif
