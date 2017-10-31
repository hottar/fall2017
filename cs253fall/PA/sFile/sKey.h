#ifndef STRKEY_H
#define STRKEY_H

#include <string>
using std::string;

class sKey{
public:
  inline sKey(const string& key_p, int cnt_p = 1) : key(key_p), cnt(cnt_p) {}
  //++, --, ==
  inline sKey& operator++() {++cnt; return *this;} //pre-increment
  inline sKey operator++(int) {sKey tmp(*this); operator++(); return tmp;} //post-increment

  inline sKey& operator--() {--cnt; return *this;} //pre-decrement
  inline sKey operator--(int) {sKey tmp(*this); operator++(); return tmp;} //post-decrement

  inline sKey& operator+=(const sKey& rhs) {cnt += rhs.cnt; return *this;}
  inline friend sKey operator+(sKey lhs, const sKey& rhs) {lhs += rhs; return lhs;}

  inline bool operator< (const sKey& rhs){ return key < rhs.key;}
  inline bool operator> (const sKey& rhs){ return rhs.key < key; }
  // inline bool operator<=(const Key& lhs, const Key& rhs){ return !(lhs > rhs); }
  // inline bool operator>=(const Key& lhs, const Key& rhs){ return !(lhs < rhs); }
  inline bool operator==(const sKey& rhs){ return key == rhs.key;}
  inline bool operator!=(const sKey& rhs){ return !(*this == rhs); }

  inline string& getKey() {return key;}
  inline int getCnt() {return cnt;}
private:
  string key;
  int cnt;
};

#endif
