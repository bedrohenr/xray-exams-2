#ifndef CONDITION
#define CONDITION

typedef struct condition Condition;

Condition *create_condition(char *name, int gravity);

char *get_condition_name(Condition *condition);

int get_condition_gravity(Condition *condition);

Condition *get_condition();

void print_condition(Condition *condition);

#endif