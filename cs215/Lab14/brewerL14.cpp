/*
Eric Brewer
CS215
Lab14 - Inheritance / Polymorphism
*/

#include <iostream>
#include "polygon.h"
#include "LList2.tmp"

char menu ();
Polygon * create (char choice);

int main ()
{
    char option;
    LList2<Polygon*> PLP;
    do
    {
        option = menu ();
        Polygon * pp = create (option);
        if (pp)
	  PLP.InsertLast(pp);
    } while (option != 'Q');

    cout << "List of polygons in order: " << endl;
    for(LList2<Polygon*>::Iterator i = PLP.begin(); i != PLP.end(); ++i)
      cout << **i << endl;
      
    cout << "List of polygons in reverse order: " << endl;
    for(LList2<Polygon*>::Iterator j = PLP.rbegin(); j != PLP.rend(); --j)
      cout << **j << endl;

    cout << "The polygons' areas in order: " << endl;
    for(LList2<Polygon*>::Iterator k = PLP.begin(); k != PLP.end(); ++k)
      cout << (*k)->Area() << endl;

    cout << "The polygons' perimeters in order: " << endl;
    for(LList2<Polygon*>::Iterator l = PLP.begin(); l != PLP.end(); ++l)
      cout << (*l)->Perimeter() << endl;

    return 0;
}

char menu ()
{
    char choice;
    std::cout << "Select one of the following options:\n";
    std::cout << "\ta. Create an Equilateral Triangle\n";
    std::cout << "\tb. Create a Right Triangle\n";
    std::cout << "\tc. Create a Scalene Triangle\n";
    std::cout << "\td. Create a Square\n";
    std::cout << "\te. Create a Rectangle\n";
    std::cout << "\tf. Create a Regular polygon\n";
    std::cout << "\tq. Exit\n";
    std::cin >> choice;
    return toupper(choice);
}

Polygon * create (char choice)
{
  Polygon * pp = NULL;
  switch (choice)
    {
    case 'A':
      {
	int side;
	std::cout << "Enter the length of the side of the "
		  << "equilateral triangle: ";
	std::cin >> side;
	pp = new Equilateral (side);
	break;
      }
    case 'B':
      {
	int side1, side2;
	std::cout << "Enter the length of one leg of the "
		  << "right triangle: ";
	std::cin >> side1;
	std::cout << "Enter the length of the other leg of the "
		  << "right triangle: ";
	std::cin >> side2;
	pp = new Right (side1, side2);
	break;
      }
    case 'C':
      {
	int side1, side2, side3;
	std::cout << "Enter the three sides of your "
		  << "scalene triangle: \nFirst side: ";
	std::cin >> side1;
	std::cout << "Second side: ";
	std::cin >> side2;
	std::cout << "Third side: ";
	std::cin >> side3;
	pp = new Scalene (side1, side2, side3);
	break;
      }
    case 'D':
      {
	int side;
	std::cout << "Enter the side of your square: ";
	std::cin >> side;
	pp = new Square(side);
	break;
      }
    case 'E':
      {
	int side1, side2;
	std::cout << "Enter the sides of your rectangle: "
		  << "\nFirst side: ";
	std::cin >> side1;
	std::cout << "Second side: ";
	std::cin >> side2;
	pp = new Rectangle(side1, side2);
	break;
      }
    case 'F':
      {
	int numSides, length;
	std::cout << "Enter the number of sides of your "
		  << "regular polygon: ";
	std::cin >> numSides;
	std::cout << "Enter the length of each side: ";
	std::cin >> length;
	pp = new Regular(numSides, length);
	break;
      }
    case 'Q':
      {
	std::cout << "Good bye\n";
	break;
      }
    default:
      std::cout << "Invalid option - please try again\n";
    }
  return pp;
}

