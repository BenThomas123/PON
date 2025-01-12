#include "syscall.h"
#include "uart.h"
#include "boot.h"

/* System Call Table */
#define MAX_SYSCALLS 16
static void *syscall_table[MAX_SYSCALLS];

/* Invalid System Call Handler */
void syscall_invalid(void) {
    uart_send_string("Invalid System Call\n");
}

/* Register a System Call */
void register_syscall(int syscall_number, void *function) {
    if (syscall_number < 0 || syscall_number >= MAX_SYSCALLS) {
        uart_send_string("Invalid syscall number\n");
        return;
    }
    syscall_table[syscall_number] = function;
}

/* System Call Dispatcher */
void syscall_dispatcher(int syscall_number, int arg1, int arg2, int arg3) {
    if (syscall_number < 0 || syscall_number >= MAX_SYSCALLS || syscall_table[syscall_number] == NULL) {
        syscall_invalid();
        return;
    }

    /* Call the registered system call handler */
    void (*syscall_handler)(int, int, int) = syscall_table[syscall_number];
    syscall_handler(arg1, arg2, arg3);
}

/* Example System Calls */

/* Syscall: Print a String */
void syscall_print_string(int arg1, int arg2, int arg3) {
    const char *str = (const char *)arg1;
    uart_send_string(str);
}

/* Syscall: Toggle GPIO */
void syscall_toggle_gpio(int arg1, int arg2, int arg3) {
    int pin = arg1;
    int state = arg2;
    gpio_set_level(pin, state);
}

/* Initialize the System Call Table */
void syscall_init(void) {
    for (int i = 0; i < MAX_SYSCALLS; i++) {
        syscall_table[i] = syscall_invalid; /* Initialize all to invalid handler */
    }

    /* Register default system calls */
    register_syscall(0, syscall_print_string);
    register_syscall(1, syscall_toggle_gpio);
}
