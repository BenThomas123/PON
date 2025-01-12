#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

typedef struct
{
    int id;
    unsigned char data[256]; // Message payload
} Message;

typedef struct
{
    Message *messages;
    int capacity;
    int size;
    int head;
    int tail;
} MessageQueue;

/* Function prototypes */
MessageQueue *message_queue_init(int capacity);
int message_queue_enqueue(MessageQueue *queue, const Message *msg);
int message_queue_dequeue(MessageQueue *queue, Message *msg);
void message_queue_free(MessageQueue *queue);

#endif /* MESSAGE_QUEUE_H */
