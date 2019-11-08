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
#include "HEADER/util.h"

void zmain(void){
  int n=0;
  char* c;
  isr_install(); //defini os interrupts

  putstr("\n\n Kernel Iniciado\n\n");
  putstr(" Configurando Interrupts\n");
  putstr(" Interrupts confiurados\n Iniciando timer...\n\n");

  asm volatile("sti");
  init_timer(0xb000);
  k_init();

  clear(0xf);
  putstr("&> ");
  //back_space(get_cursor_offset());


  //while(1);
}
