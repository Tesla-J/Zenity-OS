#ifndef _ZKB
#define _ZKB

//potas de i/o do teclado
#define K_CTRL_PORT 0X60
#define K_DATA_PORT 0X64

static char keys_buffer[1024] = "cammp e marda";
static int caps;
static unsigned short buffer_position=0;

void k_init(); //inicia o teclado
#endif
