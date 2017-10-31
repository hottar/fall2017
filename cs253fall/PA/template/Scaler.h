#ifndef SCALER_TEMP
#define SCALER_TEMP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;
using std::lower_bound;

template <typename T>
class Scaler{
public:
  class Key{
  public:
    inline Key(const T& key_p, int cnt_p = 1) : key(key_p), cnt(cnt_p) {}
    //++, --, ==
    inline Key& operator++() {++cnt; return *this;} //pre-increment
    inline Key operator++(int) {Key tmp(*this); operator++(); return tmp;} //post-increment

    inline Key& operator--() {--cnt; return *this;} //pre-decrement
    inline Key operator--(int) {Key tmp(*this); operator++(); return tmp;} //post-decrement

    inline Key& operator+=(const Key& rhs) {cnt += rhs.cnt; return *this;}
    inline friend Key operator+(Key lhs, const Key& rhs) {lhs += rhs; return lhs;}

    inline bool operator< (const Key& rhs){ return key < rhs.key;}
    inline bool operator> (const Key& rhs){ return rhs < *this; }
    // inline bool operator<=(const Key& lhs, const Key& rhs){ return !(lhs > rhs); }
    // inline bool operator>=(const Key& lhs, const Key& rhs){ return !(lhs < rhs); }
    inline bool operator==(const Key& rhs){ return key == rhs.key;}
    inline bool operator!=(const Key& rhs){ return !(*this == rhs); }

    inline T& getKey() {return key;}
    inline int getCnt() {return cnt;}
  private:
    T key;
    int cnt;
  };

// public:
  inline Scaler() {}
  inline ~Scaler() {cntvec.clear();}

  inline typename vector<Key>::iterator indexOf(const T& val) const {return lower_bound(cntvec.begin(), cntvec.end(), Key(val)); }
  inline typename vector<Key>::iterator indexOf(Key& val) const {return lower_bound(cntvec.begin(), cntvec.end(), val); }
  inline T& get(int index) {return cntvec[index];}

  void output() const{
    for(auto var : cntvec)
      cout << var.getKey() << " " << var.getCnt() << endl;
  }

  void add(const T& val){
    typename vector<Key>::iterator it = indexOf(val);
    if(it!=cntvec.end()){
      *it++;
    } else {
      cntvec.push_back(Key(val));
      sort(cntvec.begin(), cntvec.end());
    }
  }

private:
  vector<Key> cntvec;
};

#endif
