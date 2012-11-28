#include"LList.tmp"
#include<iostream>
using namespace std;
#include"CoordPt.h"
#include<string>

int main()
{
  LList <string> L1;
  LList <CoordinatePoint> L2;

  L1.InsertFirst("Hello");
  L2.InsertLast(CoordinatePoint(1,2));
  cout << L1 << endl;
  cout << L2.Size() << endl;

  L1.InsertFirst("Woah");
  cout << L1 << endl;
  L1.InsertLast("K.");
  cout << L1 <<endl;
  L1.DeleteFirst();
  cout << L1 <<endl;
  L1.DeleteLast();
  cout << L1 <<endl;

  L2.InsertLast(CoordinatePoint(3,4));
  cout << L2 <<endl;
  L2.InsertFirst(CoordinatePoint(8,7));
  cout << L2 <<endl;
  L2.DeleteLast();
  cout << L2 <<endl;
  L2.DeleteFirst();
  cout << L2 <<endl;

  LList <string> L3;
  LList <CoordinatePoint> L4;
  
  L3 = L1;
  cout << L3 << endl;
  L4 = L2;
  cout << L4 << endl;

  if(L1 == L3)
    cout << "Right." << endl;
  else
    cout << "Wrong." << endl;

  cout << L3.Size() << endl;
  cout << L4.Size() << endl;

  return 0;
}
