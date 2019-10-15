#include "HEADER/isr.h"
#include "HEADER/screen.h"
#include "HEADER/idt.h"
#include "HEADER/io.h"

//configura os idt gates
void isr_install(){
  set_idt_gate(0, (unsigned long)isr0);
  set_idt_gate(1, (unsigned long)isr1);
  set_idt_gate(2, (unsigned long)isr2);
  set_idt_gate(3, (unsigned long)isr3);
  set_idt_gate(4, (unsigned long)isr4);
  set_idt_gate(5, (unsigned long)isr5);
  set_idt_gate(6, (unsigned long)isr6);
  set_idt_gate(7, (unsigned long)isr7);
  set_idt_gate(8, (unsigned long)isr8);
  set_idt_gate(9, (unsigned long)isr9);
  set_idt_gate(10, (unsigned long)isr10);
  set_idt_gate(11, (unsigned long)isr11);
  set_idt_gate(12, (unsigned long)isr12);
  set_idt_gate(13, (unsigned long)isr13);
  set_idt_gate(14, (unsigned long)isr14);
  set_idt_gate(15, (unsigned long)isr15);
  set_idt_gate(16, (unsigned long)isr16);
  set_idt_gate(17, (unsigned long)isr17);
  set_idt_gate(18, (unsigned long)isr18);
  set_idt_gate(19, (unsigned long)isr19);
  set_idt_gate(20, (unsigned long)isr20);
  set_idt_gate(21, (unsigned long)isr21);
  set_idt_gate(22, (unsigned long)isr22);
  set_idt_gate(23, (unsigned long)isr23);
  set_idt_gate(24, (unsigned long)isr24);
  set_idt_gate(25, (unsigned long)isr25);
  set_idt_gate(26, (unsigned long)isr26);
  set_idt_gate(27, (unsigned long)isr27);
  set_idt_gate(28, (unsigned long)isr28);
  set_idt_gate(29, (unsigned long)isr29);
  set_idt_gate(30, (unsigned long)isr30);
  set_idt_gate(31, (unsigned long)isr31);

  //remap the PICs
  byte_out(0x11, 0x20); //master
  byte_out(0x20,0x21);
  byte_out(0x4,0x21);
  byte_out(0x1,0x21);
  byte_out(0x0,0x21);
  byte_out(0x11, 0xa0); //slave
  byte_out(0x28,0xa1);
  byte_out(0x2,0xa1);
  byte_out(0x1,0xa1);
  byte_out(0x0,0xa1);

  //IRQs
  set_idt_gate(32, (unsigned long)irq0);
  set_idt_gate(33, (unsigned long)irq1);
  set_idt_gate(34, (unsigned long)irq2);
  set_idt_gate(35, (unsigned long)irq3);
  set_idt_gate(36, (unsigned long)irq4);
  set_idt_gate(37, (unsigned long)irq5);
  set_idt_gate(38, (unsigned long)irq6);
  set_idt_gate(39, (unsigned long)irq7);
  set_idt_gate(40, (unsigned long)irq8);
  set_idt_gate(41, (unsigned long)irq9);
  set_idt_gate(42, (unsigned long)irq10);
  set_idt_gate(43, (unsigned long)irq11);
  set_idt_gate(44, (unsigned long)irq12);
  set_idt_gate(45, (unsigned long)irq13);
  set_idt_gate(46, (unsigned long)irq14);
  set_idt_gate(47, (unsigned long)irq15);

  set_idt();
}

//vector das mensagens de cada exception
char *except_msg[] = {
  "Division by Zero",
  "Debug",
  "Non Mascable Interrupt",
  "Breakpoint",
  "Into Detected Overflow",
  "Out of Bounds",
  "Invalid Opcode",
  "No Coprocessor",

  "Double Fault",
  "Coprocessor Segment Overrurn",
  "Bad TSS",
  "Segment Nor Present",
  "Stack Not Present",
  "Stack Fault",
  "General Protection Fault",
  "Page Fault",
  "Unknown Interrupt",

  "Coprocessor Fault",
  "Alignment Check",
  "Machine check",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",

  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved"
};

//mostra o resultado do interrupt
void isr_handler(stk_reg r){
  char *s;
  //putstr_at(except_msg[r.int_no], -1, -1, RED_ON_BLACK);
  putstr(except_msg[r.int_no]);
}

void irq_handler(stk_reg r){
  //enviando EOI
  if(!r.int_no)
    byte_out(0x20, 0xa0);
  byte_out(0x20, 0x20);

  putstr(" IRQ acionado\n");
}
