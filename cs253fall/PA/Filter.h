#ifndef FILTER_H
#define FILTER_H

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <regex>
using std::regex;
using std::regex_search;
using std::regex_match;
using std::smatch;

class Filter {
public:
  Filter() {}
  ~Filter() {storage.clear();}
  inline void init() {storage.clear(); previous="";}
  inline string prev() const {return previous;}
  vector<string> filter(const string& source, const string& prev);
  bool add(const string::const_iterator& it, int length);
  int find(const string& source, const string& r) const;
  int alphaNumeric(const string& source) const;
  int other(const string& source) const;
  int unknown(const string& source) const;
  bool wasEndLine() const;

private:
  vector<string> storage;
  string previous;
};

#endif
