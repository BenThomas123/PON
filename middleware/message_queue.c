#include "message_queue.h"
#include "stdlib.h"
#include "string.h"

/* Initialize a message queue */
MessageQueue *message_queue_init(int capacity) {
    MessageQueue *queue = malloc(sizeof(MessageQueue));
    if (!queue) return NULL;

    queue->messages = malloc(sizeof(Message) * capacity);
    if (!queue->messages) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

/* Enqueue a message */
int message_queue_enqueue(MessageQueue *queue, const Message *msg) {
    if (queue->size == queue->capacity) {
        return -1; // Queue full
    }

    queue->messages[queue->tail] = *msg;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;

    return 0; // Success
}

/* Dequeue a message */
int message_queue_dequeue(MessageQueue *queue, Message *msg) {
    if (queue->size == 0) {
        return -1; // Queue empty
    }

    *msg = queue->messages[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;

    return 0; // Success
}

/* Free the message queue */
void message_queue_free(MessageQueue *queue) {
    free(queue->messages);
    free(queue);
}
