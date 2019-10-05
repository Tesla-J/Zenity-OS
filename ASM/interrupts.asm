[bits 32]
[extern isr_handler]

isr_common_stub:
  ;salva o status da cpu
  pusha
  mov ax, ds
  push eax
  mov ax, 0x10
  mov ds, ax
  mov gs, ax
  mov fs, ax
  mov es, ax

  ;chama a funcao...
  call isr_handler

  ;retorna ao estado anterior
  pop eax
  mov ds, ax
  mov gs, ax
  mov fs, ax
  mov es, ax
  popa
  add esp, 8
  sti
  iret

  global isr0
  global isr1
  global isr2
  global isr3
  global isr4
  global isr5
  global isr6
  global isr7
  global isr8
  global isr9
  global isr10
  global isr11
  global isr12
  global isr13
  global isr14
  global isr15
  global isr16
  global isr17
  global isr18
  global isr19
  global isr20
  global isr21
  global isr22
  global isr23
  global isr24
  global isr25
  global isr26
  global isr27
  global isr28
  global isr29
  global isr30
  global isr31

  isr0:
    push byte 0
    push byte 0
    cli
    jmp isr_common_stub

  isr1:
    push byte 0
    push byte 1
    cli
    jmp isr_common_stub

  isr2:
    push byte 0
    push byte 2
    cli
    jmp isr_common_stub

  isr3:
    push byte 0
    push byte 3
    cli
    jmp isr_common_stub

  isr4:
    push byte 0
    push byte 4
    cli
    jmp isr_common_stub

  isr5:
    push byte 0
    push byte 5
    cli
    jmp isr_common_stub

  isr6:
    push byte 0
    push byte 6
    cli
    jmp isr_common_stub

  isr7:
    push byte 0
    push byte 7
    cli
    jmp isr_common_stub

  isr8:
    push byte 8
    cli
    jmp isr_common_stub

  isr9:
    push byte 0
    push byte 9
    cli
    jmp isr_common_stub

  isr10:
    push byte 10
    cli
    jmp isr_common_stub

  isr11:
    push byte 11
    cli
    jmp isr_common_stub

  isr12:
    push byte 12
    cli
    jmp isr_common_stub

  isr13:
    push byte 13
    cli
    jmp isr_common_stub

  isr14:
    push byte 14
    cli
    jmp isr_common_stub

  isr15:
    push byte 0
    push byte 15
    cli
    jmp isr_common_stub

  isr16:
    push byte 0
    push byte 16
    cli
    jmp isr_common_stub

  isr17:
    push byte 0
    push byte 17
    cli
    jmp isr_common_stub

  isr18:
    push byte 0
    push byte 18
    cli
    jmp isr_common_stub

    isr19:
      push byte 0
      push byte 19
      cli
      jmp isr_common_stub

    isr20:
      push byte 0
      push byte 20
      cli
      jmp isr_common_stub

    isr21:
      push byte 0
      push byte 21
      cli
      jmp isr_common_stub

    isr22:
      push byte 0
      push byte 22
      cli
      jmp isr_common_stub

    isr23:
      push byte 0
      push byte 23
      cli
      jmp isr_common_stub

    isr24:
      push byte 0
      push byte 24
      cli
      jmp isr_common_stub

    isr25:
      push byte 0
      push byte 25
      cli
      jmp isr_common_stub

    isr26:
      push byte 0
      push byte 26
      cli
      jmp isr_common_stub

    isr27:
      push byte 0
      push byte 27
      cli
      jmp isr_common_stub

    isr28:
      push byte 0
      push byte 28
      cli
      jmp isr_common_stub

    isr29:
      push byte 0
      push byte 29
      cli
      jmp isr_common_stub

    isr30:
      push byte 0
      push byte 30
      cli
      jmp isr_common_stub

    isr31:
      push byte 0
      push byte 31
      cli
      jmp isr_common_stub
