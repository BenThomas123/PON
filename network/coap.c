#include "network.h"
#include <stdio.h>

/* Send a CoAP message */
int coap_send(const char *message, const char *address, int port) {
    printf("CoAP message sent to %s:%d -> %s\n", address, port, message);
    return 0; // Success
}

/* Receive a CoAP message */
int coap_receive(char *buffer, size_t max_len) {
    snprintf(buffer, max_len, "CoAP response received");
    printf("CoAP message received: %s\n", buffer);
    return 0; // Success
}
