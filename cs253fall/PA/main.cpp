#include "Organizer.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, const char** argv) {
  Organizer o;
  try {
    if(argc<3) throw string("ARGC_ERR: Not enough arguments!");
    cout << o.work(argc, argv) << endl;
  } catch(string e) {
    cerr << e << endl;
    return -1;
  }

  return 0;
}
