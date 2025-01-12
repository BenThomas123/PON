#ifndef NETWORK_H
#define NETWORK_H

#include <stddef.h>

/* CoAP Functions */
int coap_send(const char *message, const char *address, int port);
int coap_receive(char *buffer, size_t max_len);

/* MQTT Functions */
int mqtt_connect(const char *broker, int port);
int mqtt_publish(const char *topic, const char *message);
int mqtt_subscribe(const char *topic);

/* TCP/IP Functions */
int tcp_connect(const char *address, int port);
int tcp_send(const char *data, size_t len);
int tcp_receive(char *buffer, size_t max_len);

/* TLS Functions */
int tls_init(void);
int tls_handshake(void);
int tls_send(const char *data, size_t len);
int tls_receive(char *buffer, size_t max_len);

#endif /* NETWORK_H */
