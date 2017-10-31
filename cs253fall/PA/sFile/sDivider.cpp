#include "sDivider.h"

vector<string> sDivider::cut(string word){
  load(word);
  vector<string> wordList;
  bool flag(false);
  while(parent.size()>0){
    if(hasRy()) {ry(); flag=false;}
    else if(hasApostrophes()) {apostrophes(); flag=false;}
    else if(flag) {activeAmbiguous(); flag=false;}
    else if(hasPassiveAmbiguous()) {endMark(); flag=true;}
    else if(hasAlpha()) alpha();
    else if(hasDigit()) digit();
    else if(hasEndMark()) endMark();
    else if(hasNonAlphaNumeric()) nonAlphaNumeric();
    wordList.push_back(child);
  }
return wordList;
}

vector<string> sDivider::cut(string word, bool flag){
  if(!flag) return cut(word);

  load(word);
  vector<string> wordList;
  if(parent.size()>0) {
    if(hasActiveAmbiguous()) {
      activeAmbiguous();
      wordList.push_back(child);
    }
  }

  vector<string> tmp(cut(parent));
  for(auto var : tmp)
    wordList.push_back(var);
  return wordList;
}

void sDivider::load(const regex& r){
  smatch m;
  regex_search(parent, m, r);
  child = m[0].str();
  parent = parent.substr(child.size());
}

void sDivider::load(const regex& r, bool flag){
  if(!flag) load(r);
  else {
    smatch m;
    regex_search(parent, m, r);
    child = "+" + m[0].str();
    parent = parent.substr(m[0].str().size());
  }
}
