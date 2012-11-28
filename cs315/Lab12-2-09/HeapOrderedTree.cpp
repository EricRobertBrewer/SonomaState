#include "HeapOrderedTree.hpp"

void HeapOrderedTree :: insert( int v ){
  tail_index++;
  heap[tail_index] = v;
  siftUp();
}  

void HeapOrderedTree :: deleteMin(){
  if( !empty() ){
    swap( heap[1], heap[tail_index] );
    tail_index--;
    siftDown();
  }
}

void HeapOrderedTree :: print(){
  cout << "\nThe Heap - Level-Ordered: ";
  for( int i = 1; i <= tail_index; i++ )
    cout << "\n" << heap[i];
}

void HeapOrderedTree :: swap( int &a, int &b ){
  heap[0] = a;
  a = b;
  b = heap[0];
}

void HeapOrderedTree :: siftUp(){
  int index = tail_index;
  while( index > 1 && heap[index] < heap[index / 2] ){
    swap( heap[index], heap[index / 2] );
    index = index / 2;
  }
}

void HeapOrderedTree :: siftDown(){
  int index = 1;
  while( index < tail_index && heap[index] > heap[index * 2] || heap[index] > heap[index * 2 + 1] ){
    if( heap[index * 2] < heap[index * 2 + 1] ){
      swap( heap[index], heap[index * 2] );
      index = index * 2;
    }
    else{
      swap( heap[index], heap[index * 2 + 1] );
      index = index * 2 + 1;
    }
  }
}
