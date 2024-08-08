#include "queue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct queue {
    QueueNode *front;
    QueueNode *rear;
};

struct queue_node {
    void* info;
    StructType type;
    QueueNode *next;
};

Queue *q_create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    return q;
}

int q_is_empty(Queue *q) {
    return q->front == NULL;
}

void q_enqueue(Queue *q, StructType type, void *p) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->info = p;
    node->type = type;
    node->next = NULL;

    if(q_is_empty(q))
        q->front = node;
    else
        q->rear->next = node;

    q->rear = node;
}

void* q_dequeue(Queue *q) {
    assert(!q_is_empty(q));

    void *v = q->front->info;
    QueueNode *p = q->front;

    if(q->front != q->rear)
        q->front = q->front->next;
    else
        q->front = q->rear = NULL;

    free(p);
    return v;
}

void q_free(Queue *q) {
    QueueNode *p = q->front;
    
    while(p != NULL) {
        QueueNode *t = p->next;
        free(p);
        p = t;
    }

    free(q);
}

void q_print(Queue *q) {
    for(QueueNode *p = q->front; p != NULL; p = p->next)
        print_by_struct_type(p->type, p->info);

    printf("\n");
}