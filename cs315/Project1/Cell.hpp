#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
using namespace std;

class Cell{
public:
  Cell();
  Cell(int R, int C);
  Cell(const Cell & other);
  Cell & operator = (const Cell & other);
  
  int row;
  int col;
};

#endif
