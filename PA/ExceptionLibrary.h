#ifndef EXLIB_H
#define EXLIB_H

#include <unordered_map>
using std::unordered_map;

#include "ExceptionKey.h"

class ExceptionLibrary {
public:
  ExceptionLibrary(int size = 0) : library(size) {}
  ~ExceptionLibrary() {init();}
  inline void init() { library.clear(); }
  inline void store(const ExceptionKey& exkey) { library.emplace(exkey.getKey(), exkey); }
  inline bool contain(const string& from) const { return library.find(from)!=library.end(); }
  inline string morf(const string& from) const { unordered_map<string, ExceptionKey>::const_iterator it=library.find(from); return (it==library.end()) ? from : (*it).second.To(); }
  inline string tostring() const {if(library.empty()) throw string("EXLIB_ERR: No element is stored!"); string s(""); for(auto var : library) s+=(var.second.getKey() + " " + var.first + "\n"); return s;}
private:
  unordered_map<string, ExceptionKey> library;
};

#endif
