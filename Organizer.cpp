#include "Organizer.h"

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
    string prev = "\n";
    
    while(r.hasNext()) {
        for(auto var : f.filter(r.next(), prev) ) {
            lv.insert(var);
            store(var);
        }
        lv.newline(f.endLine());
        prev = f.prev();
    }
    
    lvlist.store(fname, lv.level());
    lv.reset();
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

void Organizer::readDocInFile(const string& fname) {
    r.read(fname);
    
    // first read in exception files
    readEx(r.next());
    
    // read the list of files to analyse
    string doc;
    while(r.hasNext()) {
        // read in the document to analyse data and reading levels.
        readDoc(r.next());
        // remove "+" ie. amgious capitalizations
        unambiguous();
        // store file name and the analysed data
        tfidf.store(fname, storage);
        // reset the word lists
        storage.clear();
    }
}

string Organizer::compare( const string& targetfile ) {
    // build the similarity
    tfidf.init();
    
    float max(-1.0), tmp;
    string simf;
    for(auto var : lvlist ) {
        if( tmp = tfidf.sim(targetfile, var.first) <= max ) {
            max = tmp;
            simf = var.first;
        }
    }
    
    return simf;

//     stringstream stream;
//     for ( auto doc1 : fnames) {
//         for (auto doc2 : fnames)
//             stream << right << setw(10) << fixed << setprecision(3) << tfidf.sim(doc1, doc2);
//         stream << "\n";
//     }
//     
//     return stream.str();
}

string Organizer::work(const string& targetname, const string& fname, float low, float high) {
    lvlist.setBounds(low, high);
    
    readDocInFile(fname);
    
    return compare(targetname);
}
