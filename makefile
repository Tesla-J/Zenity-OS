ZenityOS.img: BIN/boot.bin BIN/kernel.bin
	cat $^ > $@

BIN/boot.bin: ASM/boot.asm ASM/write.asm ASM/disk.asm ASM/gdt.asm ASM/pm.asm
	nasm -f bin $< -o $@

BIN/kernel.bin: C/*.c ASM/k_entry.asm C/HEADER/*.h
	gcc -ffreestanding -c C/kernel.c -o BIN/kernel.o
	gcc -ffreestanding -c C/io.c -o BIN/io.o
	gcc -ffreestanding -c C/screen.c -o BIN/screen.o
	gcc -ffreestanding -c C/string.c -o BIN/string.o
	gcc -ffreestanding -c C/keyboard.c -o BIN/keyboard.o
	nasm ASM/k_entry.asm -f elf64 -o BIN/k_entry.o
	ld --Ttext 0x1000 BIN/k_entry.o BIN/kernel.o BIN/io.o BIN/screen.o BIN/string.o BIN/keyboard.o --oformat binary -o $@
#devido a modificações, isto está assim
