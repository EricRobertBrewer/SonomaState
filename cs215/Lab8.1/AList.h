#ifndef ALIST_H
#define ALIST_H

#define MIN_SIZE 10
#define GROW_FACTOR 1.25
#define SHRINK_LIMIT 0.5
#define SHRINK_FACTOR 0.8

#include <cstdlib>
#include <iostream>
using namespace std;

class AList
{
    public:
	AList ();
	AList (const AList & other);
	~AList ();
	AList & operator = (const AList & other);
	bool operator == (const AList & other);
	int Capacity () const;
	int Used () const;
	friend ostream & operator << (ostream & outs, const AList & L);
	bool Insert (const int & value);
	bool Delete (const int & value);
    private:
	int * data;
	int capacity;
	int used;
};

#endif
