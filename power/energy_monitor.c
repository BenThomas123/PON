#include "power.h"
#include <stdio.h>

/* Simulated energy usage data */
static float current_energy_usage = 0.0;

/* Initialize energy monitoring */
void energy_monitor_init(void) {
    printf("Energy Monitor Initialized\n");
    current_energy_usage = 0.0;
}

/* Update energy usage */
void energy_monitor_update(float usage) {
    current_energy_usage += usage;
    printf("Updated energy usage: %.2f mWh\n", current_energy_usage);
}

/* Get current energy usage */
float energy_monitor_get_usage(void) {
    return current_energy_usage;
}

/* Reset energy usage */
void energy_monitor_reset(void) {
    current_energy_usage = 0.0;
    printf("Energy usage reset to 0.0 mWh\n");
}
