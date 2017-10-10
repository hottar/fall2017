#include <HashTable.h>


HashTable::HashTable(const HashTable& src) : size(src.size), factor(src.factor), counter(src.counter)
{
  cout << "Prim" << endl;
  table = new string[size];
  for(unsigned int index = 0; index < size; index++) {
    table[index] = src.table[index];
  }
}

HashTable::~HashTable()
{
  delete [] table;
  table = 0;
  size = 0;
}

HashTable& HashTable::operator = (const HashTable& src)
{
  cout << "=" << endl;
  table = new string[size];
  for(unsigned int index = 0; index < size; index++) {
    table[index] = src.table[index];
  }
  size = src.size;
  factor = src.factor;
  return *this;
}

unsigned int HashTable::Resize(unsigned int new_size)
{
  string* temp = table;
  table = new string[new_size];
  for(unsigned int index = 0; index < new_size; index++) {
    table[index] = temp[index];
  }
  delete [] temp;
  size = new_size;
  return size;
}

int HashTable::Hash(const string& str) const
{
  int code = 1;
  for(unsigned int index = 0; index < str.length(); index++) {
    code *= CharCode(str.at(index));
  }
  return code % size;
}

bool HashTable::Contains(const string& str)
{
  int index = Hash(str);
  return (0 == str.compare(table[index]));
}

bool HashTable::Add(const string& str)
{
  int index = Hash(str);
  if (table[index].empty()) {
    table[index] = str;
    counter++;
    return false;
  }
  else if (0 == str.compare(table[index])) {
    return false;
  }
  else {
    Resize(size * factor);
    Add(str);
    return true;
  }
}
