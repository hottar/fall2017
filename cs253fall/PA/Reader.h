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
  inline void read(const string& fname_p) {if(file) file.close(); fname = fname_p; file=ifstream(fname); if(!file) throw string("READ_ERR: File "+fname+" cannot be read!");}
  inline bool hasNext() {return file.peek() != EOF;}
  inline string next() {old = file.tellg(); string tmp; file >> tmp; return tmp;}
  inline string prev() {file.seekg(old); string tmp; file >> tmp; return tmp;} //file.unget();
  inline string nextLine() { old = file.tellg(); string line; getline(file, line); return line; }

private:
  string fname;
  ifstream file;
  ifstream::pos_type old;
};

#endif
