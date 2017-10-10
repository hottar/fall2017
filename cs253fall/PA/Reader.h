#ifndef STRREADER_H
#define STRREADER_H

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

class Reader{
public:
  inline Reader(const string& fname_p) : fname(fname_p), file(fname) {if(!file) throw string("READ_ERR: File "+fname+" cannot be read!");}
  inline Reader() : fname("") {}
  inline ~Reader() {if(file) file.close();}
  inline Reader(const Reader& other) : fname(other.fname), file(ifstream(fname)) {}
  inline void read(const string& fname_p) {fname = fname_p; file=ifstream(fname); if(!file) throw string("READ_ERR: File "+fname+" cannot be read!");}
  inline bool hasNext() {return file.peek() != EOF;}
  inline string next() {string tmp; file >> tmp; return tmp;}
  inline string prev() {file.unget(); string tmp; file >> tmp; return tmp;}

private:
  string fname;
  ifstream file;
};

#endif
