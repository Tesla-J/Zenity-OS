#include "HEADER/keyboard.h"
#include "HEADER/io.h"
#include "HEADER/screen.h"
#include "HEADER/isr.h"
#include "HEADER/idt.h"
#include "HEADER/string.h"

void clear_buffer(void){
  for(int i=0; keys_buffer[i]; i++) keys_buffer[i]='\0';
  buffer_position=0;
}

void find_command(char* c){
  if(!strcmp("power",c)) shine();
  else if(!strcmp("halt",c)) asm volatile("hlt");
  else putstr("Comando desconecido!\n");
}

void put_to_buffer(char key){
  //caps lock
  if(!caps) if ( ((key >= 'A') && (key<='Z')) || ((key >='a') && (key <= 'z')) )  key ^= 0x20;
  keys_buffer[buffer_position] = key;

  ++buffer_position;
  set_cursor_offset(get_offset(3,get_row(get_cursor_offset())));

  putstr(keys_buffer);
}

static void k_check(){
  unsigned char s_code = byte_in(0X60);

  switch (s_code){
    case 0x1: break; //ESC

    case 0x2: put_to_buffer('1'); break;
    case 0x3: put_to_buffer('2'); break;
    case 0x4: put_to_buffer('3'); break;
    case 0x5: put_to_buffer('4'); break;
    case 0x6: put_to_buffer('5'); break;
    case 0x7: put_to_buffer('6'); break;
    case 0x8: put_to_buffer('7'); break;
    case 0x9: put_to_buffer('8'); break;
    case 0xa: put_to_buffer('9'); break;
    case 0xb: put_to_buffer('0'); break;

    case 0xe: back_space(get_cursor_offset());
              --buffer_position; keys_buffer[buffer_position] = '\0'; break; //BACKSPACE

    case 0x10: put_to_buffer('Q'); break;
    case 0x11: put_to_buffer('W'); break;
    case 0x12: put_to_buffer('E'); break;
    case 0x13: put_to_buffer('R'); break;
    case 0x14: put_to_buffer('T'); break;
    case 0x15: put_to_buffer('Y'); break;
    case 0x16: put_to_buffer('U'); break;
    case 0x17: put_to_buffer('I'); break;
    case 0x18: put_to_buffer('O'); break;
    case 0x19: put_to_buffer('P'); break;

    case 0x1c: nwln();
               find_command(keys_buffer);
               putstr("&> ");
               clear_buffer();
               break; //ENTER
    case 0x1e: put_to_buffer('A'); break;
    case 0x1f: put_to_buffer('S'); break;
    case 0x20: put_to_buffer('D'); break;
    case 0x21: put_to_buffer('F'); break;
    case 0x22: put_to_buffer('G'); break;
    case 0x23: put_to_buffer('H'); break;
    case 0x24: put_to_buffer('H'); break;
    case 0x25: put_to_buffer('J'); break;
    case 0x26: put_to_buffer('K'); break;
    case 0x2a: break; //L SHIFT

    case 0x2c: put_to_buffer('Z'); break;
    case 0x2d: put_to_buffer('X'); break;
    case 0x2e: put_to_buffer('C'); break;
    case 0x2f: put_to_buffer('V'); break;
    case 0x30: put_to_buffer('B'); break;
    case 0x31: put_to_buffer('N'); break;
    case 0x32: put_to_buffer('M'); break;

    case 0x36: break; //R SHIFT
    case 0x37: break; //PtScr
    case 0x38: break; //Alt
    case 0x3b: break; //F1 - usarei como help



    case 0x1d: break; //CTRL
    case 0x3a: caps ^= 1; break; //caps lock
  }
}

void k_init(){
  reg_int_handler(IRQ1, k_check);
}
