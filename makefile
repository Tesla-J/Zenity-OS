ZenityOS.img: BIN/boot.bin BIN/kernel.bin
	cat $^ > $@

BIN/boot.bin: ASM/boot.asm ASM/write.asm ASM/disk.asm ASM/gdt.asm ASM/pm.asm
	nasm -f bin $< -o $@

BIN/kernel.bin: C/kernel.c
	gcc -ffreestanding -c $< -o BIN/kernel.o
	ld --Ttext 0x1000 BIN/kernel.o --oformat binary -o $@
