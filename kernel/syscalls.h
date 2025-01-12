#ifndef SYSCALL_H
#define SYSCALL_H

/* Function Prototypes */
void syscall_init(void);
void register_syscall(int syscall_number, void *function);
void syscall_dispatcher(int syscall_number, int arg1, int arg2, int arg3);

#endif /* SYSCALL_H */
