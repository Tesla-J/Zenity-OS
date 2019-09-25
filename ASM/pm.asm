[bits 16]
sw_pm:
  cli
  lgdt [gdt_desc]
  mov eax, cr0
  or eax, 1
  mov cr0, eax
  jmp CODE_SEG:init_pm

[bits 32]
init_pm:
  mov ax, DATA_SEG
  mov es, ax
  mov ds, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax
  jmp start_pm

start_pm:
  ;set stack
  mov ebp, 0x90000
  mov esp, ebp

  mov ebx, 0xb8000+(160*11)
  mov edx, 0x0f
  mov esi, PM_MSG
  call print_pm
  jmp 0x1000 ;esntrada do kernel
