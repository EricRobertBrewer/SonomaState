#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
using namespace std;

class Polygon
{    
    public:
        Polygon ();
        Polygon (const Polygon & p);
        ~Polygon ();
        Polygon & operator = (const Polygon & p);
        virtual int Sides () const { return 0; }
        virtual double Area () const { return 0; }
        virtual double Perimeter () const { return 0; }
        friend ostream & operator << (ostream & outs, const Polygon & P);
    protected:
        double side;
    private:
};

class Triangle : public Polygon
{
    public:
        Triangle ();
        Triangle (const Triangle & p);
        ~Triangle ();
        Triangle & operator = (const Triangle & p);
        int Sides () const;
    private:
};

class Equilateral : public Triangle
{
    public:
        Equilateral ();
        Equilateral (double S);
        ~Equilateral ();
        Equilateral (const Equilateral & p);
        Equilateral & operator = (const Equilateral & p);
        double Area () const;
        double Perimeter () const;
    private:
};

class Right : public Triangle
{
    public:
        Right ();
        Right (double S1, double S2);
        ~Right ();
        Right (const Right & p);
        Right & operator = (const Right & p);
        double Area () const;
        double Perimeter () const;
    private:
        double side2;
};

class Scalene : public Triangle
{
    public:
        Scalene ();
        Scalene (double S1, double S2, double S3);
        ~Scalene ();
        Scalene (const Scalene & p);
        Scalene & operator = (const Scalene & p);
        double Area () const;
        double Perimeter () const;
    private:
        double side2, side3;
};

class Quadrilateral : public Polygon
{
    public:
        Quadrilateral ();
        Quadrilateral (const Quadrilateral & p);
        ~Quadrilateral ();
        Quadrilateral & operator = (const Quadrilateral & p);
        int Sides () const;
    private:
};

// Add Square and Rectangle classes here
class Square : public Quadrilateral
{
 public:
  Square();
  Square(double S1);
  ~Square();
  Square(const Square & p);
  Square & operator = (const Square & p);
  double Area() const;
  double Perimeter() const;
 public:
};

class Rectangle : public Quadrilateral
{
 public:
  Rectangle();
  Rectangle(double S1, double S2);
  ~Rectangle();
  Rectangle(const Rectangle & p);
  Rectangle & operator = (const Rectangle & p);
  double Area() const;
  double Perimeter() const;
 public:
  double side2;
};

class Regular : public Polygon
{
    public:
        Regular ();
	Regular(int N, double S);
        Regular (const Regular & p);
        ~Regular ();
        Regular & operator = (const Regular & p);
        int Sides () const;
        double Area () const;
        double Perimeter () const;
    private:
        int num_sides;
};

#endif
