#include "Organizer.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char** argv) {
  Organizer o;
  try {
    if(argc<2) throw string("ARGC_ERR: Not enough arguments!");
    cout << o.work(argv[1]) << endl;
  } catch(string e) {
    cout << e << endl;
  }

  return 0;
}
