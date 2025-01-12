#ifndef LIB_H
#define LIB_H

/* Math Functions */
double sqrt(double x);
double pow(double base, double exp);

/* Standard I/O Functions */
int printf(const char *format, ...);
int scanf(const char *format, ...);

/* Standard Library Functions */
void *malloc(size_t size);
void free(void *ptr);
int rand(void);
void srand(unsigned int seed);

/* String Functions */
size_t strlen(const char *str);
char *strcpy(char *dest, const char *src);
int strcmp(const char *str1, const char *str2);

#endif /* LIB_H */
