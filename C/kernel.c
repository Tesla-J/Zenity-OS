/*Algo estranho se passa: o índice dos vectores começa de 1 e não de 0
Mas... como se diz: "Se finciona, não mexa!"

Rafael Marcos 24-9-2019 21:17 GMT+1
*/

#include "HEADER/keyboard.h"
#include "HEADER/screen.h"
#include "HEADER/string.h"
#include "HEADER/idt.h"
#include "HEADER/isr.h"

void zmain(void){
isr_install();

  putstr("\n\n Kernel Iniciado\n\n");
  putstr(" Configurando Interrupts\n");
  asm volatile ("int $32");
  putstr(" Interrupts confiurados\n Iniciando testes...");

  while(1);
}
