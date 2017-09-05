#ifndef READER_TEMP
#define READER_TEMP

#include <string>
using std::string;
#include <fstream>
using std::ifstream;

template <typename T>
class Reader{
public:
  inline Reader(const string& fname_p) : fname(fname_p), file(fname) {if(!file) throw string("READ_ERR: File "+fname+" cannot be read!");}
  inline ~Reader() {if(file) file.close();}
  inline Reader(Reader<T>& other) : fname(other.fname), file(other.file) {}
  bool hasNext() const;
  T& next();
private:
  string fname;
  ifstream file;
};

#endif
