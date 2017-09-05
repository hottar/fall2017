#include "Measure.h"

int main(int argc, char** argv){
  if(argc < 2) throw "Not enough arguments!";

  Measure measure(0, 19);
  try{
    measure.read(string(argv[1]));
  } catch(string err) {
    cerr << err << endl;
  }

  return 0;
}
