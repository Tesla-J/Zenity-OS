#include "HEADER/io.h"

//ler byte de uma porta
unsigned char byte_in(unsigned short port){
  unsigned char in_value;

  asm("in %%dx, %%al":"=a"(in_value):"d"(port));
  return in_value;
}

//ler word para uma porta
unsigned short word_in(unsigned short port){
  unsigned short in_value;

  asm("in %%dx, %%ax":"=a"(in_value):"d"(port));
  return in_value;
}


//enviar byte pela porta
void byte_out(unsigned char value, unsigned short port){
  asm("out %%al, %%dx": :"d"(port),"a"(value));
  return;
}


//enviar word pela porta
void word_out(unsigned short value, unsigned short port){

  asm("out %%ax, %%dx": :"d"(port),"a"(value));
  return;
}
