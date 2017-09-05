#ifndef SCALER_TEMP
#define SCALER_TEMP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

template <typename T, int range_min = 0, int range_max = 19>
class Scaler{
public:
  inline Measure() : cntvec(range_max-rangemin+1, 0) {}
  inline ~Measure() {cntvec.clear();}
  void output() const;
  void add(T& val);
private:
  vector<T> cntvec;
};

#endif
