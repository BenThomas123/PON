#include "lib.h"
#include <vcruntime.h>

void *malloc(size_t size) {
    // Simple example of static memory allocation
    static char memory_pool[1024];
    static size_t used = 0;

    if (used + size > sizeof(memory_pool)) {
        return NULL; // Out of memory
    }

    void *ptr = &memory_pool[used];
    used += size;
    return ptr;
}

void free(void *ptr) {
    // No-op for this simple example
}

int rand(void) {
    static unsigned int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 32768;
}

void srand(unsigned int new_seed) {
    seed = new_seed;
}
