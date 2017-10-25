#ifndef EXKEY_H
#define EXKEY_H

#include "Key.h"

class ExceptionKey : public Key {
public:
  ExceptionKey(string from_p, string to_p) : Key(from_p), to(to_p) {}
  ~ExceptionKey() {}
  string To() const { return to; }
private:
  string to;
};

#endif
