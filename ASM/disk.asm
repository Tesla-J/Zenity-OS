[bits 16]
;carrega os restantes sectores
load:
  mov ah, 2
  mov al, 37
  mov ch, 0
  mov cl, 2
  mov dh, 0
  mov bx, 0x1000;E
  int 13h
  jc .error
  mov si, LOADED
  call print
  ret

  .error:
    mov si, NLOADED
    call print
    jmp $
