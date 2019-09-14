#define VID_MEM 0xb8000
#define MAX_COL 80
#define MAX_ROW 25
#define REG_SCREEN_CTRL 0X3D4
#define REG_SCREEN_DATA 0X3D5



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
void p(){
  char* video_mem = (char*) (0xb8000+(160*13));

  video_mem[1] = 'x';
  video_mem[2] = 0xc;
  video_mem[3] = 'X';
  video_mem[4] = 0xc;
  video_mem[5] = 'x';
  video_mem[6] = 0xc;

  return;
}

//funcao para imprimir
void put_char(char ch, int line){
  unsigned char* mem = (unsigned char*) VID_MEM + (160*line);

  mem[0] = ch;
  mem[1] = 0xd;

}
