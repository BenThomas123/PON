#ifndef UART_H
#define UART_H

/* UART Registers */
#define UART_BASE 0x3FF40000
#define UART_FIFO (*(volatile uint32_t *)(UART_BASE + 0x00)) /* Data FIFO Register */
#define UART_INT_RAW (*(volatile uint32_t *)(UART_BASE + 0x04)) /* Interrupt Status */
#define UART_INT_CLR (*(volatile uint32_t *)(UART_BASE + 0x10)) /* Interrupt Clear */
#define UART_CLKDIV (*(volatile uint32_t *)(UART_BASE + 0x14)) /* Clock Divisor */
#define UART_CONF0 (*(volatile uint32_t *)(UART_BASE + 0x18)) /* Config Register */

void uart_init(void);
void uart_send_char(char c);
void uart_send_string(const char *str);

#endif /* UART_H */
