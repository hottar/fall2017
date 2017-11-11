#include "IDF.h"

void IDF::update(const string& source){
    auto it = freq_map.find(source);
    if(it==freq_map.end())
        freq_map.emplace(source, 1);
    else
        (*it).second++;
}
