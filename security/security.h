#ifndef SECURITY_H
#define SECURITY_H

#include <stddef.h>

/* Authentication */
int authenticate_user(const char *username, const char *password);

/* Encryption */
void encrypt_data(const char *input, char *output, const char *key);
void decrypt_data(const char *input, char *output, const char *key);

/* Key Store */
int add_key(const char *key);
const char *get_key(int index);

/* Secure Boot */
void secure_boot(void);
int verify_firmware(const char *firmware_hash);

/* TLS */
int tls_init(void);
int tls_handshake(void);
int tls_send(const char *data, size_t len);
int tls_receive(char *buffer, size_t max_len);

#endif /* SECURITY_H */
