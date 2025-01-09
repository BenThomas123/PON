/* boot.c - Peripheral Initialization and Kernel Handoff for ESP32 */

#include "boot.h"

/* ========================== */
/* ===== UART FUNCTIONS ===== */
/* ========================== */

/* Initialize UART Peripheral */
void uart_init(void) {
    UART_CONF0 = 0x00000000;  /* Default: 8 data bits, no parity, 1 stop bit */
    UART_CLKDIV = 0x0000004E; /* Baud rate divisor for 115200 baud at 80 MHz */
}

/* Send a single character via UART */
void uart_send_char(char c) {
    /* Timeout counter */
    int timeout = 1000000;

    /* Wait until the UART TX FIFO is empty or timeout occurs */
    while (!(UART_STATUS & UART_TXFIFO_EMPTY) && --timeout) {}

    /* Write character to UART FIFO if no timeout */
    if (timeout) {
        UART_FIFO = c;
    }
}

/* Send a string via UART */
void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

/* ========================== */
/* ===== GPIO FUNCTIONS ===== */
/* ========================== */

/* Initialize GPIO Peripheral */
void gpio_init(void) {
    GPIO_ENABLE |= (1 << STATUS_LED_PIN); /* Enable STATUS_LED_PIN as output */
    GPIO_OUT &= ~(1 << STATUS_LED_PIN);   /* Ensure LED is off initially */
}

/* Set GPIO Pin Level */
void gpio_set_level(uint32_t pin, int level) {
    if (level) {
        GPIO_OUT |= (1 << pin);  /* Set pin HIGH */
    } else {
        GPIO_OUT &= ~(1 << pin); /* Set pin LOW */
    }
}

/* Blink LED for Diagnostics */
void gpio_blink_led(int times, int delay_ms) {
    for (int i = 0; i < times; i++) {
        gpio_set_level(STATUS_LED_PIN, 1); /* LED ON */
        for (volatile int j = 0; j < delay_ms * 1000; j++); /* Delay */
        
        gpio_set_level(STATUS_LED_PIN, 0); /* LED OFF */
        for (volatile int j = 0; j < delay_ms * 1000; j++); /* Delay */
    }
}

/* Check if Safe Mode Button is Pressed */
int gpio_check_safe_mode(void) {
    return (GPIO_IN >> SAFE_MODE_PIN) & 1; /* Return state of SAFE_MODE_PIN */
}

/* ========================= */
/* === BOOTLOADER MAIN === */
/* ========================= */

void bootloader_main(void) {
    /* Initialize Peripherals */
    uart_init();
    gpio_init();

    /* Indicate Bootloader is Running */
    gpio_set_level(STATUS_LED_PIN, 1);
    uart_send_string("Bootloader Initialized\n");

    /* Check Safe Mode Trigger */
    if (gpio_check_safe_mode()) {
        uart_send_string("Safe Mode Detected. Entering Safe State...\n");
        gpio_blink_led(5, 500); /* Blink 5 times for Safe Mode */
        while (1); /* Stay in Safe Mode */
    }

    /* Blink Once to Indicate Normal Boot */
    gpio_blink_led(1, 500);

    /* Validate Kernel Entry Point */
    uart_send_string("Validating Kernel...\n");
    if (*(volatile uint32_t *)KERNEL_ENTRY_ADDRESS == 0xFFFFFFFF) {
        uart_send_string("Error: Invalid Kernel at Entry Point\n");
        while (1) {
            gpio_set_level(STATUS_LED_PIN, 0);
            for (volatile int i = 0; i < 100000; i++);
            gpio_set_level(STATUS_LED_PIN, 1);
            for (volatile int i = 0; i < 100000; i++);
        }
    }

    /* Handoff to Kernel */
    uart_send_string("Loading Kernel...\n");
    void (*kernel_entry)(void) = (void (*)(void)) KERNEL_ENTRY_ADDRESS;
    kernel_entry();

    /* Error State - If Kernel Returns */
    while (1) {
        uart_send_string("Error: Kernel Returned Unexpectedly!\n");
        gpio_blink_led(2, 1000); /* Blink Twice for Error */
    }
}
