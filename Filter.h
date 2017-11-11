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
    Filter() : sentence(0.0) {}
    ~Filter() {storage.clear();}
    inline void init() {storage.clear(); previous=""; sentence=0.0;}
    inline string prev() const {return previous;}
    inline float endLine() { return sentence; }
    vector<string> filter(const string& source, const string& prev);
    bool add(const string::const_iterator& it, int length);
    int find(const string& source, const string& r) const;
    int alphabet(const string& source) const;
    int ambigNumeric(const string& source) const;
    int numeric(const string& source) const;
    int punctuation(const string& source) const;
    int unknown(const string& source) const;
    bool wasEndLine() const;

private:
    vector<string> storage;
    string previous;
    float sentence;
};

#endif
