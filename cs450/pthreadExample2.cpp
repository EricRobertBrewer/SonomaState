#include<pthread.h>
#include<iostream>
#include<stdlib.h>

int x = 0;
int numThreadsTerminated = 0;

pthread_cond_t syncCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t syncMutex = PTHREAD_MUTEX_INITIALIZER;
const int numThreads = 10;

void *someFunction( void * )
{
    for( int i = 0; i < 10; i++ ) {
        // Critical Section begins
        pthread_mutex_lock( &mutex );

        int tmp = x;
        int r =  rand() % 100;
        if( r != 0 )  usleep( r );
        tmp++;
        x = tmp;
        // Critical Section ends
        pthread_mutex_unlock( &mutex );

    }

    // Use the condition variable "syncCond" to count the
    // number of threads that have terminated so far.
    pthread_mutex_lock( &syncMutex );
    numThreadsTerminated++;
    if( numThreadsTerminated == numThreads )
        pthread_cond_signal( &syncCond );
    std::cout << "Thread " << pthread_self() << " terminates. ";
    std::cout << "Number of threads terminated so far: " << numThreadsTerminated << std::endl;
    pthread_mutex_unlock( &syncMutex );
    pthread_exit( NULL );
}

int main()
{
    pthread_t tID[numThreads]; 
  
    for( int i = 0; i < numThreads; i++ )
        pthread_create( tID+i, NULL, someFunction, NULL );

    // wait until all threads terminate.

    pthread_mutex_lock( &syncMutex );
    pthread_cond_wait( &syncCond, &syncMutex ); 
    pthread_mutex_unlock( &syncMutex );
 
    std::cout << "x  = " << x << std::endl;
    pthread_exit( NULL );
}
