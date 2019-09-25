#define _ZIO

/* PROTOTIPOS */
unsigned char byte_in(unsigned short port);
unsigned short word_in(unsigned short port);
void byte_out(unsigned char value, unsigned short port);
void word_out(unsigned short value, unsigned short port);
