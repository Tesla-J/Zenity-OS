#include "HEADER/idt.h"

void set_idt_gate(int n, unsigned long handler){
  idt[n].low_offset = (unsigned short) (handler & 0xffff);
  idt[n].sel = Z_CS;
  idt[n].always0 = 0;
  idt[n].flags = 0x8e;
  idt[n].high_offset = (unsigned short) ((handler >> 16) & 0xffff);
}

void set_idt(void){
  reg.base = (unsigned long) &idt;
  reg.limit = (IDT_ENTRIES * sizeof (idt_gate)) -1 ;
  asm volatile ("lidtl (%0)" : : "r" (&reg));
}
