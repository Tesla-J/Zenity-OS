/*Algo estranho se passa: o índice dos vectores começa de 1 e não de 0
Mas... como se diz: "Se finciona, não mexa!"

Rafael Marcos 24-9-2019 21:17 GMT+1
*/

#include "HEADER/keyboard.h"
#include "HEADER/screen.h"
#include "HEADER/string.h"
#include "HEADER/idt.h"
#include "HEADER/isr.h"
#include "HEADER/timer.h"

void zmain(void){
isr_install();

  putstr("\n\n Kernel Iniciado\n\n");
  putstr(" Configurando Interrupts\n");
  putstr(" Interrupts confiurados\n Iniciando timer...");
  asm volatile("sti");
  init_timer(0xb000);

  while(1);
}
