/*
Eric Brewer
9/16/09
CS315
Lab3 - Find the common elements of two sorted arrays
*/

#include <fstream>
#include <iostream>
using namespace std;

int commonElementsIteratively(int a[], int n, int b[], int m);
int commonElementsRecursively(int a[], int n, int b[], int m);

int main(){
  int array1[1000000];
  int array2[1000000];
  int size1 = 0;
  int size2 = 0;
  int dud = 0;
 
  ifstream fin;
  fin.open("subset_a.input");
  while(!fin.eof()){
    fin >> array1[size1];
    size1++;
  }
  size1--;
  fin.close();

  fin.open("subset_b.input");
  while(!fin.eof()){
    fin >> array2[size2];
    size2++;
  }
  size2--;
  fin.close();

  /*
  cout << size1 << " " << size2 << endl;
  for(int i = 0; i < 5; i++)
    cout << array1[i] << ' ';
  cout << endl;
  for(int i = 0; i < 5; i++)
    cout << array2[i] << ' ';
  cout << endl;
  cout << array1[size1-1] << ' ' << array2[size2-1] << endl;
  */

  cout << "Common elements iteratively: " 
       << commonElementsIteratively(array1, size1, array2, size2) << endl;

  size1 = 0;
  fin.open("subset_rec_a.input");
  while(!fin.eof()){
    fin >> array1[size1];
    size1++;
  }
  size1--;
  fin.close();

  size2 = 0;
  fin.open("subset_rec_b.input");
  while(!fin.eof()){
    fin >> array2[size2];
    size2++;
  }
  size2--;
  fin.close();
  
  //cout << size1 << ' ' << size2 << endl;

  cout << "Common elements recursively: "
       << commonElementsRecursively(array1, size1, array2, size2) << endl;
  
  return 0;
}

int commonElementsIteratively(int a[], int n, int b[], int m){
  int itr1 = 0;
  int itr2 = 0;
  int commonNums = 0;
  while(itr1 < n && itr2 < m){
    if(a[itr1] == b[itr2])
      commonNums++;
    if(a[itr1] < b[itr2])
      itr1++;
    else
      itr2++;
  }

  return commonNums;
}

int commonElementsRecursively(int a[], int n, int b[], int m){
  if (!n)
    return 0;
  if (!m)
    return 0;
  if(a[n] == b[m])
    return 1 + commonElementsRecursively(a, n-1, b, m-1);
  if(a[n] < b[m])
    return commonElementsRecursively(a, n, b, m-1);
  if(a[n] > b[m])
    return commonElementsRecursively(a, n-1, b, m);
}
