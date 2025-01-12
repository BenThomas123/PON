#include <stdio.h>
#include "drivers.h"

void test_uart_driver(void) {
    printf("Testing UART Driver...\n");
    uart_init();
    uart_send_char('A');
    printf("UART Driver Test Passed\n");
}

void test_gpio_driver(void) {
    printf("Testing GPIO Driver...\n");
    gpio_init();
    gpio_set_level(1, 1); // Set GPIO pin 1 to HIGH
    printf("GPIO Driver Test Passed\n");
}

int main(void) {
    test_uart_driver();
    test_gpio_driver();
    return 0;
}
