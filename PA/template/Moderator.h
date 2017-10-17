#ifndef MODERATOR_H
#define MODERATOR_H

#include "Scaler.h"

#include "Reader.h"

template<typename T>
class Moderator{
public:
  Moderator(string fname) : r(fname){}
  ~Moderator() {}
  inline void read(const string& fname) {r(fname);}
  inline void scale() { while(r.hasNext()) s.add(r.next()); }
  inline void result() {s.output(); }
private:
  Reader<T> r;
  Scaler<T> s;
};

#endif
