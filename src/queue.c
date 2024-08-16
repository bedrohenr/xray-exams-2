#include "queue.h"

#include "functions.h"
#include "exam.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura QueueNode.
struct queue {
    QueueNode *front;
    QueueNode *rear;
};

// Definição da estrutura QueueNode.
struct queue_node {
    void* info;
    StructType type;
    QueueNode *next;
};

// Cria a fila, alocando memória e a retorna.
Queue *q_create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL; // Inicializa com valores NULL

    return q; // Retorna o ponteiro
}

// Percorre a fila e retorna a quantidade de nodes na fila.
int q_size(const Queue *q){
    int count = 0;
    for(QueueNode *p = q->front; p != NULL; p = p->next) // Loop
        count++;

    return count; // Retorna a quantidade
}

// Retorna se a fila está vazia ou não.
int q_is_empty(const Queue *q) {
    return q->front == NULL;
}

// Enfileira um ponteiro genérico.
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

// Retira o primeiro da fila
void* q_dequeue(Queue *q) {
    assert(!q_is_empty(q)); // Verifica se a lista está vazia.

    void *v = q->front->info; // Faz do segundo da fila, o primeiro
    QueueNode *p = q->front; // Atribui o primeiro da fila

    // Checa se só tem um registro na fila
    if(q->front != q->rear)
        q->front = q->front->next;
    else
        q->front = q->rear = NULL; 

    free(p); // Libera memória
    return v; // Retorna o ponteiro
}

// Libera toda a memória da fila
void q_free(Queue *q) {
    QueueNode *p = q->front;

    // Libera memória até não haver nó algum na fila 
    while(p != NULL) {
        QueueNode *t = p->next;
        // Faz a liberação correta de memória, usando as funções corretas
        free_by_struct_type(p->type, p->info); 
        p = t;
    }

    // Libera memória da Queue
    free(q);
}

// Imprime todos os elementos na fila
void q_print(Queue *q) {
    for(QueueNode *p = q->front; p != NULL; p = p->next)
        // Imprime usando as funções corretas
        print_by_struct_type(p->type, p->info);

    printf("\n");
}