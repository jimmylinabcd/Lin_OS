nasm "boot.asm" -f bin -o "boot.bin"
nasm "kernel_entry.asm" -f elf -o "kernel_entry.o"
i386-elf-gcc -ffreestanding -m32 -g -c "kernel.cpp" -o "kernel.o"
nasm "zeros.asm" -f bin -o "zeros.bin"

i386-elf-ld -o "full_kernel.bin" -Ttext 0x1000 "kernel_entry.o" "kernel.o" --oformat binary

cat "boot.bin" "full_kernel.bin" "zeros.bin"  > "OS.bin"