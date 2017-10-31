#ifndef KEY_H
#define KEY_H

#include <string>
using std::string;

class Key {
public:
  Key(const string& key_p = "") : key(key_p), count(1) {}
  Key(const Key& other) : key(other.key), count(other.count) {}
  ~Key(){}
  inline bool operator<(const Key& other) const {return key < other.key;}
  inline Key& operator++() {count++; return *this;} // preincrement
  inline Key operator++(int) {Key tmp(*this); operator++(); return tmp;} //postincrement
  inline string getKey() const {return key;}
  inline int getCount() const {return count;}
private:
  string key;
  int count;
};

#endif
