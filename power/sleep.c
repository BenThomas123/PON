#include "power.h"
#include <stdio.h>
#include <unistd.h> // For sleep function (simulating deep sleep)

/* Enter system-wide sleep mode */
void enter_sleep_mode(void) {
    printf("System entering sleep mode...\n");
    sleep(1); // Simulate deep sleep (1 second)
    printf("System in sleep mode. Minimal power usage.\n");
}

/* Exit system-wide sleep mode */
void exit_sleep_mode(void) {
    printf("Exiting sleep mode...\n");
    // Simulate wake-up logic
    printf("System resumed from sleep mode.\n");
}
