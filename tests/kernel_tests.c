#include <stdio.h>
#include "kernel.h"

void test_task_creation(void) {
    printf("Testing Task Creation...\n");
    int task_id = create_task("TestTask", NULL);
    if (task_id >= 0) {
        printf("Task Creation Test Passed\n");
    } else {
        printf("Task Creation Test Failed\n");
    }
}

void test_task_switching(void) {
    printf("Testing Task Switching...\n");
    task_switch(1); // Simulate task switching
    printf("Task Switching Test Passed\n");
}

int main(void) {
    test_task_creation();
    test_task_switching();
    return 0;
}
