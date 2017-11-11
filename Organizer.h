/**
 * @file Organizer.h
 * @author Rick
 * @date Novermber 7, 2017
 * @brief Collects all the files and organize them to proceed desired output.
 * 
 * @see http://www.cs.colostate.edu/~cs253/Fall17/more_assignments/Assignment6.pdf
 */

#ifndef ORGANIZER_H
#define ORGANIZER_H

#include "Reader.h"
#include "KeyGen.h"
#include "Storage.h"
#include "Filter.h"
#include "ExceptionLibrary.h"
#include "TFIDF.h"
#include "Level.h"
#include "LvList.h"

#include <sstream>
using std::istringstream;
using std::stringstream;

#include <iomanip>
using std::setprecision;
using std::fixed;
using std::setw;

#include <iostream>
using std::right;

/**
 * @brief Class that collects and uses all files.
 */
class Organizer {
public:
    /**
     * @brief Constructor of this class.
     * There will be <b>no parameter<b> to construct this object.
     * @warning only use this object in the main function.
     */
    Organizer() {}
    ~Organizer() {}
    
    /**
     * @brief Reads in exception file @p ex_fname and builds a library of exceptions.
     * @note There will be only one library.
     * @param ex_fname file name that contains file of exceptions.
     * @warning do not inlcude string lines those doesn't have excatly two strings.
     */
    string compare( const string& targetfile );
    void readEx(const string& ex_fname);
    void readDoc(const string& fname);
    void readDocInFile(const string& fname);
    void store(const string& source);
    void unambiguous();
    string work(const string& targetname, const string& fname, float low, float high);

private:
    KeyGen gen;
    Reader r;
    Filter f;
    Storage storage;
    ExceptionLibrary exLib;
    TFIDF tfidf;
    Level lv;
    LvList lvlist;
};

#endif
