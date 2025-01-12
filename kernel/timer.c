#include "timer.h"
#include "idt.h"

void timer_interrupt_handler()
{
    uart_send_string("Timer interrupt triggered\n");
    scheduler_increment_ticks(); // Notify the scheduler
}

/* Timer Initialization */
void timer_init()
{
    /* Configure the PIT (Programmable Interval Timer) */
    // Example PIT configuration for 1000Hz
    outb(0x43, 0x36);                        // Command port
    unsigned short divisor = 1193180 / 1000; // 1000 Hz
    outb(0x40, divisor & 0xFF);              // Low byte
    outb(0x40, (divisor >> 8) & 0xFF);       // High byte

    /* Register the timer interrupt handler */
    idt_set_gate(32, (unsigned int)timer_interrupt_handler, 0x08, 0x8E); // IRQ0
}
