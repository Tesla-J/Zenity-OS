[org 0x7c00]

;setting stack
mov bp, 0x9000
mov sp, bp

;boot message
mov si, BOOT_MSG
call print

;carrega o kernel
call load

jmp E

%include "ASM/write.asm"
%include "ASM/disk.asm"

;mensagens
BOOT_MSG db "Starting Zenity OS",10,13,0
LOADED db "Zenity OS carregado!",10,13,0
NLOADED db "Erro ao carregar o Zenity OS",10,13,0
K_MSG db "Iniciando Kernel...",10,13,0

;dados especiais
DEP db "DONE",10,13,0 ;apenas para depuracao

times 510-($-$$) db 0xff
dw 0xaa55

E:
mov si, K_MSG
call print
jmp $

;Modo seguro
;pular directo para kernel
;fazer kernel
