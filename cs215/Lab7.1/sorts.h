/*
Eric Brewer
3/11/09
CS215
Lab7
*/

#ifndef SORT_TMP
#define SORT_TMP
// Description : This file contains template implementations of 3
// simple sorts (exchange, insertion, and selection).

template <class T>
void Swap (T & a, T & b)
{
  T t = a;
  a = b;
  b = t;
}
template <class T>
void eSort (T * A, size_t N)
{ 
  // implemetation of exchange (bubble) sort for array (A) of N entries
  // of type T
  bool swapped = true;
  for (int i = 0; swapped && i < N; i++)
    {
      swapped = false;
      for (int j = 1; j < N-i; j++)
	if (A[j-1] > A[j])
	  {
	    Swap (A[j], A[j-1]);
	    swapped = true;
	  }
    }
}
template <class T>
void iSort (T * A, size_t N)
{ 
  // implemetation of insertion sort for array (A) of N entries
  // of type T
  for (int i = 1; i < N; i++)
    for (int j = i; j > 0 && A[j] > A[j-1]; j--)
      Swap (A[j], A[j-1]);
}
template <class T>
void sSort (T * A, size_t N)
{ 
  // implemetation of selection sort for array (A) of N entries
  // of type T
  for (int i = 0; i < N; i++)
    {
      int p = i;
      for (int j = i+1; j < N; j++)
	if (A[p] > A[j])
	  p = j;
      Swap (A[i], A[p]);
    }
}

#endif
