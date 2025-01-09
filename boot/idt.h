// idt.h

#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// Initialize the Interrupt Descriptor Table
void idt_init();

// Set an entry in the IDT
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

// Timer Interrupt Handler Declaration
void timer_interrupt_handler();

#endif
