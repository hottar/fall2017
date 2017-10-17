#include "sModerator.h"

#include <iostream>
using std::cerr;

int main(int argc, char** argv){
  if(argc != 2) {
    cerr << "Invalid number of arguments!" << endl;
    return -1;
  }
  const string fname = argv[1];
  try{
    sModerator m(fname);
    m.scale();
    m.result();
  } catch(string err) {
    cerr << err << endl;
  }

  return 0;
}
