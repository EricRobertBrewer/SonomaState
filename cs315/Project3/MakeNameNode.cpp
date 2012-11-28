#include "MakeNameNode.hpp"

void MakeNameNode :: runCommand(){
  const char *com = _command.c_str();
  if( executecommand( com ) ){
    cout << "\nCommand of listed MakeNameNode didn't execute correctly:\n";
    print();
    exit(1);
  }
}

void MakeNameNode :: print(){
  cout << "Name: " << _name
       << "\nTimestamp: " << _timeStamp
       << "\nCommand: " << _command;
}
