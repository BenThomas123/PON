#include "memory.h"
#include "esp_system.h"

// Initialize the memory system
void memory_init() {
    // Initialize heap
    esp_heap_caps_init();
    
    // Configure PSRAM if available
    if (esp_psram_is_initialized()) {
        esp_psram_init();
    }
}

// Allocate memory from heap
void* memory_alloc(size_t size) {
    return heap_caps_malloc(size, MALLOC_CAP_DEFAULT);
}

// Free allocated memory
void memory_free(void* ptr) {
    heap_caps_free(ptr);
}

// Print memory usage
void memory_print_usage() {
    printf("Free heap: %u bytes\n", esp_get_free_heap_size());
    printf("Largest free block: %u bytes\n", esp_get_largest_free_block(MALLOC_CAP_DEFAULT));
}

// Allocate memory from PSRAM
void* memory_alloc_psram(size_t size) {
    return heap_caps_malloc(size, MALLOC_CAP_SPIRAM);
}

// Save data to RTC memory
void memory_save_to_rtc(void* data, size_t size) {
    // Copy data to RTC memory
    memcpy(RTC_SLOW_MEM, data, size);
}

// Load data from RTC memory
void memory_load_from_rtc(void* buffer, size_t size) {
    memcpy(buffer, RTC_SLOW_MEM, size);
}
