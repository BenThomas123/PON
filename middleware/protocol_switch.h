#ifndef PROTOCOL_SWITCH_H
#define PROTOCOL_SWITCH_H

typedef enum {
    PROTOCOL_SLAAC,
    PROTOCOL_DHCPV6
} ProtocolState;

/* Function prototypes */
void protocol_switch_init(ProtocolState initial_protocol);
int protocol_switch(ProtocolState new_protocol);
ProtocolState protocol_get_current(void);

#endif /* PROTOCOL_SWITCH_H */
