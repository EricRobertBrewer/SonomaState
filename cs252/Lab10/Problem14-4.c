#include <stdio.h>

int main( void ){
  float fnumber = 2147483640.0;
  int inumber = 2147483646;

  printf( "Before adding, the float is %f\n", fnumber );
  printf( "   and the integer is %i\n\n", inumber );
  fnumber += 1.0;
  inumber += 1;
  printf( "After adding 1, the float is %f\n", fnumber );
  printf( "   and the integer is %i\n", inumber );

  return 0;
}
