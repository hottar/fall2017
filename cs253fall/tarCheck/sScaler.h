#ifndef STRSCALER_TEMP
#define STRSCALER_TEMP

#include "sKey.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;
using std::lower_bound;

class sScaler {
public:
  inline sScaler() {}
  inline ~sScaler() {cntvec.clear();}

  inline vector<sKey>::iterator indexOf(const string& val) {return find(cntvec.begin(), cntvec.end(), sKey(val)); }
  inline vector<sKey>::iterator indexOf(sKey& val) {return find(cntvec.begin(), cntvec.end(), val); }
  inline sKey& get(int index) {return cntvec[index];}

  void output() const;
  void add(const string& val);

private:
  vector<sKey> cntvec;
};

#endif
