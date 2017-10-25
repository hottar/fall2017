#ifndef ORGANIZER_H
#define ORGANIZER_H

#include "Reader.h"
#include "KeyGen.h"
#include "Storage.h"
#include "Filter.h"
#include "ExceptionLibrary.h"
#include "TFIDF.h"

class Organizer {
public:
  Organizer() {}
  ~Organizer() {}
  
  void readEx(const string& ex_fname);
  void readDoc(const string& fname);
  void store(const string& source);
  void unambiguous();
  string work(int argc, const char** argv);
  
private:
  KeyGen gen;
  Reader r;
  Filter f;
  Storage storage;
  ExceptionLibrary exLib;
  TFIDF tfidf;
};

#endif
