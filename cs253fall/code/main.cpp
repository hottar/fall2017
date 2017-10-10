#include "HashTable.h"
#include "Reader.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv){
  cout << int('a') << endl;
  cout << int('A') << endl;
  unsigned char c = 'A';
  cout << int(c) << endl;
  unsigned char i = '1';
  cout << int(i) << endl;
  cout << int('0') << endl;
  cout << "1" << endl;
  HashTable h = HashTable(98, 8);
  cout << "2" << endl;
  HashTable h2(h);
  cout << "tmp" << endl;
  HashTable* tmp = new HashTable(90,9);
  cout << "4" << endl;
  HashTable h4(90,6);
  cout << "3" << endl;
  HashTable h3;
  h3 = h2;
  h.Add("What");
  h.Resize(99*8);
  h.Add("Why");
  return 0;
}
