#include "security.h"
#include <string.h>

/* XOR-based encryption (for simplicity, not secure for production) */
void encrypt_data(const char *input, char *output, const char *key) {
    size_t input_len = strlen(input);
    size_t key_len = strlen(key);
    for (size_t i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
    output[input_len] = '\0'; // Null-terminate the output
}

/* XOR-based decryption (same as encryption) */
void decrypt_data(const char *input, char *output, const char *key) {
    encrypt_data(input, output, key); // Symmetric decryption
}
