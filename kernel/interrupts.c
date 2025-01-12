#include "interrupts.h"
#include "uart.h"

/* Interrupt Vector Table (IVT) */
#define INTERRUPT_VECTOR_BASE 0x40000000

/* Interrupt Service Routine (ISR) table */
static void (*isr_table[32])(void); /* Supports up to 32 interrupts */

/* Default handler for unregistered interrupts */
void default_handler(void) {
    uart_send_string("Unhandled Interrupt!\n");
    while (1); /* Trap CPU for debugging */
}

/* Register an interrupt handler */
void register_interrupt_handler(int interrupt_number, void (*handler)(void)) {
    if (interrupt_number < 0 || interrupt_number >= 32) {
        uart_send_string("Invalid interrupt number\n");
        return;
    }
    isr_table[interrupt_number] = handler;
}

/* Interrupt Dispatcher */
void interrupt_dispatcher(int interrupt_number) {
    if (interrupt_number < 0 || interrupt_number >= 32) {
        uart_send_string("Invalid interrupt during dispatch\n");
        return;
    }
    if (isr_table[interrupt_number]) {
        isr_table[interrupt_number](); /* Call the registered ISR */
    } else {
        default_handler();
    }
}

/* Initialize the interrupt system */
void interrupt_init(void) {
    /* Initialize all ISRs to default_handler */
    for (int i = 0; i < 32; i++) {
        isr_table[i] = default_handler;
    }

    /* Set up the Interrupt Vector Base Address (if required by architecture) */
    // Hardware-specific setup, e.g., Xtensa-specific interrupt controller
}

/* Example ISR for Timer Interrupt */
void timer_isr(void) {
    uart_send_string("Timer Interrupt Triggered\n");
    // Handle timer event
}
