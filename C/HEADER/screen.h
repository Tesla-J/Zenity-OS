#define _ZSC
#ifndef _ZIO
#include "io.h"
#endif

#define VID_MEM 0xb8000
#define MAX_COL 80
#define MAX_ROW 25
#define SC_SIZE (MAX_COL*MAX_ROW)
#define SCREEN_CTRL 0X3D4
#define SCREEN_DATA 0X3D5
//atributos
#define WHITE_ON_BLACK 0XF
#define GREEN_ON_BLACK 0XA
#define RED_ON_BLACK 0XC
#define BLACK_ON_WHITE 0XF0
#define BLACK_ON_BLACK 0X0

/* PROTOTIPOS */
void print(char str[], int linha, int attr);
void p(void);
void putchar_at(unsigned char ch, unsigned short col, unsigned short linha, unsigned char attr);
void putchar(char ch);
unsigned short get_cursor_offset(void);
unsigned short get_offset(unsigned short col, unsigned short linha);
void set_cursor_offset(unsigned short offset);
void clear(void);


//funcao para imprimir caractere numa posicao especifica
void putchar_at(unsigned char ch, unsigned short col, unsigned short linha, unsigned char attr){
  unsigned short offset;
  unsigned char *mem = (unsigned char*) VID_MEM;

  if(!attr) attr = WHITE_ON_BLACK;

  if(col >= MAX_COL || linha >= MAX_ROW) return;

  else if (col >= 0 && linha >= 0){
    set_cursor_offset(get_offset(col,linha));
    offset = get_cursor_offset();
  }
  else
    offset = get_cursor_offset();

  mem [offset] = ch;
  mem [offset+1] = attr;
  offset += 2;
  set_cursor_offset(offset);

  return;
}

//funcao para imprimir caractere
void putchar(char ch){
  putchar_at(ch, -1,-1,0);
  return;
}


//obtem posicao actual do cursor
unsigned short get_cursor_offset(void){
  unsigned short position;

  //14 nos da os high level byte da posicao do cursor
  byte_out(14, SCREEN_CTRL);
  position = byte_in(SCREEN_DATA) << 8; //movendo para high level byte

  byte_out(15, SCREEN_CTRL); //pede o low level byte
  position += byte_in(SCREEN_DATA);

  return 2*position;

}

//obtem o offset do cursor
unsigned short get_offset(unsigned short col, unsigned short linha){
  return 2*(linha * MAX_COL)+col;
}

//define a posicao do cursor
void set_cursor_offset(unsigned short offset){
  int aux=offset/2;

  //define high level byte
  byte_out(14,SCREEN_CTRL);
  byte_out(aux >> 8, SCREEN_DATA);

  //define low level byte
  byte_out(15,SCREEN_CTRL);
  byte_out(aux & 0xff, SCREEN_DATA);

  return;
}

//limpar a tela
void clear(void){
  unsigned short sc_size = 2*SC_SIZE, i;
  unsigned char *mem = (unsigned char*) VID_MEM;

  for (i=0; i<sc_size; i+=2){
    mem[i] = ' ';
    mem[i+1] = BLACK_ON_BLACK;
  }
}

/*
//apenas uma brincadeira
void shine(){
  int c,i,s=2*SC_SIZE;
  char *m=(char*)VID_MEM;
while(c++){
  //if (c > 0xf) c=0xa;
  for(i=1, c=0xa; i<s; i+=2, c++){
    if (c > 0xf) c=0xa;
      m[i] = ' ';
      m[i+1] = c;
  }
}
}
*/
