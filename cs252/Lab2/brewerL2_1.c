/*
Eric Brewer
9/10/09
CS252
Lab2_1 - 8-bit signed integer conversion
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  int input = 0;
  
  printf("Enter a signed decimal integer: ");

  scanf("%i", &input);

  //printf("\n");

  if(input >= -128 && input <= 127){
    if(input < 0)
      input += 256;
    
    int binArr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    int j = 0;
    while(input){
      binArr[i] = (input % 2);
      input = input / 2;
      i++;
    }
    printf("In 2's complement binary: ");

    for(i = 7; i > -1; i--)
      printf("%i", binArr[i]);
    
    printf("\n");

  }
  else
    printf("Your signed number won't fit into 8 bits.\n");

  return 0;
}
