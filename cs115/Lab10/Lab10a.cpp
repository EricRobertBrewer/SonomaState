/*
Eric Brewer
10/28/08
Rivoire
Lab 10
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
const int SIZE = 50;
void Swap(int& a, int& b);
void InitArray(int array[], int size);
void PrintArray(int array[], int a, int b);

int main () {
  int numbers[SIZE];
  int last_elt = SIZE - 1;
  InitArray(numbers, SIZE);
  PrintArray(numbers, 0, SIZE);
  // Loop A
  for (int k=0; k < SIZE; k++) {
    for (int j=1; j < SIZE; j++) {
      if (numbers[j] < numbers[j-1]) {
	Swap(numbers[j], numbers[j-1]);
      }
    }
  }
  // Call 2
  PrintArray(numbers, 0, SIZE);
  return 0;
}
void InitArray(int array[], int size) {
  srand (time (NULL));
  for (int i = 0; i < size; i++) {
    array[i] = 1 + rand() % 100;
  }
}
void PrintArray(int array[], int a, int b) {
  cout << "Array of numbers:\n";
  if (a <= b) {
    for (int i = a; i < b; i++) {
      cout << i << ": " << array[i] << '\t';
    }
  }
  else {
    for (int i = a-1; i >= b; i--) {
      cout << i << ": " << array[i] << '\t';
    }
  }
  cout << endl;
}
void Swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}
