#include <stdio.h>

int main( void ){
  float number;
  int counter = 20;

  number = 0.5;
  while( number != 0.0 && counter > 0 ){
    printf( "number = %.10f and counter = %i\n", number, counter );

    number -= 0.0625;
    counter -= 1;
  }

  return 0;
}
