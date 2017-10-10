#ifndef READER_H
#define READER_H

#include <HashTable.h>

class Reader {
public:
  Reader(const string& input);

  inline unsigned int Count() const {return ht.Count();}
  unsigned int Size() {return ht.Size();}
  unsigned int Resize(unsigned int resize) {return ht.Resize(resize);}
  int Compare(string comp_string);

protected:
  HashTable ht;
};

#endif // READER_h
