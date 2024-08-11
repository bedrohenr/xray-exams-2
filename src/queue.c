#include "queue.h"

#include "functions.h"
#include "exam.h"

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

int q_size(Queue *q){
    int count = 0;
    for(QueueNode *p = q->front; p != NULL; p = p->next)
        count++;

    return count;
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

void q_enqueue_exam_prio(Queue *q, StructType type, void *p) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->info = p;
    node->type = type;
    node->next = NULL;

    // Exam *new_exam = p;
    int new_exam_gravity = get_exam_condition_gravity(p);

    printf("\n\nEmtpy q: %d\n\n", q_is_empty(q));
    if(q_is_empty(q)){
        printf("\n\nflag empty\n\n\n");
        q_enqueue(q, type, p);
    }
    else{
        Exam *exam, *next_exam;
        int gravity, next_gravity;

        int counter = 0;
        for(QueueNode *ptr = q->front; ptr->next != NULL; ptr = ptr->next){
            if(ptr == NULL || ptr->next == NULL){
                printf("CARALHOOOOOOOO\n");
                q_enqueue(q, type, ptr);
                return;
            
            }
            exam = ptr->info;
            next_exam = ptr->next->info;

            gravity = get_exam_condition_gravity(exam);
            // next_gravity = get_exam_condition_gravity(next_exam);
            
            printf("if grav: %d > %d\n", new_exam_gravity, gravity);
            if(new_exam_gravity > gravity){
                printf("\nINSERTING\n");
                if(counter == 0){
                    q->front = node;
                    node->next = ptr;
                } else {
                    node->next = ptr;
                    ptr->next = next_exam;
                }

                return;
            }
            printf("%d, c: %d\n", new_exam_gravity, counter);
            counter++;
        }
        printf("flag enqueue");
        q_enqueue(q, type, p);
    }

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
        free_by_struct_type(p->type, p->info);
        p = t;
    }

    free(q);
}

void q_print(Queue *q) {
    for(QueueNode *p = q->front; p != NULL; p = p->next)
        print_by_struct_type(p->type, p->info);

    printf("\n");
}