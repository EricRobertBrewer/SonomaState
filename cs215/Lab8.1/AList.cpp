#include "AList.h"

AList::AList ()
{
	data = new int [MIN_SIZE];
	capacity = MIN_SIZE;
	used = 0;
}

AList::AList (const AList & other)
{
	data = new int [other.capacity];
	for (int i = 0; i < other.used; i++)
		data[i] = other.data[i];
	capacity = other.capacity;
	used = other.used;
}

AList::~AList ()
{
	delete [] data;
}

AList & AList::operator = (const AList & other)
{
	if (this == &other)
		return * this;
	delete [] data;
	data = new int [other.capacity];
	for (int i = 0; i < other.used; i++)
		data[i] = other.data[i];
	capacity = other.capacity;
	used = other.used;
	return * this;
}

bool AList::operator == (const AList & other)
{
	if (used != other.used)
		return false;
	for (int i = 0; i < used; i++)
		if (data[i] != other.data[i])
			return false;
	return true;
}

int AList::Capacity () const
{
	return capacity;
}

int AList::Used () const
{
	return used;
}

ostream & operator << (ostream & outs, const AList & L)
{
	if (L.used)
		outs << L.data[0];
	for (int i = 1; i < L.used; i++)
		outs << ' ' << L.data[i];
	return outs;
}

bool AList::Insert (const int & value)
{
  if (used == capacity)
    {
      capacity *= GROW_FACTOR;
      int * temp = new int[capacity];
      if (temp == NULL)
	return false;
      for (int i = 0; i < used; i++)
	temp[i] = data[i];
      delete [] data;
      data = temp;
    }
  
  bool squeezed = false;
  
  for(int i = 0; i < used && !squeezed; i++)
    if (data[i] > value)
      {
	data[used+1] = 0;
	int temp = data[i];
	data[i] = value;
	for (int j = (i+1); j < (used-i); j++)
	  {
	    int temp2 = data[j];
	    data[j] = temp;
	    temp = temp2;
	  }
	squeezed = true;
      }
  
  if (!squeezed)
    {
      data[used+1] = value;
      squeezed = true;
    }
  used++;
  return squeezed;
}

bool AList::Delete (const int & value)
{
  bool nixxed = false;
  for (int i = 0; i < used && !nixxed; i++)
    if (data[i] == value)
      {
	for(int j = i; j<(used-i-1); j++)
	  data[j+1] = data[j];
	nixxed = true;
      }
  
  used--;
  
  if(used < (SHRINK_LIMIT * capacity))
    {
      int * temp = new int[capacity];
      if (temp == NULL)
	return false;
      for (int i = 0; i < used; i++)
	temp[i] = data[i];
      delete [] data;
      if((SHRINK_FACTOR * capacity) < MIN_SIZE)
	data = new int[MIN_SIZE];
      else
	data = new int[int(SHRINK_FACTOR * capacity)];
      data = temp;
    }

  return nixxed;
}
