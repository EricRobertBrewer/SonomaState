/*
Eric Brewer
9/10/09
CS252
Lab2_2 - The "read" and "write" c functions
*/

#include <unistd.h>

int writeStr(char* c);
int readLn(char* c, int MAX);

int main(){
  char* cstr = NULL;

  do{
    write(STDOUT_FILENO, "Enter a string of characters: ", 30);
    readLn(cstr,80);
    writeStr(cstr);
    write(STDOUT_FILENO, "\n", 1);
  }while(readLn(cstr, 80));

  return 0;
}

int writeStr(char* c){
  int i = 0;
  while(c[i] != '\n'){
    write(STDOUT_FILENO, &c[i], 1);
    i++;
  }

  return i;
}

int readLn(char* c, int MAX){
  int i = 0;
  while(c[i] != '\n' && i < MAX){
    read(STDIN_FILENO, &c[i], 1);
    i++;
  }

  return i;
}
