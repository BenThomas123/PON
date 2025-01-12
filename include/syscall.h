#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>

/* System Call Numbers */
#define SYSCALL_PRINT_STRING 0
#define SYSCALL_TOGGLE_LED 1
#define SYSCALL_ALLOCATE_MEMORY 2

/* System Call Interface */
int syscall(int syscall_number, ...);

#endif /* SYSCALL_H */
