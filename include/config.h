#ifndef CONFIG_H
#define CONFIG_H

/* System Configuration Parameters */
#define SYSTEM_CLOCK_FREQUENCY 16000000 /* System clock in Hz */
#define MAX_TASKS 16                   /* Maximum number of tasks in the system */
#define STACK_SIZE 4096                /* Default stack size for tasks (in bytes) */
#define HEAP_SIZE 8192                 /* Heap size (in bytes) */

/* UART Configuration */
#define UART_BAUD_RATE 115200

/* File System */
#define FS_MAX_FILES 10                /* Maximum open files in the file system */

/* Debugging */
#define ENABLE_DEBUG 1                 /* Set to 1 to enable debug logging */

#endif /* CONFIG_H */
