/* bootloader.asm - ESP32 Bootloader Initialization */

/* Section for the Reset Handler */
.section .text
.global reset_handler
.type reset_handler, @function

reset_handler:
    /* Step 1: Disable interrupts during initialization */
    rsil a0, 3           /* Disable interrupts, set interrupt level to 3 */

    /* Step 2: Initialize Stack Pointer */
    l32r a1, =_stack_top /* Load stack top address into a1 */
    mov sp, a1           /* Set stack pointer */

    /* Step 3: Clear the BSS Section (Zero-initialized Data) */
    l32r a2, =_bss_start /* Start of BSS section */
    l32r a3, =_bss_end   /* End of BSS section */
    mov a4, zero         /* Load zero into a4 for clearing */

clear_bss:
    bltu a2, a3, clear_next /* Compare start and end addresses */
    j bootloader_main       /* Jump to C bootloader_main if cleared */

clear_next:
    s32i a4, a2, 0         /* Store zero at address a2 */
    addi a2, a2, 4         /* Increment address by 4 bytes */
    j clear_bss            /* Repeat clearing process */

/* Section for memory definitions */
.section .data
.global _stack_top
.global _bss_start
.global _bss_end

/* Memory Region Definitions */
_stack_top:  .word 0x3FFB0000   /* Top of the stack (adjust for your board) */
_bss_start:  .word 0x3FFB8000   /* Start of BSS section */
_bss_end:    .word 0x3FFBC000   /* End of BSS section */
