// measure.h

// Rick Hotta
// CS253
// PA1
// Sep 3, 2017

#ifndef MEASURE_H
#define MEASURE_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;

class Measure{
public:
  inline Measure(int min_p = 0, int max_p = 0) : intcnt(20), min(min_p), max(max_p) {}
  inline ~Measure() {intcnt.clear();}
  inline void output(const vector<int> vec) const {int cnt = min; for(auto var : vec) cout << cnt++ << " " << var << endl;}
  inline void errmsg(const string errorcode) const { throw string("Error! "+ errorcode); }
  void read(string fname);
  void add(int var);
private:
  vector<int> intcnt;
  int min;
  int max;
};

#endif
