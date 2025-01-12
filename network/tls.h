#ifndef TLS_H
#define TLS_H

#include <stddef.h>

/* TLS Functions */
int tls_init(void);
int tls_handshake(void);
int tls_send(const char *data, size_t len);
int tls_receive(char *buffer, size_t max_len);

#endif /* TLS_H */
