#include "Cell.hpp"

Cell :: Cell(){
  row = 0;
  col = 0;
}

Cell :: Cell(int R, int C){
  row = R;
  col = C;
}

Cell :: Cell(const Cell & other){
  row = other.row;
  col = other.col;
}

Cell & Cell :: operator = (const Cell & other){
  row = other.row;
  col = other.col;
  return *this;
}
