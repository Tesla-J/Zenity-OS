gdt_start:
gdt_null:
  dd 0
  dd 0
gdt_code:
  dw 0xffff
  dw 0
  db 0
  db 0x9a
  db 0xcf
  db 0
gdt_data:
  dw 0xffff
  dw 0
  db 0
  db 0x92
  db 0xcf
  db 0
gdt_end:
gdt_desc:
dw gdt_end - gdt_start - 1
dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
