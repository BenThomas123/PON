#include "network.h"
#include <stdio.h>

/* Establish a TCP connection */
int tcp_connect(const char *address, int port) {
    printf("TCP connection established with %s:%d\n", address, port);
    return 0; // Success
}

/* Send data over TCP */
int tcp_send(const char *data, size_t len) {
    printf("TCP data sent: %.*s\n", (int)len, data);
    return 0; // Success
}

/* Receive data over TCP */
int tcp_receive(char *buffer, size_t max_len) {
    snprintf(buffer, max_len, "TCP data received");
    printf("TCP data received: %s\n", buffer);
    return 0; // Success
}
