#include "Filter.h"

#define ALPHABET    R"([^@!\"#$%&\(\)*+,-./:;<=>?`\[\\\]^_{|}~\d\s]+)"
#define AMBIGNUM    R"(\.?(?!\.|\,)\d+((\.|\,)(?!\,|\.)\d+)*)"
#define NUMERIC     R"(\d+((\.|\,)(?!\,|\.)\d+)*)"
#define PUNCTUATION R"([@!\"#$%&\(\)*+,-./:;<=>?`\[\\\]^_{|}~]+)"
#define UNKNOWN     R"([A-Z][^@!\"#$%&\(\)*+,-./:;<=>?`\[\\\]^_{|}~\d\s]*)"
#define ENDLINE     R"([@!\"#$%&\(\)*+,-./:;<=>?`\[\\\]^_{|}~]*(\.|\!|\?)+[@!\"#$%&\(\)*+,-./:;<=>?`\[\\\]^_{|}~]*)"

/**
 * @note flag makes a diff in running Alice. it will read 1 sentence less.
 */
vector<string> Filter::filter(const string& source, const string& prev) {
    init();
    previous = prev;
    string::const_iterator it = source.begin();
    int length;
    
    if( add(it, length = ambigNumeric( source ) ) );
    it += length;
    
    while(it != source.end() ) {
        string input(it, source.end());
        
        if(add(it, length = unknown( input )) != 0 ) storage.back() = "+" + storage.back();
        else if( add(it, length = alphabet( input )) != 0 );
        else if( add(it, length = numeric( input )) != 0 );
        else length = punctuation( input );
        
        previous = string(it, it + length);
        if(wasEndLine()) ++sentence;
        it += length;
    }
    
    return storage;
}

bool Filter::add(const string::const_iterator& it, int length) {
    if(length==0) return 0;
    storage.push_back(string(it, it+length));
    return length;
}

int Filter::find(const string& source, const string& r) const {
    smatch m;
    regex_search(source, m, regex(r));
    return m.position(0)==0 ? m.length() : 0;
}

/**
 * Recurses between this and numeric, substringing each time.
 */
int Filter::alphabet( const string& source ) const {
    int len = find(source, ALPHABET);
    return (len != 0) ? len + numeric( string( source.begin() + len, source.end() ) ) : 0;
}

/**
 * @brief Searches for numbers that may start be decimal starting form period
 * <br> eg. .32 and not 0.32 </br>
 * @note Only used at the beginning of the filter call, don't call this in loop.
 */
int Filter::ambigNumeric(const string& source ) const {
    int len = find(source, AMBIGNUM);
    return (len != 0) ? len + alphabet( string( source.begin() + len, source.end() ) ) : 0;
}

int Filter::numeric( const string& source ) const {
    int len = find(source, NUMERIC);
    return (len != 0) ? len + alphabet( string( source.begin() + len, source.end() ) ) : 0;
}

int Filter::punctuation( const string& source ) const {
    return find(source, PUNCTUATION);
}

int Filter::unknown( const string& source ) const {
    int len = find(source, UNKNOWN);
    return (len >= alphabet(source) && wasEndLine() ) ? len : 0;
}

bool Filter::wasEndLine() const {
    return regex_match(previous, regex(ENDLINE));
}
