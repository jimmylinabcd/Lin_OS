export PATH=$PATH:/usr/local/i386elfgcc/bin
i386-elf-gcc -ffreestanding -m32 -g -c "kernel.cpp" -o "kernel.o"
i386-elf-ld -o "full_kernel.bin" -Ttext 0x1000 "kernel_entry.o" "kernel.o" --oformat binary
cat "boot.bin" "full_kernel.bin" "zeros.bin"  > "OS.bin"