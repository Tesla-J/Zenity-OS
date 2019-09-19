#include "HEADER/keyboard.h"
#include "HEADER/screen.h"

void zmain(void){
  char str[] = {'x','X','x','\0'};//{'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
  int index=0, offset;
  char *v = (char*) 0xb8000;

set_cursor_offset(get_offset(0,15));
offset = get_cursor_offset() + 1;


  //putchar('X');
  putchar_at('X',16,13,GREEN_ON_BLACK);

  /*v[offset] = 'X';
  v[offset+1] = 0xa;*/


  while(1); //loop infinito
}
