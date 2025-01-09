// idt.c

#include "idt.h"

typedef struct idt_entry {
    uint16_t base_low;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
};

typedef struct idt_ptr{
    uint16_t limit;
    uint32_t base;
};


// Define the IDT and pointer
struct idt_entry idt[256];
struct idt_ptr idtp;

// External assembly function to load IDT
extern void idt_load();

// Timer Interrupt Handler (IRQ0)
void timer_interrupt_handler() {
    static uint32_t tick = 0;
    tick++;

    // Clear Timer Interrupt (ESP32-Specific Code Example)
    // Assuming TIMERG0 is the relevant timer group
    // Adjust based on your ESP32 timer registers
    *((volatile uint32_t*)0x3FF5F004) = 1; // Clear Timer 0 Interrupt (example register)

    // Placeholder UART debug output
    // uart_write("Timer Tick: ", tick); (Implement if UART is ready)
}

// Set an entry in the IDT
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = (base & 0xFFFF);
    idt[num].base_high = (base >> 16) & 0xFFFF;

    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

// Initialize the Interrupt Descriptor Table (IDT)
void idt_init() {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;

    // Clear all entries
    for (int i = 0; i < 256; i++) {
        idt_set_gate(i, 0, 0, 0);
    }

    // Setup Timer Interrupt Handler (IRQ0 maps to Interrupt Vector 32)
    idt_set_gate(32, (uint32_t)timer_interrupt_handler, 0x08, 0x8E);

    // Load the IDT
    idt_load();
}

// Example Kernel Initialization Function
void kernel_init() {
    idt_init();
}
