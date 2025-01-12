#ifndef POWER_H
#define POWER_H

#define MAX_NODES 10

/* Energy Monitor Functions */
void energy_monitor_init(void);
void energy_monitor_update(float usage);
float energy_monitor_get_usage(void);
void energy_monitor_reset(void);

/* Node Power Management Functions */
typedef enum {
    NODE_OFF,
    NODE_ON,
    NODE_SLEEP
} NodeState;

void power_nodes_init(void);
void power_node_set_state(int node_id, NodeState state);
NodeState power_node_get_state(int node_id);

/* Sleep Functions */
void enter_sleep_mode(void);
void exit_sleep_mode(void);

#endif /* POWER_H */
