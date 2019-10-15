#ifndef _ZSC
#define _ZSC

#define VID_MEM 0xb8000
#define MAX_COL 80
#define MAX_ROW 25
#define SC_SIZE (MAX_COL*MAX_ROW)
#define SCREEN_CTRL 0X3D4
#define SCREEN_DATA 0X3D5
//atributos
#define WHITE_ON_BLACK 0XF
#define GREEN_ON_BLACK 0XA
#define RED_ON_BLACK 0XC
#define BLACK_ON_WHITE 0XF0
#define BLACK_ON_BLACK 0X0

/* PROTOTIPOS */
void print(char str[], int linha, int attr);
void p(void);
void putchar_at(char ch, short col, short linha, char attr);
void putchar(char ch);
void putstr_at(char str[], short col, short linha, unsigned short attr);
void putstr(char str[]);
unsigned short get_cursor_offset(void);
unsigned short get_offset(unsigned short col, unsigned short linha);
void set_cursor_offset(unsigned short offset);
void clear(char attr);
void nwln(void);
void tab(void);
unsigned short get_row(unsigned short offset);
unsigned short get_col(unsigned short offset);
void scroll();
#endif
