#include "SuFFix.h"

bool SuFFix::endsWith(const string& source, const string& suffix) const {
  if(source.size() < suffix.size()) return false;
  return equal(suffix.rbegin(), suffix.rend(), source.rbegin());
  // return equal(rbegin(suffix), rend(suffix), rbegin(source));
}

void SuFFix::replaceWith(string& source, const string& suffix, const string& replace){
    source.erase(source.end()-suffix.size(), source.end());
    source.append(replace);
}

bool SuFFix::tryReplaceWith(string& source, const string& suffix, const string& replace){
  if(endsWith(source, suffix)) {
    replaceWith(source, suffix, replace);
    return true;
  }
  return false;
}

bool SuFFix::hasVowel(const string& source) const{
  string tmp(source);
  while(tmp.length() > 0){
    if(isVowel(tmp)) {
      return true;
    }
    tmp.pop_back();
  }
  return false;
}

string SuFFix::fix(string& source) {
  // string tmp(source); // need if const
  if(source.size()>2) {
    step1(source);
    step2(source);
    step3(source);
    step4(source);
    step5(source);
    step6(source);
    step7(source);
    step8(source);
  }
  return source;
}

bool SuFFix::isVowel(const string& source) const {
    switch(source.back()) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            return true;
        case 'y':
            return (source.front()!='y') ? true : !isVowel(preceder(source, "y"));
        default:
            return false;
    }
//   if(source.size() != 0){
//     char last = source.back();
//     if(last == 'a' || last == 'i' || last == 'u' || last == 'e' || last == 'o')
//       return true;
//     else if(last == 'y' && source.front()!='y' && !isVowel(preceder(source, "y")) )
//       return true;
//   }
// 
//   return false;
}

bool SuFFix::isDouble(const string& source) const {
  return endsWith(source, "bb") || endsWith(source, "dd") || endsWith(source, "ff") || endsWith(source, "gg") || endsWith(source, "mm") || endsWith(source, "nn") || endsWith(source, "pp") || endsWith(source, "rr") || endsWith(source, "tt");
}

bool SuFFix::isLiEnd(const string& source) const {
  return endsWith(source, "c") || endsWith(source, "d") || endsWith(source, "e") || endsWith(source, "g") || endsWith(source, "h") || endsWith(source, "k") || endsWith(source, "m") || endsWith(source, "n") || endsWith(source, "r") || endsWith(source, "t");
}

string SuFFix::region1(const string& source) const {
    bool consonant(false), vowel(false);
    for(unsigned int i = 1; i <= source.size(); i++) {
      if( isVowel(source.substr(0,i)) ) vowel=true;
      else if(vowel) consonant = true;
      else vowel=consonant=false;
      if(vowel && consonant) return source.substr(i);
    }
    return string("");
}

string SuFFix::region2(const string& source) const {
    int i = 0, n = 0;
    while ( n < 2 ) {
        do { // find vowel
            if( i >= (int) source.size() ) return "";
            else if( isVowel( string(source.begin(), source.begin()+i) ) ) break;
            i++;
        } while (true);
        if( !isVowel( string(source.begin(), source.begin()+(++i)) ) ) 
            n++;
    }
    return string(source.begin()+i, source.end());

//   return region1(region1(source));
}

string SuFFix::preceder(const string& source, const string& suffix) const {
  return string(source.begin(), source.end()-suffix.size());
}

bool SuFFix::isShortSyllable(const string& source) const {
    if( source.length() < 2 || isVowel(source) || !isVowel(string(source.begin(), source.end()-1)) || isVowel(string(source.begin(), source.end()-2)) ) return false;
    if( endsWith(source, "w") || endsWith(source, "x") || endsWith(source, "y") ) return false;
    return true;
//   if(source.length()==2 && !isVowel(source) && isVowel(string(source.begin(), source.end()-1)) ) return true;
//   else if(source.length() < 3) return false;
//   string vowel(source.begin(), source.end()-1), consonant(source.begin(), source.end()-2);
//   if(endsWith(source, "w") || endsWith(source, "x") || endsWith(source, "y")) return false;
//   return !isVowel(source) && isVowel(vowel) && !isVowel(consonant);
}

bool SuFFix::isShort(const string& source) const {
  return isShortSyllable(source) && region1(source).empty();
}

void SuFFix::step1(string& source) {
  // if the word (i.e. string) begins with an apostrophe, remove the apostrophe.
  if(source.front()=='\'') source.erase(source.begin());

  // Then apply the longest of the following substitutions that apply
  if(tryReplaceWith(source, "\'s\'", ""));
  else if(tryReplaceWith(source, "\'s", ""));
  else if(tryReplaceWith(source, "\'", ""));
}

void SuFFix::step2(string& source) {
  if(endsWith(source, "sses") ) replaceWith(source, "sses", "ss");
  else if(endsWith(source, "ied") || endsWith(source, "ies")) {
    if(preceder(source, "ied").length() > 1) replaceWith(source, "ied", "i");
    else replaceWith(source, "ied", "ie");
  }
  else if(endsWith(source, "us") || endsWith(source, "ss")); // do nothing
  else if(endsWith(source, "s") ) {
    // preceding word part contains a vowel not immediately before the s
    if(hasVowel(preceder(source, "_s")) ) replaceWith(source, "s", "");
  }
}

void SuFFix::step3(string& source) {
    string r1(region1(source)), suffix("");
    
    if(endsWith(source, "eedly")) {
        if( endsWith(r1, "eedly") ) replaceWith(source, "eedly", "ee");
        else return;
    }
    else if(endsWith(source, "eed")) {
        if( endsWith(r1, "eed") ) replaceWith(source, "eed", "ee");
        else return;
    }
    else if(endsWith(source, "ingly") && hasVowel(preceder(source, "ingly")) ) suffix = "ingly";
    else if(endsWith(source, "edly") && hasVowel(preceder(source, "edly")) ) suffix = "edly";
    else if(endsWith(source, "ing") && hasVowel(preceder(source, "ing")) ) suffix = "ing";
    else if(endsWith(source, "ed") && hasVowel(preceder(source, "ed")) ) suffix = "ed";

    if(!suffix.empty()){
      string prec(preceder(source, suffix));
      if(endsWith(prec, "at") || endsWith(prec, "bl") || endsWith(prec, "iz")) replaceWith(source, suffix, "e");
      else if(isDouble(prec)) replaceWith(source, "_"+suffix, "");
      else if(isShort(prec)) replaceWith(source, suffix, "e");
      else replaceWith(source, suffix, "");
    }
}

void SuFFix::step4(string& source) {
  if(endsWith(source, "y") && !isVowel(preceder(source, "y")) && preceder(source, "y").size()>1 ) replaceWith(source, "y", "i");
}

void SuFFix::step5(string& source) {
  if(tryReplaceWith(source, "abli", "able"));
  else if(tryReplaceWith(source, "alism", "al") || tryReplaceWith(source, "aliti", "al") || tryReplaceWith(source, "alli", "al"));
  else if(tryReplaceWith(source, "anci", "ance"));
  else if(tryReplaceWith(source, "ization", "ize") || tryReplaceWith(source, "izer", "ize") );
  else if(tryReplaceWith(source, "ation", "ate") || tryReplaceWith(source, "ational", "ate") || tryReplaceWith(source, "ator", "ate"));
  else if(tryReplaceWith(source, "biliti", "ble") || tryReplaceWith(source, "bli", "ble"));
  else if(tryReplaceWith(source, "enci", "ence"));
  else if(tryReplaceWith(source, "entli", "ent"));
  else if(tryReplaceWith(source, "fulli", "ful") || tryReplaceWith(source, "fulness", "ful") );
  else if(tryReplaceWith(source, "iveness", "ive") || tryReplaceWith(source, "iviti", "ive") );
  else if(tryReplaceWith(source, "lessli", "less"));
  else if(endsWith(source, "li") && isLiEnd(preceder(source, "li")) ) replaceWith(source, "li", "");
  else if(endsWith(source, "ogi") && endsWith(preceder(source, "ogi"), "l") ) replaceWith(source, "ogi", "og");
  else if(tryReplaceWith(source, "ousli", "ous") || tryReplaceWith(source, "ousness", "ous"));
  else if(tryReplaceWith(source, "tional", "tion"));
}

void SuFFix::step6(string& source) {
  string r1(region1(source));
  if(!r1.empty()){
      if( endsWith(source, "ational") ) {
          if(endsWith(r1, "ational")) replaceWith(source, "ational", "ate");
          else return;
      } else if( endsWith(source, "tional") ) {
          if(endsWith(r1, "tional")) replaceWith(source, "tional", "tion");
          else return;
      } else if( endsWith(source, "alize") ) {
          if(endsWith(r1, "alize")) replaceWith(source, "alize", "al");
          else return;
      } else if( endsWith(source, "icate") || endsWith(source, "iciti") ) {
          if( endsWith(r1, "icate") || endsWith(r1, "iciti") ) replaceWith(source, "icate", "ic");              
          else return;
      } else if( endsWith(source, "ical") ) {
          if(endsWith(r1, "ical")) replaceWith(source, "ical", "ic");
          else return;
      } else if( endsWith(source, "ness") ) {
          if(endsWith(r1, "ness") ) replaceWith(source, "ness", "");
          else return;
      } else if( endsWith(source, "ful") ) {
          if(endsWith(r1, "ful")) replaceWith(source, "ful", "");
          else return;
      } else if( endsWith(source, "ative") ) {
          if(endsWith(region2(source), "ative")) replaceWith(source, "ative", "");
          else return;
      } 
  }
}

void SuFFix::step7(string& source) {
  string r2(region2(source));
  if(!r2.empty()){
      if( endsWith(source, "ement") ) { 
          if(endsWith(r2, "ement")) 
              replaceWith(source, "ement", ""); // 5 letters
          else return;
      } else if( endsWith(source, "able") || endsWith(source, "ance") || endsWith(source, "ence") || endsWith(source, "ible") || endsWith(source, "ment") ) { 
          if( endsWith(r2, "able") || endsWith(r2, "ance") || endsWith(r2, "ence") || endsWith(r2, "ible") || endsWith(r2, "ment")  ) 
              replaceWith(source, "able", ""); // 4 letters
          else return;
      } else if( endsWith(source, "ant") || endsWith(source, "ate") || endsWith(source, "ent") || endsWith(source, "ism") || endsWith(source, "iti") || endsWith(source, "ive") || endsWith(source, "ize") || endsWith(source, "ous") ) { 
          if( endsWith(r2, "ant") || endsWith(r2, "ate") || endsWith(r2, "ent") || endsWith(r2, "ism") || endsWith(r2, "iti") || endsWith(r2, "ive") || endsWith(r2, "ize") || endsWith(r2, "ous")  ) 
              replaceWith(source, "ant", ""); // 3 letters
          else return;
      } else if( endsWith(source, "al") || endsWith(source, "er") || endsWith(source, "ic") ) { 
          if( endsWith(r2, "al") || endsWith(r2, "er") || endsWith(r2, "ic")  ) 
              replaceWith(source, "al", ""); // 2 letters
          else return;
      } else if( endsWith(source, "ion") ) { 
          if( endsWith(r2, "ion") && (preceder(source, "ion").back()=='s' || preceder(source, "ion").back()=='t')  ) 
              replaceWith(source, "ion", "");
          else return;
      } 
  }
}

void SuFFix::step8(string& source) {
  string r1(region1(source)), r2(region2(source)), prec(preceder(source, "e"));
  if( endsWith(r2, "e") || (endsWith(r1, "e") && !isShortSyllable(prec)) )
    replaceWith(source, "e", "");
  else if( endsWith(r2, "l") && endsWith(prec, "l") )
    replaceWith(source, "l", "");
}
