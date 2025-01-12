#include "scheduler.h"
#include <cstddef>

typedef struct {
    void (*task)();
    int interval_ms;
    int time_remaining;
} Task;

#define MAX_TASKS 10
static Task tasks[MAX_TASKS];
static int task_count = 0;
static int tick_count = 0;

void scheduler_init() {
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].task = NULL;
    }
}

void scheduler_add_task(void (*task)(), int interval_ms) {
    if (task_count < MAX_TASKS) {
        tasks[task_count].task = task;
        tasks[task_count].interval_ms = interval_ms;
        tasks[task_count].time_remaining = interval_ms;
        task_count++;
    }
}

void scheduler_increment_ticks() {
    tick_count++;
}

void scheduler_run() {
    for (int i = 0; i < task_count; i++) {
        tasks[i].time_remaining -= tick_count;
        if (tasks[i].time_remaining <= 0) {
            tasks[i].task(); // Execute the task
            tasks[i].time_remaining = tasks[i].interval_ms; // Reset time_remaining
        }
    }
    tick_count = 0; // Reset tick count after processing
}
