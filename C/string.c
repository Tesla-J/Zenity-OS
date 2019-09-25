#include "HEADER/string.h"


//retorna tamanho da string (sem contar '\0')
unsigned int strlen(char str[]){
  int c;

  for(c=0; str[c] != 0; c++);
  return c;
}

//copia uma string para um array/ponteiro
void strcp(char dest[], char src[]){
  unsigned short i;

  for(i=0; src[i] != '\0'; i++){
    dest[i] = src[i];
  }return;
}

//retorna concatena duas strings
void strcat(char* str1, char* str2){
  int s1len = strlen(str1),i;

  for(i=0; str2[i] != '\0'; i++, s1len++){
    str1[s1len] = str2[i];
  }
  str1[s1len] = '\0';
  return;
}
