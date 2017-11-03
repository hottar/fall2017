#include "Organizer.h"

#include <sstream>
using std::istringstream;

using const_it = map<string, Key>::const_iterator;

void Organizer::unambiguous() {
    const_it start(storage.lower_bound("+")), last(storage.upper_bound(","));
    const_it it(start);
    string ambig, unambig;
    int cnt;
    
    while ( it != last ) {
        ambig = (*it).first ;
        cnt = (*it).second.getCount();
        unambig = string(ambig.begin()+1, ambig.end());
        if(storage.find(unambig) == storage.end() ) // lower-case it
            transform(unambig.begin(), unambig.end(), unambig.begin(), tolower);
        for(int c = 0; c < cnt; c++)
            store(unambig);
        ++it;
    }
    storage.erase( start, last );
}

void Organizer::readDoc(const string& fname) {
    r.read(fname);
    string prev = ".";
    
    while(r.hasNext()) {
        for(auto var : f.filter(r.next(), prev) )
            store(var);
        prev = f.prev();
    }
}

void Organizer::readEx(const string& ex_fname) {
    r.read(ex_fname);
    string line, from, to, extra;
    while(r.hasNext()) {
        line = r.nextLine();
        if(line!="" && line!="\n") {
            istringstream iss(line);
            if( !(iss >> from >> to)) throw string("ORG_ERR: File " + ex_fname + " contains line with less than two strings!");
            iss >> extra;
            if(iss && extra != "\n") throw string("ORG_ERR: File " + ex_fname + " contains line with more than two strings!");
            exLib.store(ExceptionKey(from, to));
        }
    }
}

void Organizer::store(const string& source) {
    regex reg( R"((\'*[a-z]+\'*)+)" );
    if(exLib.contain(source) && source.size() > 2)
        storage.store( Key(exLib.morf(source)) ); // is in exception library
    else if(regex_match(source, reg))
        storage.store( gen.generate(source) ); // just a vocab
    else
        storage.store( Key(source) ); // unknown/acronym/etc.
}

string Organizer::work(int argc, const char** argv) {
    vector<string> fnames;
    for (int i  = 2; i < argc ; i++) fnames.push_back(argv[i]); 
    
    // read in exception File
    string ex_fname(argv[1]);
    readEx(ex_fname);
    
    for( auto fname : fnames) {
        // read in file to analyse
        readDoc(fname);
        
        // remove "+" ie. ambiguoug capitalizations
        unambiguous();

        // store file name and the analysed data
        tfidf.store(fname, storage);
        
        storage.clear();
    }
    
    // build the similarity
    tfidf.init();
    
    string s("");
    for ( auto doc1 : fnames) {
        for (auto doc2 : fnames) 
            s += to_string(tfidf.sim(doc1, doc2)) + "\t" ;
        s += "\n";
    }
    
    return s;
}

