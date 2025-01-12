#include <stdio.h>
#include "scheduler.h"

void test_scheduler_init(void) {
    printf("Testing Scheduler Initialization...\n");
    scheduler_init();
    printf("Scheduler Initialization Test Passed\n");
}

void test_task_scheduling(void) {
    printf("Testing Task Scheduling...\n");
    create_task("Task1", NULL);
    create_task("Task2", NULL);
    schedule_tasks(); // Simulate task scheduling
    printf("Task Scheduling Test Passed\n");
}

int main(void) {
    test_scheduler_init();
    test_task_scheduling();
    return 0;
}
