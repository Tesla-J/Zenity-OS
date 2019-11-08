#include "HEADER/util.h"
#include "HEADER/string.h"

//converte string para numero
long stoi(char* s){
  long num=0, digit, base=10;
  unsigned short index;

  for(index=0; s[index]; index++){
    num *= base;
    digit = atoi(s[index]);
    num += digit;
  }
  return num;
}

//converte numero para string
char* itos(long i){
  short q,r;
  char* str;
  int index;

  for(index=0; i!=0; i/=10, index++){
    r = i%10;
    str[index] = itoa(r);
  }
  return revstr(str);
}

//converte ascii pata int
int atoi(char a){
  return (int) (a-'0');
}

///converte int para ascii
char itoa(int i){
  char low_i = (i & 0x00ff);
  return (char) (low_i+48);
}
