#include "HEADER/keyboard.h"
#include "HEADER/screen.h"

void zmain(void){
  char str[] = {'x','X','x','\0'};//{'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
  char ola[] = {'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
  int index=0, offset;
  char *v = (char*) 0xb8000;

  /*clear();
  putchar('>');
  putchar(' ');
  putchar('?');*/

  set_cursor_offset(get_offset(0,17));
  while(1){
    putchar(ola[index]);
    ++index;
    if(!ola[index]) break;
  }
  //putstr(ola);

  while(1); //loop infinito
}
