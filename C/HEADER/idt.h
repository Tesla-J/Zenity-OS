#ifndef _ZIDT
#define _ZIDT
#define Z_CS 0x08

//idt table
typedef struct{
  unsigned short low_offset; //16bits
  unsigned short sel;
  unsigned char always0;
  unsigned char flags;
  unsigned short high_offset;
} __attribute__((packed)) idt_gate;

//idt registrer
typedef struct{
  unsigned short limit;
  unsigned long base;
} __attribute__((packed)) idt_reg;

#define IDT_ENTRIES 256
idt_gate idt[IDT_ENTRIES];
idt_reg  reg;

//Prototipos
void set_idt_gate(int n, unsigned long handler);
void set_idt(void);
#endif
