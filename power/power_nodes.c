#include "power.h"
#include <stdio.h>

/* Node power states */
typedef enum {
    NODE_OFF,
    NODE_ON,
    NODE_SLEEP
} NodeState;

/* Example power state management for nodes */
static NodeState node_states[MAX_NODES] = {NODE_OFF};

/* Initialize node power management */
void power_nodes_init(void) {
    for (int i = 0; i < MAX_NODES; i++) {
        node_states[i] = NODE_OFF;
    }
    printf("Power nodes initialized. All nodes are OFF.\n");
}

/* Set node power state */
void power_node_set_state(int node_id, NodeState state) {
    if (node_id < 0 || node_id >= MAX_NODES) {
        printf("Invalid node ID: %d\n", node_id);
        return;
    }

    node_states[node_id] = state;
    printf("Node %d state set to %s\n", node_id,
           state == NODE_OFF ? "OFF" : (state == NODE_ON ? "ON" : "SLEEP"));
}

/* Get node power state */
NodeState power_node_get_state(int node_id) {
    if (node_id < 0 || node_id >= MAX_NODES) {
        printf("Invalid node ID: %d\n", node_id);
        return NODE_OFF;
    }

    return node_states[node_id];
}
