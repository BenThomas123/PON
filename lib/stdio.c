#include "lib.h"
#include <stdarg.h> // For variable arguments

int printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;

    while (*format) {
        if (*format == '%' && *(format + 1) == 'd') {
            int value = va_arg(args, int);
            char buffer[16];
            sprintf(buffer, "%d", value);
            count += uart_send_string(buffer); // Example using UART
            format += 2;
        } else {
            uart_send_char(*format); // Example UART function
            count++;
            format++;
        }
    }

    va_end(args);
    return count;
}

int scanf(const char *format, ...) {
    // Simplified scanf (add parsing logic if required)
    return 0;
}
