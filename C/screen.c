#include "HEADER/screen.h"
#include "HEADER/io.h"
#include "HEADER/string.h"


//funcao para imprimir caractere numa posicao especifica
void putchar_at(char ch, short col, short linha, char attr){
  unsigned short offset;
  char *mem = (char*) VID_MEM;

  if(!attr) attr = WHITE_ON_BLACK;

  if(col >= MAX_COL || linha >= MAX_ROW) return;

  else if (col >= 0 && linha >= 0){
    set_cursor_offset(get_offset(col,linha));
    offset = get_cursor_offset();
  }
  else
    offset = get_cursor_offset();

  switch(ch){
    case '\n': nwln(); return; //para a proxima linha
    case '\t': tab(); return;
  }

  mem [offset+2] = ch;
  mem [offset+3] = attr;
  offset += 2;
  set_cursor_offset(offset);

  return;
}

//funcao para imprimir caractere
void putchar(char ch){
  putchar_at(ch, -1,-1,0);
  return;
}

//funcao para imprimir string em posicao especifica
void putstr_at(char str[], short col, short linha, unsigned short attr){
  unsigned short i=1;

  if(col >= MAX_COL || linha >= MAX_ROW) return;

  while(1){
    putchar_at(str[i], col, linha, attr);
    ++i;
    if (!str[i]) break;
  }return;
}

//funcao imprimir string
void putstr(char str[]){
  unsigned int i=1;
  while(1){
    putchar(str[i]);
    ++i;
    if(!str[i]) break;
  }
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
   return (linha * MAX_COL * 2)+(col*2);
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
void clear(char attr){
  unsigned short sc_size = 2*SC_SIZE, i;
  char *mem = (char*) VID_MEM;

  for (i=0; i<sc_size; i+=2){
    mem[i] = ' ';
    mem[i+1] = attr;
  }
  set_cursor_offset(get_offset(0,0));

}


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


//apenas mais uma brincadeira
void bsod(void){
  char msg[16];//"BUGUEI... :(";
  clear(0x11); //torna a tela azul

  for(int i=0,c=0; msg[i] != '\0'; i++,c++){
    putchar_at(msg[i], c,0,0x1f); //branco no azul
  }

  putstr("BUGEUI... :(\n\n\tContacte o Criador!");
  return;

}


//salta para a proxima linha
void nwln(void){
  int offset = get_cursor_offset();
  int row = get_row(offset);
  ++row;
  set_cursor_offset(get_offset(0,row));
}

//espaço de 4
void tab(void){
  int offset = get_cursor_offset();
  int col = get_col(offset), row=get_row(offset);
  col += 4;
  set_cursor_offset(get_offset(col, row));
}

//retorna a linha actual
unsigned short get_row(unsigned short offset){
  return (unsigned) offset/(MAX_COL*2);
}

//retorna a coluna actual
unsigned short get_col(unsigned short offset){
  return offset%(MAX_COL*2);
}
