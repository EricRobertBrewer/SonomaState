/*
BoundedBuffer.hpp
Eric Brewer
11/2/10
Kooshesh
CS450 - Operating Systems
Chat Program: BoundedBuffer template class header and 
  implementation - 
*/

#ifndef _BOUNDEDBUFFER_HPP
#define _BOUNDEDBUFFER_HPP

#define MAXIMUM_BUFFER_SIZE 40

#include <vector>
using namespace std;
#include <pthread.h>
#include <assert.h>

template <typename T>
class BoundedBuffer{

public:
  BoundedBuffer();
  void addItem( T item );
  T removeItem();

private:
  int _limit;
  vector<T> buffer;
  pthread_mutex_t mutex;
  pthread_cond_t okToAdd;
  pthread_cond_t okToRemove;
};

template <typename T>
BoundedBuffer<T>::BoundedBuffer(){

  _limit = MAXIMUM_BUFFER_SIZE;
  buffer.clear();
  pthread_mutex_init( &mutex, NULL );
  pthread_cond_init( &okToAdd, NULL );
  pthread_cond_init( &okToRemove, NULL );
}

template <typename T>
void BoundedBuffer<T>::addItem( T item ){
  int status = pthread_mutex_lock( &mutex );

  assert( status == 0 );
  while( buffer.size() == _limit ){
    status = pthread_cond_wait( &okToAdd, &mutex );
    assert( status == 0 );
  }
  buffer.push_back( item );
  status = pthread_cond_signal( &okToRemove );
  assert( status == 0 );
  status = pthread_mutex_unlock( &mutex );
  assert( status == 0 );
}

template <typename T>
T BoundedBuffer<T>::removeItem(){  
  int status = pthread_mutex_lock( &mutex );

  assert( status == 0 );
  while( buffer.size() == 0 ){
    status = pthread_cond_wait( &okToRemove, &mutex );
    assert( status == 0 );
  }
  T item = buffer.back();
  buffer.pop_back();
  status = pthread_cond_signal( &okToAdd );
  assert( status == 0 );
  status = pthread_mutex_unlock( &mutex );
  assert( status == 0 );
  return item;
}

#endif
