#include "Filter.h"

#define NUMERIC R"(\.?(?!\.|\,)(\d*|(\.|\,)(?!\,|\.))+\d)"
#define ALPHABET R"([a-zA-Z\']+)"
#define ALPHANUMERIC R"(([a-zA-Z\']+|\.?(?!\.|\,)(\d*|(\.|\,)(?!\,|\.))+\d)+)"
#define OTHER R"(([^\w\d']|_)+)"
#define UNKNOWN R"([A-Z][a-z\']*)"
#define VALIDPERIOD R"(([^\w\d\'\s]|_)*(\.|\!|\?)+([^\w\d\'\s]|_)*)"

vector<string> Filter::filter(const string& source, bool period) {
  init();
  string::const_iterator it = source.begin();
  int length(0);

  while(it!=source.end()){
    string input(it, source.end());
    if(period) {
      if(add(it, length = unknown( input )) != 0 ) storage.back() = "+" + storage.back();//(*(storage.end()-1)) = "+" + (*(storage.end()-1));
      else if(add(it, length = alphaNumeric( input )) != 0);
      else if(add(it, length = other( input )) != 0 );
    } else {
      if(add(it, length = alphaNumeric( input )) != 0 );
      else if(add(it, length = unknown( input )) != 0 ) storage.back() = "+" + storage.back();// (*(storage.end()-1)) = "+" + (*(storage.end()-1));
      else if(add(it, length = other( input )) != 0);
    }
    it += length;
    period = wasEndLine();
  }

  return storage;
}

bool Filter::add(const string::const_iterator& it, int length) {
  if(length==0) return 0;
  storage.push_back(string(it, it+length));
  return length;
}

int Filter::alphaNumeric(const string& source) const {
  regex r(ALPHANUMERIC);
  smatch m;
  regex_search(source, m, r);
  return m.position(0)==0 ? m.length() : 0;
}

int Filter::alphabet(const string& source) const {
  regex r( ALPHABET );
  smatch m;
  regex_search(source, m, r);
  return m.position(0)==0 ? m.length() : 0;
}

int Filter::numeric(const string& source) const{
  regex r( NUMERIC );
  smatch m;
  regex_search(source, m, r);
  return m.position(0)==0 ? m.length() : 0;
}

int Filter::other(const string& source) const {
  regex r( OTHER );
  smatch m;
  regex_search(source, m, r);
  return m.position(0)==0 ? m.length() : 0;
}

int Filter::unknown(const string& source) const {
  regex r( UNKNOWN );
  smatch m;
  regex_search(source, m, r);
  if(m.position(0)!=0) return 0;
  return (m.length() >= alphaNumeric(source)) ? m.length() : 0;
}

int Filter::alphaNumericAt(const string& source) const{
  regex r( ALPHANUMERIC );
  smatch m;
  regex_search(source, m, r);
  return m.position(0);
}

bool Filter::wasEndLine() const {
  regex r( VALIDPERIOD );
  return regex_match(storage.back(), r);
}
