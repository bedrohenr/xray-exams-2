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

// Enfileira um ponteiro Exame com prioridade da variável gravidade da estrutura Condition.
void q_enqueue_exam_prio(Queue *q, StructType type, void *p) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->info = p;
    node->type = type;
    node->next = NULL;

    // Atribui o nível de gravidade da Condition do novo Exame a ser inserido
    int new_exam_gravity = get_exam_condition_gravity(p);

    // Checa se a fila está vazia.
    if(q_is_empty(q)){
        q_enqueue(q, type, p); // Caso esteja, enfileira normalmente.
    } else{
        // Vars
        Exam *exam; // Exame atual no loop.
        int gravity; // Nível de gravidade do exame atual.
        QueueNode *prev_ptr = NULL; // Armazena o ponteiro prévio do loop.

        for(QueueNode *ptr = q->front; ptr != NULL; ptr = ptr->next){
            if(ptr == NULL){
                q_enqueue(q, type, ptr);
                return;
            
            }
            exam = ptr->info;
            gravity = get_exam_condition_gravity(exam);
            
            // Testa o nível de gravidade do novo exame e o atual do loop.
            if(new_exam_gravity > gravity){
                // Checa se irá ser o primeiro da lista.
                if(prev_ptr == NULL){
                    q->front = node;
                    node->next = ptr;
                } else { // Não será o primeiro da lista.
                    prev_ptr->next = node;
                    node->next = ptr;
                }

                return; // Finaliza a execução da função.
            }
            prev_ptr = ptr; // Atribuição para o ponteiro anterior.
        }
        // Caso nao tenha gravidade maior que nenhum outro.
        // Será enfileirado ao final.
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