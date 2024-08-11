#ifndef CONDITION
#define CONDITION

typedef struct condition Condition;

Condition* create_condition(int id, char *name, int gravity);

void destroy_condition(Condition *condition);

int get_condition_id(Condition *condition);

char* get_condition_name(Condition *condition);

int get_condition_gravity(Condition *condition);

Condition* get_condition();

void print_condition(Condition *condition);

char* condition_output(Condition *condition);

#endif