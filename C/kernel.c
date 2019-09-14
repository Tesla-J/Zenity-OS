#include "HEADER/screen.h"

void zmain(void){
  char str[] = {'x','X','x','\0'};//{'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
  int index=0;

  //print(str,13,0xf);
  p();

  while(str[index++]){
    p();
    put_char(str[index],13);
  }
  while(1); //loop infinito
}
