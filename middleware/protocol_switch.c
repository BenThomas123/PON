#include "protocol_switch.h"
#include "stdio.h"

/* Current protocol state */
static ProtocolState current_protocol = PROTOCOL_SLAAC;

/* Initialize protocol switching */
void protocol_switch_init(ProtocolState initial_protocol) {
    current_protocol = initial_protocol;
    printf("Protocol initialized to %s\n",
           current_protocol == PROTOCOL_SLAAC ? "SLAAC" : "DHCPv6");
}

/* Switch protocol */
int protocol_switch(ProtocolState new_protocol) {
    if (current_protocol == new_protocol) {
        return -1; // Already using the desired protocol
    }

    current_protocol = new_protocol;
    printf("Switched protocol to %s\n",
           current_protocol == PROTOCOL_SLAAC ? "SLAAC" : "DHCPv6");

    return 0; // Success
}

/* Get current protocol */
ProtocolState protocol_get_current(void) {
    return current_protocol;
}