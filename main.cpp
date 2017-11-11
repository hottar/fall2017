#include "Organizer.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::stof;

int main(int argc, const char** argv) {
  Organizer o;
  try {
    if(argc<4) throw string("ARGC_ERR: Not enough arguments!");
    cout << o.work(argv[1], argv[2], stof(argv[3]), stof(argv[4])) << endl;
  } catch(string e) {
    cerr << e << endl;
    return -1;
  }

  return 0;
}
