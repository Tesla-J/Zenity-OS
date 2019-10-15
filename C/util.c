#include "HEADER/util.h"
#include "HEADER/string.h"

//converte string para numero
long stoi(char* s){
  long num=0, digit, base=10;
  unsigned short index;

  for(index=0; s[index]; index++){
    num *= base;
    digit = s[index];
    num += digit
  }
  return num;
}

//converte numero para string
char* itos(long i){
  short q,r;
  char* str;

  for(int i=0; i; i/=10){
    r = i%10;
    str[i] = itoa(r);
  }
  return revstr(str);
}

//converte ascii pata int
int atoi(char a){
  return (int) (a-'1');
}

///converte int para ascii
char itoa(int i){
  return (char) (i+'1');
}
