#include "stack.h"

struct stack {
    StackNode *top;
};

struct stacknode {
    void info;
    StackNode *next;
};

Stack *stack_create(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;

    return s;
}

int stack_is_empty(Stack *s){
    return s->top == NULL;
}

void stack_push(Stack *s, void *p){
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->info = p;
    node->next = s->top;
    s->top = node;
}

void* stack_top(Stack *s){
    assert(!stack_is_empty(s));

    return s->top->info;
}

void* stack_pop(Stack *s){
    assert(!s_is_empty(s));

    void *v = s->top->info;
    StackNode *p = s->top;
    s->top = s->top->next;
    free(p);
    
    return v;
}

void stack_free(Stack *s){
    StackNode *p = s->top;

    while(p != NULL){
        StackNode *t = p->next;
        free(p);
        p = t;
    }

    free(s);
}

void stack_print(Stack *s){
    for(StackNode *p = s->top; p != NULL; p = p->next)
        printf("%.2f", p->info);

    printf("\n");
}