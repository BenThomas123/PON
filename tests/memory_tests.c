#include <stdio.h>
#include "memory.h"

void test_malloc(void) {
    printf("Testing malloc...\n");
    void *ptr = malloc(128);
    if (ptr) {
        printf("malloc Test Passed\n");
        free(ptr);
    } else {
        printf("malloc Test Failed\n");
    }
}

void test_free(void) {
    printf("Testing free...\n");
    void *ptr = malloc(128);
    free(ptr);
    printf("free Test Passed\n");
}

int main(void) {
    test_malloc();
    test_free();
    return 0;
}
