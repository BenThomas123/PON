#ifndef LWIP_H
#define LWIP_H

#include <stddef.h>

/* Initialize LWIP stack */
void lwip_init(void);

/* Send a network packet */
int lwip_send_packet(const char *data, size_t len);

/* Receive a network packet */
int lwip_receive_packet(char *buffer, size_t max_len);

#endif /* LWIP_H */
