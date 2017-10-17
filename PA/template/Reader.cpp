#include "Reader.h"

template <typename T>
bool Reader<T>::hasNext(){
  ifstream::pos_type tmpLoc = file.tellg();
  bool retbool(true);
  T tmp;
  file >> tmp;
  if(file.eof()) retbool = false;
  else if(file.fail()) throw string("File contains value of non-" + string(typeid(T).name()) + "!");
  file.seekg(tmpLoc);
  return retbool;
}

template <typename T>
T Reader<T>::next(){
  T tmp;
  file >> tmp;
  return tmp;
}
