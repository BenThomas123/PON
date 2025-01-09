#include "gdt.h"

// Define a GDT entry structure
struct gdt_entry {
    uint16_t limit_low;  /* The starting address of the memory segment */
    uint16_t base_low;   /* Specifies the size of the segment */
    uint8_t base_middle; /* Defines the next 8 bits of the segment’s base address. */
    uint8_t access;      /* Defines access permissions and segment type. */
    uint8_t granularity; /* Controls segment granularity, size, and upper limit bits. */
    uint8_t base_high;   /* Defines the last 8 bits of the segment base address. */
};

// Define the GDT pointer
struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
};

// Define the GDT table and pointer
struct gdt_entry gdt[3];
struct gdt_ptr gp;

// External assembly function to load GDT
extern void gdt_flush(uint32_t);

// Set up a GDT entry
void gdt_set_entry(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = (limit >> 16) & 0x0F;
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

// Initialize GDT
void gdt_init() {
    gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = (uint32_t)&gdt;

    gdt_set_entry(0, 0, 0, 0, 0);                // Null segment
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment

    gdt_flush((uint32_t)&gp);
}
