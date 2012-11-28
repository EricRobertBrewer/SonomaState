/*
Eric Brewer
9/10/09
CS252
Lab2_3 - BCD integer representation
*/

#include <stdio.h>

int main(){
  int input = 0;
  int digitArr[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int i = 0;

  printf("Enter an unsigned decimal integer: ");

  scanf("%i", &input);

  printf("The BCD representation of your integer is:\n");

  do{
    digitArr[i] = input % 10;
    input = input / 10;
    i++;
  }while(input);

  for(i--; i > -1; i--){
    switch(digitArr[i]){
    case 0:
      printf("0000 ");
      break;
    case 1:
      printf("0001 ");
      break;
    case 2:
      printf("0010 ");
      break;
    case 3:
      printf("0011 ");
      break;
    case 4:
      printf("0100 ");
      break;
    case 5:
      printf("0101 ");
      break;
    case 6:
      printf("0110 ");
      break;
    case 7:
      printf("0111 ");
      break;
    case 8:
      printf("1000 ");
      break;
    case 9:
      printf("1001 ");
      break;
    default:
      printf("Invalid input.\n");
    }
  }
  
  printf("\n");
  
  return 0;
}
