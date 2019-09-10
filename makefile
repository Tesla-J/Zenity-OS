ZenityOS.img: BIN/boot.bin
	cat $^ > $@

BIN/boot.bin: ASM/boot.asm ASM/write.asm ASM/disk.asm
	nasm -f bin $< -o $@
