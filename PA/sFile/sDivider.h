#ifndef SDIVIDER_H
#define SDIVIDER_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <regex>
using std::regex;
using std::regex_search;
using std::regex_match;
using std::smatch;

#include <iostream> //erase after use.
using std::cout;
using std::endl;

class sDivider{
public:
  vector<string> cut(string word);
  vector<string> cut(string word, bool flag);
  inline bool hadEndMark(string prev) {return regex_match(prev, regex( R"(.*[.!?]+)" ));}
private:
  string parent;
  string child;
  inline void load(string word) {parent=word;}
  inline void load(smatch m) {child=m[0];}
  void load(const regex& r);
  void load(const regex& r, bool flag);

  inline bool match(const regex& r) {return regex_match(parent, r);}

  inline bool hasEndMark() {return match(regex( R"([.!?]+.*)" ));}
  inline bool hasNonAlphaNumeric() {return match(regex( R"([\W]+.*)" ));}
  inline bool hasDigit() {return match(regex( R"(((\d*)[,]?)*[.,]?(\d+).*)" ));}
  inline bool hasRy() {return match(regex( R"([A-z]+(((\d*)[,]?)*[.,]?(\d+))+.*)" )); } // (ry
  inline bool hasActiveAmbiguous() {return match(regex( R"([A-Z][a-z]*.*)" ));}
  inline bool hasPassiveAmbiguous() {return match(regex( R"([.!?]+[A-Z][a-z]*.*)" ));}
  inline bool hasApostrophes() {return match(regex( R"([A-z]*[']+[A-z]*.*)" ));}
  inline bool hasAlpha() {return match(regex( R"([A-z]+.*)" ));}

  inline void endMark(){load(regex( R"([.!?]+)" ));} //.?!
  inline void nonAlphaNumeric(){load(regex( R"([\W]+)" ));}
  inline void digit() {load(regex( R"(((\d*)[,]?)*[.,]?(\d+))" ));}
  inline void ry(){load(regex( R"([A-z]+(((\d*)[,]?)*[.,]?(\d+))+)" ));}
  inline void activeAmbiguous(){load(regex( R"([A-Z][a-z]*)" ), true);}
  inline void passiveAmbiguous(){load(regex( R"([.!?]+[A-Z][a-z]*)" ), true);}
  inline void apostrophes(){load(regex( R"([A-z]*[']+[A-z]*)" ));}
  inline void alpha(){load(regex( R"([A-z]+)" ));}

  inline void debug(smatch m) {cout << m[0] << " ";} // erase after use
};

#endif
