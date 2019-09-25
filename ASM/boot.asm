[org 0x7c00]

;setting stack
mov bp, 0x9000
mov sp, bp

;boot message
mov si, BOOT_MSG
call print

;carrega o kernel
call load

;modo protegido
mov si, PM_ALERT
call print
call sw_pm

jmp $

%include "ASM/write.asm"
%include "ASM/disk.asm"
%include "ASM/gdt.asm"
%include "ASM/pm.asm"

;mensagens
BOOT_MSG db "Starting Zenity OS",10,13,0
LOADED db "Zenity OS carregado!",10,13,0
NLOADED db "Erro ao carregar o Zenity OS",10,13,0
K_MSG db "Iniciando Kernel...",10,13,0
PM_ALERT db "Entrando em modo seguro...",10,13,0
PM_MSG db "Modo seguro iniciado com sucesso!",0

;dados especiais
DEP db "DONE",10,13,0 ;apenas para depuracao

times 510-($-$$) db 0xff
dw 0xaa55
