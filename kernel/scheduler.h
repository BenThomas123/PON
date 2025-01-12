#ifndef SCHEDULER_H
#define SCHEDULER_H

/* Scheduler Initialization */
void scheduler_init();

/* Add a Task to the Scheduler */
void scheduler_add_task(void (*task)(), int interval_ms);

/* Run Scheduled Tasks */
void scheduler_run();

/* Increment Scheduler Ticks (called by timer interrupt) */
void scheduler_increment_ticks();

#endif /* SCHEDULER_H */
