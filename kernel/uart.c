#include "uart.h"
#include "boot.h"

/* UART Initialization */
void uart_init(void) {
    static int initialized = 0;
    if (initialized) return; /* Avoid re-initializing */
    initialized = 1;

    /* Configure UART for 115200 baud, 8N1 */
    UART_CONF0 = 0x00000000; /* 8 data bits, no parity, 1 stop bit */
    UART_CLKDIV = 0x0000004E; /* Set baud rate divisor */
}

/* Send a single character over UART */
void uart_send_char(char c) {
    while (!(UART_INT_RAW & (1 << 7))) {
        /* Wait for transmit buffer to be empty */
    }
    UART_FIFO = c;
}

/* Send a string over UART */
void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}
