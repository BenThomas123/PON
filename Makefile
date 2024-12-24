all:
    cd boot && make
    cd kernel && make
    cd lib && make
    cd tests && make
    ld -T linker.ld -o pon_os.bin boot/bootloader.o kernel/kernel.o lib/*.o

run:
    qemu-system-x86_64 -kernel pon_os.bin

clean:
    cd boot && make clean
    cd kernel && make clean
    cd lib && make clean
    cd tests && make clean
    rm -f *.bin
