#include "sDivider.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv){
  sDivider sd;

  vector<string> vs = sd.cut("Why", true);
  for(auto var : vs)
    cout << var << " | ";
  cout << endl;

  string s("Why,didn't~Whale!AD2020?you");
  vs = sd.cut(s, true);
  for(auto var : vs)
    cout << var << " | ";
  cout << endl;

  s = "didn't~Whale!AD2020?you";
  regex r(R"([A-z]*[']+[A-z]*.*)");
  cout << regex_match(s,r) << endl;

  s = "This is a test, test it is!!";
  vs = sd.cut(s, true);
  for(auto var : vs)
    cout << var << "\\";
    cout << endl;
  return 1;
}
