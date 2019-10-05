ZenityOS.img: BIN/boot.bin BIN/kernel.bin
	cat $^ > $@

BIN/boot.bin: ASM/boot.asm ASM/write.asm ASM/disk.asm ASM/gdt.asm ASM/pm.asm
	nasm -f bin $< -o $@

BIN/kernel.bin: C/*.c ASM/k_entry.asm C/HEADER/*.h ASM/interrupts.asm
	gcc -m32 -ffreestanding -c C/kernel.c -o BIN/kernel.o
	gcc -m32 -ffreestanding -c C/io.c -o BIN/io.o
	gcc -m32 -ffreestanding -c C/screen.c -o BIN/screen.o
	gcc -m32 -ffreestanding -c C/string.c -o BIN/string.o
	gcc -m32 -ffreestanding -c C/keyboard.c -o BIN/keyboard.o
	gcc -m32 -ffreestanding -c C/idt.c -o 	BIN/idt.o
	gcc -m32 -ffreestanding -c C/isr.c -o 	BIN/isr.o
	nasm ASM/k_entry.asm -f elf -o BIN/k_entry.o
	nasm ASM/interrupts.asm -f elf -o BIN/interrupts.o
	ld -melf_i386 --Ttext 0x1000 BIN/k_entry.o BIN/kernel.o BIN/interrupts.o BIN/isr.o BIN/idt.o BIN/io.o BIN/screen.o BIN/string.o BIN/keyboard.o --oformat binary -o $@
#devido a modificações, isto está assim
