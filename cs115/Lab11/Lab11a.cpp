/*
Eric Brewer
11/4/08
Rivoire
Lab 11 - array sorting
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CITIES = 50;

int InputCities(string arr[]);
void PrintArray(string arr[], int size);
void BubbleSort(string arr[], int size);
void Swap(string& a, string& b);
void SelectionSort(string arr[], int size);
int FindMinPos(string arr[], int start, int end);
int LinearSearch(string arr[], int size, string searchStr);
int BinarySearch(string arr[], int size, string searchStr);

int main( ) {
  string cities[MAX_CITIES];
  string userChoice;
  int num_cities;
  int pos;
  num_cities = InputCities(cities);
  //BubbleSort(cities, num_cities);
  SelectionSort(cities, num_cities);

  do {
    cout << "Enter a city (q to quit): ";
    getline(cin, userChoice);
    //pos = LinearSearch(cities, num_cities, userChoice);
    pos = BinarySearch(cities, num_cities, userChoice);
    cout << "Position of " << userChoice << " is " << pos <<
      endl;
  } while (userChoice != "q");

  PrintArray(cities, num_cities);
  return 0;
}

int InputCities(string arr[]) {
  ifstream inFile;
  int count = 0;
  string aName;
  inFile.open("lab11a.in");
  getline(inFile, aName);
  while (!inFile.eof() && count < MAX_CITIES) {
    arr[count] = aName;
    count++;
    getline(inFile, aName);
  }
  inFile.close();
  return count;
}

void PrintArray(string arr[], int size)
{
  for (int i = 0; i < size; i++)
    {
      cout << arr[i] << endl;
    }
}

void BubbleSort (string arr[], int size) {
  int num_swaps = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - i; j++) {
      if (arr[j] < arr[j-1]) {
	swap (arr[j], arr[j-1]);
	num_swaps++;
      }
    }
  }
  cout << "BubbleSort: " << num_swaps << " swaps." << endl;
}

void Swap (string& a, string& b) {
  string temp = a;
  a = b;
  b = temp;
}

void SelectionSort(string arr[], int size) {
  int num_swaps = 0;
  int min_pos = 0;
  for (int i = 0; i < size-1; i++) {
    min_pos = FindMinPos(arr, i, size-1);
    if (min_pos != i) {
      Swap(arr[i], arr[min_pos]);
      num_swaps++;
    }
  }
  cout << "SelectionSort: " << num_swaps << " swaps" << endl;
}
// Find array position of minimum element
int FindMinPos(string arr[], int start, int end) {
  string minVal = arr[start];
  int minPos = start;
  for (int i = start+1; i <= end; i++) {
    if (arr[i] < minVal) {
      minVal = arr[i];
      minPos = i;
    }
  }
  return minPos;
}

int LinearSearch(string arr[], int size, string searchStr) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == searchStr) {
      cout << "Linear search: " << i+1 << " comparisons" << endl;
      return i;
    }
  }
  cout << "Linear search: " << size << " comparisons" << endl;
  return -1;
}

int BinarySearch(string arr[], int size, string searchStr) {
  int first=0, last=size-1, middle, pos=-1;
  int compares=0;
  bool found = false;
  while (!found and (first <= last)) {
    middle = (first + last) / 2;
      compares++;
    if (searchStr == arr[middle]) {
      found = true;
      pos = middle;
    }
    else if (searchStr > arr[middle]) {
      first = middle + 1;
      cout << "Compares: " << arr[middle] << endl;
    }
    else {
      last = middle - 1;
      cout << "Compares: " << arr[middle] << endl;
    }
  }
  cout << "Binary search: " << compares << " comparisons" << endl;
  return pos;
}
