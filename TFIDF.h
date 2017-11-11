#ifndef TFIDF_H
#define TFIDF_H

#include "IDF.h"

class TFIDF {
public:
    TFIDF() {}
    ~TFIDF() { storage_map.clear(); }
    
    inline void store(const string& fname, const Storage& storage) { storage_map.insert( {fname, storage} ); }
    inline void init() { idf = IDF(storage_map.size()); for(auto pair : storage_map) idf.store(pair.second);}
    inline double get(const Key& key) const { return double(key.getCount()) * idf.get(key.getKey()); }
    
    double sim(const string& doc1, const string& doc2) const;
    double sim(const Storage& doc1, const Storage& doc2) const;
private:
    IDF idf;
    map<string, Storage> storage_map;
};

#endif
