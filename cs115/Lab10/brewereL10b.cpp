/*
Eric Brewer
10/28/08
Rivoire
Lab 10
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#define MAX 20
struct student {
  string name;
  int score1, score2, score3;
  float average;
};
int input (ifstream& ins, student rs[]);
void sort (int num, student rs[]);
float calculate (int num, student rs[]);
void output (int num, student rs[]);
int main () {
  ifstream data;
  student roster [MAX];
  int count = 0;
  float totaverage = 0;
  data.open ("lab10b.in");
  count = input (data, roster);
  sort (count, roster);
  totaverage = calculate (count, roster);
  output (count, roster);
  cout << setw(12) << "Average:" << setw(8) << totaverage
       << endl;
  return 0;
}
int input (ifstream& ins, student rs[]) {
  int number = 0;
  string aName;
  ins >> aName;
  while (!ins.eof() && number < MAX) {
    rs[number].name = aName;
    ins >> rs[number].score1 >> rs[number].score2
	>> rs[number].score3;
    rs[number].average = (rs[number].score1 + rs[number].score2
			  + rs[number].score3) / 3.0;
    number++;
    ins >> aName;
  }
  return number;
}
void swap (student & a, student & b) {
  student t = a;
  a = b;
  b = t;
}
void sort (int num, student rs[]) {
  bool sw = true;
  for (int i = 0; i < num && sw; i++) {
    sw = false;
    for (int j = 1; j < num - i; j++) {
      if (rs[j].name < rs[j-1].name) {
	swap (rs[j], rs[j-1]);
	sw = true;
      }
    }
  }
}
float calculate (int num, student rs[]) {
  float total, average;
  total = 0;
  for (int i=0; i < num; i++)
    {
      total += rs[i].average;
    }
  average = total / num;
  return average;
}
void output (int num, student rs[]) {
  for (int i=0; i < num; i++)
    {
      cout << rs[i].name << '\t' << rs[i].score1 << '\t' <<  rs[i].score2 << '\t' 
	   << rs[i].score3 << '\t' << rs[i].average << endl;
    }
}
