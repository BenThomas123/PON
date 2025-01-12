// gdt.h

#ifndef GDT_H
#define GDT_H

void gdt_init();
void gdt_set_entry(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran);

#endif
