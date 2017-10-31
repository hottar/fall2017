#ifndef IDF_H
#define IDF_H

#include "Storage.h"

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <math.h>
using std::log10;

class IDF{
public:
    IDF(int n_p=1) : N(n_p) {}
    ~IDF() {freq_map.clear();}
    inline void store(const vector<Storage>& storageList) {for( auto storage : storageList ) store(storage);}
    inline void store(const Storage& storage) { for(auto pair : storage) update(pair.first); }
    inline int freq(const string& source) const {return (*freq_map.find(source)).second; }
    inline double get(const string& source) const { double frac(double(N)/double(freq(source))); return log10(frac);}
    void update(const string& source);
private:
    unordered_map<string, int> freq_map;
    int N;
};

#endif
