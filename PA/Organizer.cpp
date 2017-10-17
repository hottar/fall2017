#include "Organizer.h"

string Organizer::work(const string& fname) {
  regex reg( R"((\'*[a-z]+\'*)+)" );
  bool period(true);

  r.read(fname);
  while(r.hasNext()) {
    for(auto var : f.filter(r.next(), period) ) {
      period = validPeriod(var);
      if(regex_match(var, reg)) storage.store(gen.generate(var));
      else storage.store(Key(var));
    }
  }
  return storage.tostring();
}
