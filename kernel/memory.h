#ifndef MEMORY_H
#define MEMORY_H

#include "esp_system.h"
#include <stddef.h>

// Initialize memory management
void memory_init();

// Dynamic memory allocation
void *memory_alloc(size_t size);
void memory_free(void *ptr);
void *memory_realloc(void *ptr, size_t new_size);

// Heap diagnostics
size_t memory_get_free_heap_size();
size_t memory_get_largest_free_block();
void memory_print_usage();

// PSRAM memory allocation
void *memory_alloc_psram(size_t size);

// RTC memory management
void memory_save_to_rtc(void *data, size_t size);
void memory_load_from_rtc(void *buffer, size_t size);

#endif /* MEMORY_H */
