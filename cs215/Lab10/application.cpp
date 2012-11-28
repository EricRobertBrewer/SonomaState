#include<iostream>
using namespace std;
#include"LList2.tmp"

void Print(const int & value);

int main()
{
  LList2 <int> L;

  L.InsertFirst(1);
  cout << '1' << endl;
  L.InsertLast(3);
  cout << '1' << endl;
  L.InsertLast(4);
  cout << '1' << endl;
  L.InsertFirst(2);
  cout << '1' << endl;
  L.DeleteFirst();
  cout << '1' << endl;
  L.DeleteLast();
  cout << '1' << endl;
  L.DeleteFirst();
  cout << '1' << endl;
  L.DeleteFirst();
  cout << '1' << endl;
  L.DeleteLast();
  cout << '1' << endl;
  L.DeleteFirst();
  cout << '1' << endl;
  L.InsertLast(6);
  L.DeleteLast();
  L.InsertLast(1);
  L.InsertLast(2);
  L.InsertLast(3);
  L.InsertLast(4);
  L.InsertLast(5);
  L.InsertLast(6);
  L.InsertLast(7);
  L.InsertLast(8);
  L.InsertFirst(0);

  L.Forward(Print);
  L.Backward(Print);

  return 0;
}

void Print(const int & value)
{
  cout << "The value in the list is " << value << endl;
}
