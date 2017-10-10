#ifndef ORGANIZER_H
#define ORGANIZER_H

#include "Reader.h"
#include "KeyGen.h"
#include "Storage.h"
#include "Filter.h"

#define PERIOD R"(([^\w\d\'\s]|_)*(\.|\!|\?)+([^\w\d\'\s]|_)*)"

class Organizer {
public:
  Organizer() {}
  ~Organizer() {}
  string work(const string& fname);
  inline bool validPeriod(const string& source) { return regex_match(source, regex(PERIOD)); }
private:
  KeyGen gen;
  Reader r;
  Filter f;
  Storage storage;
};

#endif
