#include <iostream>
#include <cmath>
#include "polygon.h"
using namespace std;

Polygon::Polygon ()
{
	side = 0;
}

Polygon::Polygon (const Polygon & p)
{
	side = p.side;
}

Polygon::~Polygon ()
{
}

Polygon & Polygon::operator = (const Polygon & p)
{
	side = p.side;
	return * this;
}

ostream & operator << (ostream & outs, const Polygon & P)
{
	outs << "The area of your " << P.Sides()
	     << " sided polygon is " << P.Area ()
	     << "; its perimeter is " << P.Perimeter() << ".\n";
	return outs;
}

Triangle::Triangle ()
{
	side = 0;
}

Triangle::Triangle (const Triangle & p)
{
	side = p.side;
}

Triangle::~Triangle ()
{
}

Triangle & Triangle::operator = (const Triangle & p)
{
	side = p.side;
	return * this;
}

int Triangle::Sides () const
{
	return 3;
}

Equilateral::Equilateral ()
{
	side = 0;
}

Equilateral::Equilateral (double S)
{
	side = S;
}

Equilateral::~Equilateral ()
{
}

Equilateral::Equilateral (const Equilateral & p)
{
	side = p.side;
}

Equilateral & Equilateral::operator = (const Equilateral & p)
{
	side = p.side;
	return * this;
}

double Equilateral::Area () const
{
	// Calculate and return area here
  double area = 0.0;
  area = side * side * sqrt(3) / 4;

  return area;
}

double Equilateral::Perimeter () const
{
	// Calculate and return perimeter here
  return (3 * side);
}

Right::Right ()
{
	side = side2 = 0;
}

Right::Right (double S1, double S2)
{
	side = S1;
	side2 = S2;
}

Right::~Right ()
{
}

Right::Right (const Right & p)
{
	side = p.side;
	side2 = p.side2;
}

Right & Right::operator = (const Right & p)
{
	side = p.side;
	side2 = p.side2;
	return * this;
}

double Right::Area () const
{
	// Calculate and return area here
  return (side * side2 / 2);
}

double Right::Perimeter () const
{
	// Calculate and return perimeter here
  double hypotenuse = 0.0;
  hypotenuse = sqrt(side * side + side2 * side2);

  return (side + side2 + hypotenuse);
}

Scalene::Scalene ()
{
	side = side2 = side3 = 0;
}

Scalene::Scalene (double S1, double S2, double S3)
{
	side = S1;
	side2 = S2;
	side3 = S3;
}

Scalene::~Scalene ()
{
}

Scalene::Scalene (const Scalene & p)
{
	side = p.side;
	side2 = p.side2;
	side3 = p.side3;
}

Scalene & Scalene::operator = (const Scalene & p)
{
	side = p.side;
	side2 = p.side2;
	side3 = p.side3;
	return * this;
}

double Scalene::Area () const
{
	// Calculate and return area here
  double s = (side + side2 + side3) / 2;
  
  return (sqrt(s * (s - side) * (s - side2) * (s - side3)));
}

double Scalene::Perimeter () const
{
	// Calculate and return perimeter here
  return (side + side2 + side3);
}

Quadrilateral::Quadrilateral ()
{
}

Quadrilateral::Quadrilateral (const Quadrilateral & p)
{
}

Quadrilateral::~Quadrilateral ()
{
}

Quadrilateral & Quadrilateral::operator = (const Quadrilateral & p)
{
	return * this;
}

int Quadrilateral::Sides () const
{
	return 4;
}

Square::Square()
{
  side = 0;
}

Square::Square(double S1)
{
  side = S1;
}

Square::~Square()
{ 
}

Square::Square(const Square & p)
{
  side = p.side;
}

Square & Square::operator = (const Square & p)
{
  side = p.side;
  return * this;
}

double Square::Area() const
{
  return (side * side);
}

double Square::Perimeter() const
{
  return (4 * side);
}

Rectangle::Rectangle()
{
  side = 0;
  side2 = 0;
}

Rectangle::Rectangle(double S1, double S2)
{
  side = S1;
  side2 = S2;
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(const Rectangle & p)
{
  side = p.side;
  side2 = p.side2;
}

Rectangle & Rectangle::operator = (const Rectangle & p)
{
  side = p.side;
  side2 = p.side2;
  return * this;
}
double Rectangle::Area() const
{
  return (side * side2);
}

double Rectangle::Perimeter() const
{
  return (side * 2 + side2 * 2);
}

Regular::Regular ()
{
  num_sides = 3;
  side = 0;
}

Regular::Regular(int N, double S)
{
  num_sides = N;
  side = S;
}

Regular::Regular (const Regular & p)
{
  num_sides = p.num_sides;
  side = p.side;
}

Regular & Regular::operator = (const Regular & p)
{
  num_sides = p.num_sides;
  side = p.side;
  return * this;
}

int Regular::Sides () const
{
  return num_sides;
}

double Regular::Area () const
{
  double a;
  a = (side * side / 4 * num_sides * tan((num_sides-2) * 90 / num_sides));
  return a;
}

double Regular::Perimeter () const
{  
  return num_sides * side;
}

