ZenityOS.img: BIN/boot.bin BIN/kernel.bin
	cat $^ > $@

BIN/boot.bin: ASM/boot.asm ASM/write.asm ASM/disk.asm ASM/gdt.asm ASM/pm.asm
	nasm -f bin $< -o $@

BIN/kernel.bin: C/kernel.c ASM/k_entry.asm C/HEADER/*.h
	gcc -ffreestanding -c $< -o BIN/kernel.o
	nasm ASM/k_entry.asm -f elf64 -o BIN/k_entry.o
	ld --Ttext 0x1000 BIN/k_entry.o BIN/kernel.o --oformat binary -o $@
