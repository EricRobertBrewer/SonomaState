#include "BoundedBuffer.hpp"

BoundedBuffer::BoundedBuffer( int limit ): _limit( limit ) 
{
    queue.clear();
    pthread_mutex_init( &mutex, NULL );
    pthread_cond_init( &okToProduce, NULL );
    pthread_cond_init( &okToConsume, NULL );
}

void BoundedBuffer::acceptRecord( void *record ) 
{
    int status = pthread_mutex_lock( &mutex );
    assert( status == 0 );
    while( queue.size() == _limit ) {
        status = pthread_cond_wait( &okToProduce, &mutex );
        assert( status == 0 ); 
    }
    queue.push_back( record );
    status = pthread_cond_signal( &okToConsume );
    assert( status == 0 ); 
    status = pthread_mutex_unlock( &mutex );
    assert( status == 0 ); 
}

void *BoundedBuffer::getRecord() 
{
    int status = pthread_mutex_lock( &mutex );
    assert( status == 0 );
    while( queue.size() == 0 ) {
        status = pthread_cond_wait( &okToConsume, &mutex );
        assert( status == 0 ); 
    }
    void *record = queue.front();
    queue.pop_front();
    status = pthread_cond_signal( &okToProduce );
    assert( status == 0 ); 
    status = pthread_mutex_unlock( &mutex );
    assert( status == 0 );
    return record;
}
