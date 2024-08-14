#ifndef QUEUE_H
#define QUEUE_H

#include "definitions.h"

typedef struct queue Queue;
typedef struct queue_node QueueNode;

/**
 * Cria uma nova fila, alocando memória para a estrutura e retornando-a.
 * 
 * @return Ponteiro para a estrutura Queue
 */
Queue* q_create();

/**
 * Retorna o tamanho da fila.
 * 
 * @param q Ponteiro para a estrutura Queue.
 *  
 * @return Quantidade de elementos na fila.
 */
int q_size(Queue *q);

/**
 * Retorna se não contém elementos na fila.
 * 
 * @param q Ponteiro para a estrutura Queue.
 *  
 * @return 1 se for vazia, 0 se não for.
 */
int q_is_empty(Queue *q);

/**
 * Insere um ponteiro genérico na fila.
 * 
 * @param q Ponteiro para a estrutura Queue.
 * @param type Tipo da estrutura do ponteiro.
 * @param p Ponteiro para a estrutura genérica.
 *  
 */
void q_enqueue(Queue *q, StructType type, void *p);

/**
 * Insere na fila uma estrutura exame, e calcula qual a posição pelo nível de gravidade da Condition do Exame.
 * 
 * @param q Ponteiro para a estrutura Queue.
 * @param type Tipo da estrutura do ponteiro.
 * @param p Ponteiro para a estrutura Exame.
 *  
 */
void q_enqueue_exam_prio(Queue *q, StructType type, void *p);

/**
 * Retira e retorna um ponteiro genérico da fila.
 * 
 * @param q Ponteiro para a estrutura Queue.
 *  
 * @return O ponteiro recém retirado da lista.
 */
void* q_dequeue(Queue *q);

/**
 * Libera toda memória alocada à fila e seus nós.
 * 
 * @param q Ponteiro para a estrutura Queue.
 */
void q_free(Queue *q);

/**
 * Imprime todas as estruturas na fila.
 * 
 * @param q Ponteiro para a estrutura Queue.
 */
void q_print(Queue *q);

#endif