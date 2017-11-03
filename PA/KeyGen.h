#ifndef KEYGEN_H
#define KEYGEN_H

#include "Key.h"
#include "SuFFix.h"

class KeyGen {
public:
  KeyGen() {}
  ~KeyGen() {}
  inline Key generate(string source) { return Key(suffix.fix(source)); }
private:
  SuFFix suffix;
};

#endif
