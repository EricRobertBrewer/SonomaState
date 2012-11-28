#include<pthread.h>
#include<iostream>
#include<stdlib.h>
#include<string>

// This is an example of a program that creates multiple threads of execution. 
// Each thread runs "aFunction" and then terminates. Function, "writeTID", uses
// a mutex to write to the standard-output as "cout" is not thread-safe.


pthread_mutex_t writeMutex = PTHREAD_MUTEX_INITIALIZER;
void writeTID( std::string s, pthread_t tID ) {
    pthread_mutex_lock( &writeMutex );
    std::cout << s << tID << std::endl;
    pthread_mutex_unlock( &writeMutex );
}

void *aFunction( void * )
{
  pthread_detach( pthread_self() );
  sleep( rand() % 5 );
  writeTID( "In ... aFunction = ", pthread_self() );
  return 0;
}

int main( )
{
  pthread_t tID; 
  
  pthread_create( & tID, NULL, aFunction, NULL );
  writeTID( "In main... TID = ", tID );
  pthread_create( & tID, NULL, aFunction, NULL );
  writeTID( "In main... TID = ", tID );
  pthread_create( & tID, NULL, aFunction, NULL );
  writeTID( "In main... TID = ", tID );
  pthread_exit( NULL );  // wait for the active threads to terminate.
}
