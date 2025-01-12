#include "lib.h"

size_t strlen(const char *str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

char *strcpy(char *dest, const char *src) {
    char *original = dest;
    while ((*dest++ = *src++));
    return original;
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
