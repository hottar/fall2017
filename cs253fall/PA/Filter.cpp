#include "Filter.h"

#define NUMERIC R"(\.?(?!\.|\,)(\d*|(\.|\,)(?!\,|\.))+\d)"
#define ALPHABET R"([a-zA-Z\']+)"
#define ALPHANUMERIC R"(([a-zA-Z\']+|\.?(?!\.|\,)(\d*|(\.|\,)(?!\,|\.))+\d)+)"
#define OTHER R"(([^\w\d']|_)+)"
#define UNKNOWN R"([A-Z][a-z\']*)"
#define VALIDPERIOD R"(([^\w\d\'\s]|_)*(\.|\!|\?)+([^\w\d\'\s]|_)*)"

vector<string> Filter::filter(const string& source, const string& prev) {
  init();
  previous = prev;
  string::const_iterator it = source.begin();
  int length(0);

  while(it!=source.end()){
    string input(it, source.end());
    
    if(add(it, length = unknown( input )) != 0 ) storage.back() = "+" + storage.back();
    else if(add(it, length = alphaNumeric( input )) != 0);
    else length = other( input );
    
    previous = string(it, it+length);
    it += length;
  }

  return storage;
}

bool Filter::add(const string::const_iterator& it, int length) {
  if(length==0) return 0;
  storage.push_back(string(it, it+length));
  return length;
}

int Filter::find(const string& source, const string& r) const {
  smatch m;
  regex_search(source, m, regex(r));
  return m.position(0)==0 ? m.length() : 0;
}

int Filter::alphaNumeric(const string& source) const {
  return find(source, ALPHANUMERIC);
}

int Filter::other(const string& source) const {
  return find(source, OTHER);
}

int Filter::unknown(const string& source) const {
  int length = find(source, UNKNOWN);
  return (length >= alphaNumeric(source) && wasEndLine() ) ? length : 0;
}

bool Filter::wasEndLine() const {
  return regex_match(previous, regex(VALIDPERIOD));
}
