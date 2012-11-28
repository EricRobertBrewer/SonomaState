/*
 */

#include <fstream>
#include <iostream>
using namespace std;

void mSort(int a[], int lowIdx, int highIdx);
void merge(int a[], int low1, int high1, int low2, int high2);

int main(){


  return 0;
}

void mSort(int a[], int lowIdx, int highIdx){
  if(lowIdx >= highIdx)
    return ;
  int m = (lowIdx + highIdx) / 2;
  mSort(a, lowIdx, m);
  mSort(a, m + 1, highIdx);
  merge(a, lowIdx, m, m + 1, highIdx);
}

void merge(int a[], int low1, int high1, int low2, int high2){
  int ArrSize = high2 - low1 + 1;
  int Arr[ArrSize];
  int ArrIdx = 0;
  int i = low1;
  int j = low2;
  while(i < high1 && j < high2){
    if(a[i] < a[j]){
      Arr[ArrIdx] = a[i];
      i++;
    }
    else{
      Arr[ArrIdx] = a[j];
      j++;
    }
    ArrIdx++;
  }
  for(int q = 0; q < ArrSize; q++)
    a[low1 + q] = Arr[q];
}
  
