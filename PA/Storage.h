#ifndef STORAGE_H
#define STORAGE_H

#include <map>
using std::map;
using std::pair;

#include "Key.h"

#include <string>
using std::to_string;

using m = map<string, Key>;
using const_it = m::const_iterator;

class Storage {
public:
  inline Storage() {}
  inline ~Storage() {clear();}
  
  inline void clear() { container.clear(); }
  inline const_it begin() const { return container.begin(); }
  inline const_it end() const { return container.end(); }
  inline const_it find(const string& source) const { return container.find(source); }
  inline const_it lower_bound(const string& source) const {return container.lower_bound(source); }
  inline const_it upper_bound(const string& source) const {return container.upper_bound(source); }
  inline const_it prev() { if(container.empty()) throw string("STORAGE_ERR: There is no previous element !"); return const_it(previous); }
  inline void erase(const_it& it) { container.erase(it); }
  inline void erase(const_it& start, const_it& last) { container.erase(start, last); }
  inline void store(const Key& val) { if(val.getKey()!="") { auto p = container.insert( {val.getKey(), val }); if(!p.second) (*p.first).second++; previous = p.first; } }
  inline string tostring() const {if(container.empty()) throw string("STORAGE_ERR: No element is stored!"); string s(""); for(auto var : container) s+=(var.first + " " + to_string(var.second.getCount()) + "\n"); return s;}
  
private:
  m container;
  m::iterator previous;
  
};

#endif
