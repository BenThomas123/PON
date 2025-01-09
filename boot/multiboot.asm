; multiboot.asm

section .multiboot
align 4
    dd 0x1BADB002     ; Magic number
    dd 0x00           ; Flags
    dd -(0x1BADB002)  ; Checksum

section .text
global _start
_start:
    cli               ; Disable interrupts
    mov esp, stack_top ; Set stack pointer
    call kernel_main   ; Jump to kernel_main in C code
    hlt               ; Halt if kernel_main returns

section .bss
align 16
stack_bottom:
    resb 16384        ; 16 KiB stack
stack_top:
