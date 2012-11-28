/*
Eric Brewer
2/11/09
CS215
Lab3 - strcmp function
*/

#include<iostream>
#include<cstring>

using namespace std;

int main(){
  char * s1;
  char * s2;

  s1 = new char[6];
  strcpy(s1, "Apple");
  s2 = new char[7];
  strcpy(s2, "Apples");
  cout << s1 << endl;
  cout << s2 << endl;
  cout << strcmp(s1, s2) << endl;
  cout << strcmp(s2, s1) << endl;
  
  return 0;
}
