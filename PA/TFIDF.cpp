#include "TFIDF.h"

double TFIDF::sim(const Storage& doc1, const Storage& doc2) const {
    double sum(0.0);
    auto it(doc2.end());
    for(auto pair : doc1) {
        it = doc2.find(pair.first);
        if(it!=doc2.end())
            sum += ( get(pair.second) * get((*it).second) );
    }
    return sum;
}

double TFIDF::sim(const string& doc1, const string& doc2) const {
    auto it1(storage_map.find(doc1)), it2(storage_map.find(doc2));
    return sim( (*it1).second, (*it2).second );    
}
