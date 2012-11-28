/*
Eric Brewer
10/21/08
Rivoire
Lab 9
*/

#include <iostream>
using namespace std;
const int SIZE = 10;

void InitArray(int array[], int size);
void PrintArray(int array[], int a, int b);
int TotalArray(int array[], int size);

int main () {
  int numbers[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  //InitArray(numbers, SIZE);
  PrintArray(numbers, 0, SIZE);
  PrintArray(numbers, SIZE, 0);
  cout << "Total = " << TotalArray(numbers, SIZE) << endl;
  return 0;
}

void InitArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 1 + 2 * i;
  }
}

void PrintArray(int array[], int a, int b) {
  cout << "Array of numbers:\n";
  if (a <= b) {
    // Loop 1
    for (int i = a; i < b; i++) {
      cout << i << ": " << array[i] << '\t';
    }
  }
  else {
    // Loop 2
    for (int i = a; i > b; i--) {
      cout << i << ": " << array[i-1] << '\t';
    }
  }
  cout << endl;
}

int TotalArray(int array[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += array[i];
  }
  return total; 
}
