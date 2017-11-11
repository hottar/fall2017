#ifndef SUFFIX_H
#define SUFFIX_H

#include <string>
using std::string;

class SuFFix {
public:
  SuFFix() {}
  ~SuFFix() {}
  bool endsWith(const string& source, const string& suffix) const;
  void replaceWith(string& source, const string& suffix, const string& replace);
  bool tryReplaceWith(string& source, const string& suffix, const string& replace);
  bool hasVowel(const string& source) const;
  string fix(string& source);
  bool isVowel(const string& source) const;
  bool isDouble(const string& source) const;
  bool isLiEnd(const string& source) const;
  string region1(const string& source) const;
  string region2(const string& source) const;
  string preceder(const string& source, const string& suffix) const;
  bool isShortSyllable(const string& source) const;
  bool isShort(const string& source) const;
  void step1(string& source);
  void step2(string& source);
  void step3(string& source);
  void step4(string& source);
  void step5(string& source);
  void step6(string& source);
  void step7(string& source);
  void step8(string& source);
};

#endif
