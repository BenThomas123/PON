/* boot.h - ESP32 Bootloader Header */

#ifndef BOOT_H
#define BOOT_H

#include <stdint.h>

/* ========================= */
/* === Peripheral Addresses === */
/* ========================= */

/* UART Base Address for ESP32 */
#define UART_BASE 0x3FF40000

/* UART Registers */
#define UART_FIFO    (*(volatile uint32_t *)(UART_BASE)) /* Data FIFO Register */
#define UART_STATUS  (*(volatile uint32_t *)(UART_BASE + 0x1C)) /* UART Status Register */
#define UART_CLKDIV  (*(volatile uint32_t *)(UART_BASE + 0x14)) /* Baud Rate Divisor */
#define UART_CONF0   (*(volatile uint32_t *)(UART_BASE + 0x18)) /* UART Configuration */

/* UART Status Flags */
#define UART_TXFIFO_EMPTY (1 << 15) /* TX FIFO Empty Flag */

/* GPIO Base Address for ESP32 */
#define GPIO_BASE 0x3FF44000

/* GPIO Registers */
#define GPIO_OUT    (*(volatile uint32_t *)(GPIO_BASE + 0x04)) /* GPIO Output Register */
#define GPIO_ENABLE (*(volatile uint32_t *)(GPIO_BASE + 0x20)) /* GPIO Output Enable Register */
#define GPIO_IN     (*(volatile uint32_t *)(GPIO_BASE + 0x3C)) /* GPIO Input Register */

/* GPIO Pin Definitions */
#define STATUS_LED_PIN 2 /* GPIO Pin 2 for Status LED */
#define SAFE_MODE_PIN  0 /* GPIO Pin 0 for Safe Mode Button */

/* Kernel Entry Address */
#define KERNEL_ENTRY_ADDRESS 0x08004000

/* Stack and Memory Regions (for Assembly Reference) */
extern uint32_t _stack_top;
extern uint32_t _bss_start;
extern uint32_t _bss_end;

/* ========================= */
/* === Function Prototypes === */
/* ========================= */

/* UART Functions */
void uart_init(void);
void uart_send_char(char c);
void uart_send_string(const char *str);

/* GPIO Functions */
void gpio_init(void);
void gpio_set_level(uint32_t pin, int level);
void gpio_blink_led(int times, int delay_ms);
int gpio_check_safe_mode(void);

/* Bootloader Main Entry */
void bootloader_main(void);

#endif /* BOOT_H */
