;carrega os restantes sectores
load:
  mov ah, 2
  mov al, 1
  mov ch, 0
  mov cl, 2
  mov dh, 0
  mov es, [E]
  mov bx, 0
  int 13h
  jc .error
  mov si, LOADED
  call print
  ret

  .error:
    mov si, NLOADED
    call print
    jmp $