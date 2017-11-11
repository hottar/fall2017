/**
 * @file LvList.h
 * @brief Stores the list of names of the files and their levels.
 * @author Rick
 */

#ifndef LVLIST_H
#define LVLIST_H

#include <map>
using std::map;
using std::pair;

using f = map<string, float>;
using fconst_it = f::const_iterator;

/**
 * @brief Class of Reading Level List. The map will only store those are within the range of limitation.
 */
class LvList {
public:
    LvList() : low(0.0), high(0.0) {}
    ~LvList() {clear();}
    inline void clear() { container.clear(); }
    inline fconst_it begin() const { return container.begin(); }
    inline fconst_it end() const { return container.end(); }
    inline void setBounds( float l, float h ) { low = l; high = h; }
    inline void store( const string& fname, float level ) { if(level <= high || level >= low) container.insert({fname, level}); }
private:
    float low;
    float high;
    f container;
};

#endif
