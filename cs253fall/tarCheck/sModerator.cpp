#include "sModerator.h"

void sModerator::scale() {
  bool flag(true);
  while(r.hasNext()) {
    vector<string> tmp = d.cut(r.next(), flag);
    flag = d.hadEndMark(r.prev()) ? true : false;
    for(auto var : tmp) s.add(var);
  }
}
