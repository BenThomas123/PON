# Makefile

CC = gcc
LD = ld
AS = nasm

CFLAGS = -m32 -nostdlib -ffreestanding -Wall -Wextra
LDFLAGS = -T link.ld

OBJ = gdt.o idt.o multiboot.o

all: kernel.bin

kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) -f elf32 $< -o $@

clean:
	rm -f *.o kernel.bin
