#define _ZSC
#ifndef _ZIO
#include "io.h"
#endif

#define VID_MEM 0xb8000
#define MAX_COL 80
#define MAX_ROW 25
#define SCREEN_CTRL 0X3D4
#define SCREEN_DATA 0X3D5

/* PROTOTIPOS */
void print(char str[], int linha, int attr);
void p(void);
void putchar(char ch);
unsigned short get_cursor(void);
unsigned short get_offset(void);

//imprime caracteres na tela
void print(char str[], int linha, int attr){
  int index,code;
  unsigned char *mem = (unsigned char*) (0xb8000);// + (160*linha));

  for(index=0; str[index] != '\0'; index+=2){
    mem[index+1] = str[index];
    mem[index+2] = attr;
  }
  return;
}


//teste
void p(void){
  unsigned short offset = get_offset();
  char* video_mem = (char*) (0xb8000);//+(160*13));

  video_mem[offset] = 'x';
  video_mem[offset+1] = 0xc;
  video_mem[offset+2] = 'X';
  video_mem[offset+3] = 0xc;
  video_mem[offset+4] = 'x';
  video_mem[offset+5] = 0xc;

  return;
}

//funcao para imprimir
void putchar(char ch){
  unsigned short offset = get_offset();
  unsigned char* mem = (unsigned char*) VID_MEM;

  mem[offset] = ch;
  mem[offset+1] = 0xd;

}


//obtem posicao actual do cursor
unsigned short get_cursor(void){
  unsigned short position;

  //14 nos da os high level byte da posicao do cursor
  byte_out(14, SCREEN_CTRL);
  position = byte_in(SCREEN_DATA) << 8; //movendo para high level byte

  byte_out(15, SCREEN_CTRL); //pede o low level byte
  position += byte_in(SCREEN_DATA);

  return position;

}

//obtem o offset do cursor
unsigned short get_offset(void){
  unsigned short offset = 2 * get_cursor();
  return offset;
}
