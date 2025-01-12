#include "kernel.h"

/* ========================= */
/* === Kernel Functions === */
/* ========================= */

/* Panic Handler */
void kernel_panic(const char *message) {
    uart_send_string("Kernel Panic: ");
    uart_send_string(message);
    uart_send_string("\nSystem Halted.\n");
    while (1) {
        gpio_blink_led(3, 500); /* Blink LED to indicate panic */
    }
}

/* Kernel Initialization */
void kernel_init() {
    uart_send_string("Initializing Kernel...\n");

    /* Initialize GDT */
    uart_send_string("Setting up GDT...\n");
    gdt_init();

    /* Initialize IDT */
    uart_send_string("Setting up IDT...\n");
    idt_init();

    /* Signal successful initialization */
    gpio_set_level(STATUS_LED_PIN, 1); /* Turn on LED */
    uart_send_string("Kernel Initialization Complete.\n");
}

/* ========================= */
/* ========== LED ========== */
/* ========================= */

void task_blink_led() {
    static int state = 0;
    state = !state;
    gpio_set_level(STATUS_LED_PIN, state); // Toggle LED
    uart_send_string("Task: Blink LED\n");
}

void task_uart_echo() {
    char c = uart_receive_char_nonblocking(); // Non-blocking UART read
    if (c) {
        uart_send_string("Echo: ");
        uart_send_char(c);
        uart_send_string("\n");
    }
}

void task_check_gpio() {
    int button_state = gpio_check_safe_mode();
    if (button_state) {
        uart_send_string("Task: GPIO - Safe Mode Button Pressed\n");
    } else {
        uart_send_string("Task: GPIO - Button Not Pressed\n");
    }
}

/* Kernel Main Function */
void kernel_main() {
    /* Initialize the kernel */
    kernel_init();

    /* Initialize timer */
    uart_send_string("Setting up timer...\n");
    timer_init();

    /* Initialize task scheduler */
    uart_send_string("Initializing task scheduler...\n");
    scheduler_init();

    /* Add kernel tasks */
    uart_send_string("Adding tasks to scheduler...\n");
    scheduler_add_task(task_blink_led, 1000);   // Blink LED every 1000ms
    scheduler_add_task(task_uart_echo, 500);    // Echo UART input every 500ms
    scheduler_add_task(task_check_gpio, 2000);  // Check GPIO every 2000ms

    /* Main Kernel Loop */
    uart_send_string("Entering main loop...\n");
    while (1) {
        /* Run the task scheduler */
        scheduler_run();

        /* Check for user commands */
        char command = uart_receive_char_nonblocking(); // Non-blocking UART read
        if (command) {
            handle_command(command);
        }

        /* Perform idle diagnostics or power-saving operations */
        gpio_set_level(STATUS_LED_PIN, 0); // LED off
        for (volatile int i = 0; i < 100000; i++); // Simulate some delay
        gpio_set_level(STATUS_LED_PIN, 1); // LED on
    }
}
