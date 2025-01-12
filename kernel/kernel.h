#ifndef KERNEL_H
#define KERNEL_H

#include "uart.h"
#include "gdt.h"
#include "idt.h"
#include "scheduler.h"
#include "timer.h"
#include "boot.h"

/* Kernel Initialization */
void kernel_init();

/* Kernel Panic Handler */
void kernel_panic(const char *message);

/* Kernel Main Function */
void kernel_main();

/* Command Handler */
void handle_command(char command);

void task_blink_led();
void task_uart_echo();
void task_check_gpio();

#endif /* KERNEL_H */
