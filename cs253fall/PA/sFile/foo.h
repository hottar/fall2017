#ifndef FOO
#define FOO

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

template<typename T>
class Foo{
public:
  Foo(string f_p) : f(f_p){}
  ~Foo() {}
  inline void p() { cout << "me" << endl;}
private:
  string f;
};

#endif
