;si=string
print:
  mov ah, 0xe
  .write:
    lodsb
    cmp al, 0
    jz .end
    int 10h
    jmp .write
  .end:
    ret
