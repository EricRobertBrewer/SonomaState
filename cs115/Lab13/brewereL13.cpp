#include   <cstring>
#include   <iostream>
#include   <fstream>
#include   <cstdlib>
using namespace std;
#define SIZE 100
int readWords (istream & ins, char * W []);
void sortWords (char * W [], int N);
void writeWords (char * W [], int N);
void toupper (char * W);
void swap (char *& a, char *& b);
int FindMaxPos(char * arr[], int start, int end);
int main (int argc, char * argv [])
{
  if (argc < 2)
    {
      cerr << "Syntax: " << argv[0] << " <filename>\n";
      exit (1);
    }
  ifstream input (argv[1]);
  if (input.fail())
    {
      cerr << "File " << argv[1] << " not found\n";
      exit (2);
    }
  char * words [SIZE];
  int count = readWords (input, words);
  input.close();
  sortWords (words, count);
  writeWords (words, count);
  for (int w = 0; w < count; w++)
    toupper (words[w]);
         sortWords (words, count);
         writeWords (words, count);
  for (int w = 0; w < count; w++)
    delete [] words[w];
  return 0;
}
int readWords (istream & ins, char * W [])
{
  int word_count = 0;
  char buf[1024];
  while(!ins.eof()) {
    ins >> buf;
    W[word_count] = new char[strlen(buf) + 1];
    strcpy(W[word_count], buf);
    word_count++;
      }

  return (word_count - 1);
}
void sortWords (char * W [], int N)
{
  //int num_swaps = 0;
    int max_pos = 0;
    for (int i = 0; i < N-1; i++) {
      max_pos = FindMaxPos(W, i, N-1);
      if (max_pos != i) {
	swap(W[i], W[max_pos]);
	//num_swaps++;
      }
    }
    // cout << "SelectionSort: " << num_swaps << " swaps" << endl;
}
void writeWords (char * W [], int N)
{
  for(int i = 0; i < N; i++) {
    cout << W[i] << "\t";
  }
  cout << endl;
}
void toupper (char * W)
{
  for (int i = 0; i < SIZE; i++) {
    if (isalpha(W[i]))
      W[i] = toupper(W[i]);
  }
}
void swap (char *& a, char *& b)
{
  char * t = a;
  a = b;
  b = t;
}
int FindMaxPos(char * arr[], int start, int end) {
  char * maxVal = arr[start];
  int maxPos = start;
  for (int i = start+1; i <= end; i++) {
    if (strcmp(arr[i], maxVal) > 0) {
      maxVal = arr[i];
      maxPos = i;
    }
  }
  return maxPos;
}
