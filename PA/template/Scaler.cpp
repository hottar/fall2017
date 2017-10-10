#include "Scaler.h"

template<typename T>
void Scaler<T>::output() const{
  for(auto var : cntvec)
    cout << var.getKey() << " " << var.getCnt() << endl;
}

template<typename T>
void Scaler<T>::add(T& val){
  typename vector<Key>::iterator it = indexOf(val);
  if(it!=cntvec.end()){
    *it++;
  } else {
    cntvec.push_back(Key(val));
    sort(cntvec.begin(), cntvec.end());
  }
}
