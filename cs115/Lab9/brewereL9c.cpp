/*
Eric Brewer
10/21/08
Rivoire
Lab 9
*/
#include <fstream>
#include <iostream>
using namespace std;
// define const int variables for the number of rows and number of cols
const int rows = 5;
const int cols = 7;

int main () {
  // put declaration of array A after this line
  int A[rows][cols];
  // put array initialization code after this line
  /*  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      A[r][c] = 3 * r + c;
    }
  }
  */
  /*
  for (int r = 0; r < rows; r++) {
    A[r][0] = r;
  }
  for (int c = 0; c < cols; c++) {
    A[0][c] = c;
  }
  for (int r = 1; r < rows; r++) {
    for (int c = 1; c < cols; c++) {
      A[r][c] = A[r-1][c] + A[r][c-1];
    }
  }
  */
  ifstream inFile;
  inFile.open("lab9c.in");
  

  for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
	{
	  inFile >> A[r][c];
	}
    }
  inFile.close();

  ofstream outFile;
  outFile.open("lab9c.log");
  outFile << "The rows of the array:\n";
  // put "by row" output code after this line
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      outFile << A[r][c] << '\t';
    }
    outFile << endl;
  }

  outFile << endl;
  outFile << "The columns of the array:\n";
  // put "by columns” output code after this line
  for (int c = 0; c < cols; c++) {
    for (int r = 0; r < rows; r++) {
      outFile << A[r][c] << '\t';
    }
    outFile << endl;
  }


  return 0;
}
