#ifndef MODERATOR
#define MODERATOR

#include "Scaler.h"

#include "Reader.h"

template<typename T>
class Moderator{
public:
  void read(const string& fname) {r(fname);}
  void scale() {while(r.hasNext()) s.add(r.next()); }
  void result() {s.output(); }
private:
  Reader<T> r;
  Scaler<T> s;
};

#endif
