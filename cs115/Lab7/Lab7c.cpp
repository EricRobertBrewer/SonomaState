/*
Eric Brewer
10/7/08
Rivoire
Lab7c
*/

#include <iostream>
using namespace std;

char Menu();
void SquareArea();
void CircleArea();
void CubeVolume();
void RectArea();

const float pi = 3.1415;

int main()
{
  char choice;
  do
    {
      choice = Menu();
      if (choice == 'a')
	{
	  SquareArea();
	}
      else if (choice == 'b')
	{
	  CircleArea();
	}
      else if (choice == 'c')
	{
	  CubeVolume();
	}
      else if (choice == 'd')
	{
	  RectArea();
	}
    } while (choice != 'q');
  
  cout << "Goodbye!\n";

  return 0;
}
  
char Menu()
{
  cout << "Would you like to:\n";
  cout << "\ta. Calculate the area of a square?\n";
  cout << "\tb. Calculate the area of a circle?\n";
  cout << "\tc. Calculate the volume of a cube?\n";
  cout << "\td. Calculate the area of a rectangle?\n";
  cout << "\tq. Quit.\n";

  char charmander;
  cin >> charmander;
  return charmander;
}

void SquareArea()
{
  cout << "Enter side length: ";
  float numSq = 0;
  cin >> numSq;
  cout << endl;
  numSq = numSq * numSq;
  cout << "Your square has area " << numSq << endl;
}

void CircleArea() 
{
  cout << "Enter radius length: ";
  float numCir = 0;
  cin >> numCir;
  cout << endl;
  numCir = numCir * numCir * pi;
  cout << "Your circle has area " << numCir << endl;
}

void CubeVolume() 
{
  cout << "Enter edge length: ";
  float numCube = 0;
  cin >> numCube;
  cout << endl;
  numCube = numCube * numCube * numCube;
  cout << "Your cube has volume " << numCube << endl;
}

void RectArea() 
{
  cout << "Enter one side length: ";
  float numRect1 = 0;
  cin >> numRect1;
  cout << "Enter the other side length: ";
  float numRect2 = 0;
  cin >> numRect2;
  numRect1 = numRect1 * numRect2;
  cout << "Your rectangle has area " << numRect1 << endl;
}
