
#ifndef __BoundedBuffer
#define __BoundedBuffer

#include<assert.h>
#include<pthread.h>
#include<deque>

class BoundedBuffer {
    enum { MAX_BUF_SIZE = 50 };
    
public:
    BoundedBuffer( int limit =  MAX_BUF_SIZE );
    void acceptRecord( void *record );
    void *getRecord();
    
private:
    unsigned short _limit;
    pthread_mutex_t mutex;
    pthread_cond_t okToProduce, okToConsume;
    std::deque< void * > queue;
};

#endif //  __BoundedBuffer
