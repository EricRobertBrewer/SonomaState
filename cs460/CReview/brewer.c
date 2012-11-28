/*
brewer.c
Eric Brewer
9/11/10
Tia Watts
CReview - Implementation of Exchange (Bubble) sort
 and Quick sort in C.
*/
#include <stdio.h>
#include <stdlib.h>

void ExchangeSort( int A[], int N );
void Swap( int *a, int *b );
void QuickSort( int B[], int N );
/*
The above is what is called in the main function.
The below is the actual recursive sort.
QuickSort sparks QSort.
*/
void QSort( int B[], int indexLow, int indexHigh );
void PrintArray( int A[], int N );

int main( int argc, char *argv[] ){

  if( argc < 2 ){
    printf( "Not enough command line arguments.\n" );
    exit( 1 );
  }
  FILE *fp;
  fp = fopen( argv[1], "r" );
  if( fp == NULL ){
    printf( "Cannot open file \"%s\".\n", argv[1] );
    exit( 1 );
  }

  int fileSize = 0; /* The given size of the input file */
  fscanf( fp, "%d", &fileSize );
  int *list1;
  int *list2;
  list1 = ( int* )malloc( fileSize * sizeof( int ) );
  list2 = ( int* )calloc( fileSize, sizeof( int ) );
  int i;
  for( i = 0; i < fileSize; i++ ){
    fscanf( fp, "%d", &list1[i] );
    list2[i] = list1[i];
  }
  fclose( fp );

  ExchangeSort( list1, fileSize );
  QuickSort( list2, fileSize );

  PrintArray( list1, fileSize );
  PrintArray( list2, fileSize );

  free( list1 );
  free( list2 );

  return 0;
}

void ExchangeSort( int A[], int N ){
  
  int i, j;
  int swapped = 1;
  for( i = 0; i < N && swapped; i++ ){
    swapped = 0;
    for( j = 0; j < N-1; j++ ){
      if( A[ j ] > A[ j+1 ] ){
	Swap( &A[ j ], &A[ j+1 ] );
	swapped = 1;
      }
    }
  }
}

void Swap( int *a, int *b ){

  int t = *a;
  *a = *b;
  *b = t;
}

void QuickSort( int B[], int N ){

  QSort( B, 0, N );
}

void QSort( int B[], int indexLow, int indexHigh ){

  if( indexHigh <= indexLow )
    return;
  int pivot = B[ indexLow ];
  int left = indexLow+1;
  int right = indexHigh;
  while( left < right ){
    if( B[ left ] >= pivot )
      left++;
    else
      Swap( &B[ left ], &B[ --right ] );
  }
  Swap( &B[ --left ], &B[ indexLow ] );
  
  QSort( B, indexLow, left );
  QSort( B, right, indexHigh );
}

void PrintArray( int A[], int N ){

  int i;
  for( i = 0; i < N; i++ )
    printf( "%d ", A[i] );
  printf( "\n" );
}
