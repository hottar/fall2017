#ifndef STORAGE_H
#define STORAGE_H

#include <map>
using std::map;

#include "Key.h"

#include <string>
using std::to_string;

class Storage {
public:
  inline Storage() {}
  inline ~Storage() {container.clear();}
  inline void store(const Key& val) { if(val.getKey()!="") {map<string, Key>::iterator it = container.find(val.getKey()); if(it==container.end()) container.insert( {val.getKey(), val } ); else (*it).second++;} }
  inline string tostring() {if(container.empty()) throw string("STORAGE_ERR: No element is stored!"); string s(""); for(auto var : container) s+=(var.first + " " + to_string(var.second.getCount()) + "\n"); return s;}
private:
  map<string, Key> container;
};

#endif
