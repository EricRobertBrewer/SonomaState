#ifndef HEAP_ORDERED_TREE_HPP
#define HEAP_ORDERED_TREE_HPP

#include <iostream>
using namespace std;

class HeapOrderedTree{

public:  
  HeapOrderedTree() { create(); }
  
  void create() { tail_index = 0; }
  void insert( int v );
  int findMin() { return heap[1]; }
  void deleteMin();
  bool empty() { return !tail_index; }
  void print();

private:
  void swap( int &a, int &b );
  void siftUp();
  void siftDown();

  int tail_index;
  int heap[500000];
};

#endif
