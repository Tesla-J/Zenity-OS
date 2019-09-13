//asm("call main");

void print(char *str, int linha, int attr);

void main(void){
  char* video_mem = (char*) (0xb8000+(160*13));
  char str[] = {'x','X','x','\0'};//{'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};

  video_mem[1] = 'x';
  video_mem[2] = 0xc;
  video_mem[3] = 'X';
  video_mem[4] = 0xc;
  video_mem[5] = 'x';
  video_mem[6] = 0xc;

  print(str,13,0xf);
  while(1);
}

//imprime caracteres na tela
void print(char str[], int linha, int attr){
  int index,code;
  char *mem = (char*) (0xb8000); //+ (160*linha));

  for(index=0; str[index] != '\0'; index+=2){
    mem[index] = str[index-1];
    mem[index+1] = attr;
  }
  return;
}
