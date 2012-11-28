#include <stdio.h>
#include "toLower.h"

int main(void){
  char *str = "DoWn\0";

  //printf("\nEnter a character string: ");
  //scanf("%s", str);
  toLower(str);
  printf("\nYou entered: %s", str);

  return 0;
}
