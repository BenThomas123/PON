#include "uart.h"
#ifndef INTERRUPT_H
#define INTERRUPT_H

/* Function Prototypes */
void interrupt_init(void);
void register_interrupt_handler(int interrupt_number, void (*handler)(void));
void interrupt_dispatcher(int interrupt_number);

#endif /* INTERRUPT_H */
