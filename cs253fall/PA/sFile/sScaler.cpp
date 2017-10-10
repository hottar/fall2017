#include "sScaler.h"

void sScaler::output() const{
  for(auto var : cntvec)
    cout << var.getKey() << " " << var.getCnt() << endl;
}

void sScaler::add(const string& val){
  vector<sKey>::iterator it = indexOf(val);
  if(it!=cntvec.end()){
    (*it)++;
  } else {
    cntvec.push_back(sKey(val));
    sort(cntvec.begin(), cntvec.end());
  }
}
