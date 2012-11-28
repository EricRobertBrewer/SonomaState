/*
Eric Brewer
9/7/09
CS252
Lab 1 - Binary and Hex conversion
*/

#include<stdio.h>

int main(){
  printf("Enter an unsigned, decimal number: \n");
  int input = 0;
  scanf("%i", &input);

  int binArr[32];
  int i = 0;
  int binInput = input;
  while(binInput){
    binArr[i] = binInput % 2;
    binInput = binInput / 2;
    i++;
  }
  printf("Binary: ");
  if (!input)
    printf("0");
  else
    for(i = i-1; i > -1; --i)
      printf("%i", binArr[i]);
  printf("\n");

  char hexArr[8];
  char hexVals[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
  i = 0;
  int power = 16;
  int hexInput = input;
  while(hexInput){
    hexArr[i] = hexVals[hexInput % power];
    hexInput = hexInput - (hexInput % power);
    hexInput = hexInput / 16;
    i++;
  }
  printf("Hexadecimal: ");
  if(!input)
    printf("0");
  else
    for(i = i-1; i > -1; --i)
      printf("%c", hexArr[i]);
  printf("\n");

  return 0;
}

