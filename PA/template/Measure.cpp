#include "Measure.h"

const string ERR_FILE = "Invalid file!";
const string ERR_NUMVAR = "Need 1 or more Numbers!";
const string ERR_VAR = "File contains value of non-number!";
const string ERR_MIN = "Value is too small!";
const string ERR_MAX = "Value is too large!";

void Measure::read(string fname){
  ifstream reader(fname);//.c_str()
  if(!reader) errmsg(ERR_FILE);
  int var, cnt_p(0);
  while(reader){
    reader >> var;
    if(reader.eof()){
      if(cnt_p==0) errmsg(ERR_NUMVAR);
      else break;
    }
    else if(reader.fail()) errmsg(ERR_VAR);
    add(var);
    ++cnt_p;
  }

  output(intcnt);
}

void Measure::add(int var){
  if(var < min) errmsg(ERR_MIN);
  else if(var > max) errmsg(ERR_MAX);

  ++intcnt[var];
}
