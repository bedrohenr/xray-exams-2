#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;
typedef struct stacknode StackNode;

Stack *stack_create();

float stack_pop(Stack *q);

float stack_top(Stack *q);

void *stack_push(Stack *q, void *p);

int stack_is_empty(Stack *q);

void stack_free(Stack *q);

void stack_print(Stack *q);