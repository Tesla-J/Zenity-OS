#include "HEADER/timer.h"
#include "HEADER/isr.h"
#include "HEADER/screen.h"
#include "HEADER/io.h"

unsigned long tick_tac = 0;

static void timer_callback(stk_reg r){
  tick_tac++;
  putstr("Tick Tack");
}

void init_timer(unsigned long freq){
  unsigned  mhz = 1193180;
  unsigned long div = mhz/ freq;
  unsigned char low = (unsigned char) (div & 0xff);
  unsigned char high = (unsigned char)((div >> 8) & 0xff);

  //send the command
  byte_out(0x36, 0x43);
  byte_out(low, 0x40);
  byte_out(high, 0x40);
}
