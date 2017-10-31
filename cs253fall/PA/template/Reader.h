#ifndef READER_TEMP
#define READER_TEMP

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <typeinfo>

template <typename T>
class Reader{
public:
  inline Reader(const string& fname_p) : fname(fname_p), file(fname) {if(!file) throw string("READ_ERR: File "+fname+" cannot be read!");}
  inline ~Reader() {if(file) file.close();}
  inline Reader(const Reader<T>& other) : fname(other.fname), file(other.file) {}
  bool hasNext(){
    ifstream::pos_type tmpLoc = file.tellg();
    bool retbool(true);
    T tmp;
    file >> tmp;
    if(file.eof()) retbool = false;
    else if(file.fail()) throw string("File contains value of non-" + string(typeid(T).name()) + "!");
    file.seekg(tmpLoc);
    return retbool;
  }
  T next() {
    T tmp;
    file >> tmp;
    return tmp;
  }

private:
  string fname;
  ifstream file;
};

#endif
