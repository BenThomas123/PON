// idt.h

#ifndef IDT_H
#define IDT_H

// Initialize the Interrupt Descriptor Table
void idt_init();

// Set an entry in the IDT
void idt_set_gate(unsigned char num, unsigned int base, unsigned int sel, unsigned char flags);

// Timer Interrupt Handler Declaration
void timer_interrupt_handler();

#endif
