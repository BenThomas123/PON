#include "security.h"
#include <stdio.h>
#include <string.h>

/* Simulated key store */
#define MAX_KEYS 10
static char key_store[MAX_KEYS][64];
static int key_count = 0;

/* Add a key to the store */
int add_key(const char *key) {
    if (key_count >= MAX_KEYS) {
        printf("Key store full\n");
        return -1; // Failure
    }
    strncpy(key_store[key_count], key, sizeof(key_store[key_count]) - 1);
    key_store[key_count][sizeof(key_store[key_count]) - 1] = '\0'; // Null-terminate
    key_count++;
    printf("Key added to store\n");
    return 0; // Success
}

/* Retrieve a key by index */
const char *get_key(int index) {
    if (index < 0 || index >= key_count) {
        printf("Invalid key index\n");
        return NULL;
    }
    return key_store[index];
}
