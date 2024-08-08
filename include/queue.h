#ifndef QUEUE_H
#define QUEUE_H

#include "definitions.h"

typedef struct queue Queue;
typedef struct queue_node QueueNode;

Queue* q_create();

int q_is_empty(Queue *q);

void q_enqueue(Queue *q, StructType type, void *p);

void* q_dequeue(Queue *q);

void q_free(Queue *q);

void q_print(Queue *q);

#endif