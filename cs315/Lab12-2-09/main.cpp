#include "HeapOrderedTree.hpp"

int main(){
  int array[10] = { 2134, 2346, 6, 62, 865, 123, 34, 689, 127, 876 };
  HeapOrderedTree t;

  for( int i = 0; i < 10; i++)
    t.insert(array[i]);

  t.print();

  return 0;
}
