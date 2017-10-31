#ifndef STRREADER_TEMP
#define STRREADER_TEMP

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

class sReader{
public:
  inline sReader(const string& fname_p) : fname(fname_p), file(fname) {if(!file) throw string("READ_ERR: File "+fname+" cannot be read!");}
  inline ~sReader() {if(file) file.close();}
  inline sReader(const sReader& other) : fname(other.fname), file(ifstream(fname)) {}
  inline bool hasNext() {return file.peek() != EOF;}
  inline string next() {string tmp; file >> tmp; return tmp;}
  inline string prev() {file.unget(); string tmp; file >> tmp; return tmp;}

private:
  string fname;
  ifstream file;
};

#endif
