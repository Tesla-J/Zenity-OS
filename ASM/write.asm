[bits 16]
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

[bits 32]
;si=string
;dx=attr
;bx=memory
print_pm:
  .rw:
    lodsb
    mov [ebx], al
    inc ebx
    mov [ebx], byte dl
    inc ebx
    or al, al
    jz .end
    jmp .rw
  .end:
    ret
