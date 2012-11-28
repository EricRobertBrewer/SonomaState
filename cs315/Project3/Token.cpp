#include "Token.hpp"

void Token :: print(){
  cout << "Name: " << _name
       << "\nColon: " << _isAColon
       << "\nTab: " << toInt(_isATab)
       << "\nEnd of line: " << toInt(_eol)
       << "\nEnd of file: " << toInt(_eof)
       << "\nBad Token: " << toInt(_badToken);
}
