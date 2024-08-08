/*
    Condição            |   Probabilidade   |  Nível de Gravidade   |   Range   |
    Saúde Normal        |   0.3             |   1                   |    0 - 29 |
    Bronquite           |   0.2             |   2                   |   30 - 49 |
    Pneumonia           |   0.1             |   3                   |   50 - 59 |
    COVID               |   0.1             |   4                   |   60 - 69 |
    Embolia pulmonar    |   0.05            |   4                   |   70 - 74 |
    Derrame pleural     |   0.05            |   4                   |   75 - 79 |
    Fibrose pulmonar    |   0.05            |   5                   |   80 - 84 |
    Tuberculose         |   0.05            |   5                   |   85 - 89 |
    Câncer de pulmão    |   0.1             |   6                   |   90 - 99 |
*/

#include "condition.h"
#include "functions.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

struct condition{
    char *name;
    // float prob;
    int gravity;
} condition;

Condition *create_condition(char *name, int gravity){
    Condition *new_condition = (Condition *)malloc(sizeof(Condition));

    if(new_condition == NULL){
        // Mensagem de erro
        printf("\nErro.\nNao foi possível alocar memória para a condição deste paciente");
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
    }   

    new_condition->name = strdup(name);
    new_condition->gravity = gravity;

    return new_condition;
}

void destroy_condition(Condition *condition){
    free(condition);
}

char *get_condition_name(Condition *condition){
    return condition->name;
}

int get_condition_gravity(Condition *condition){
    return condition->gravity;
}

Condition *get_condition(){
    char *name;
    int gravity;

    int rng = get_random_number(99); // 0 até 99

    if(rng <= 29) {
        name = "Saúde Normal";
        gravity = 1;
    }
    else if(rng >= 30 && rng <= 49){
        name = "Bronquite";
        gravity = 2;
    }
    else if(rng >= 50 && rng <= 59){
        name = "Pneumonia";
        gravity = 3;
    }
    else if(rng >= 60 && rng <= 69){
        name = "COVID";
        gravity = 4;
    }
    else if(rng >= 70 && rng <= 74){
        name = "Embolia Pulmonar";
        gravity = 4;
    }
    else if(rng >= 75 && rng <= 79){
        name = "Derrame Pleural";
        gravity = 4;
    }
    else if(rng >= 80 && rng <= 84){
        name = "Fibrose Pulmonar";
        gravity = 5;
    }
    else if(rng >= 85 && rng <= 89){
        name = "Tuberculose";
        gravity = 5;
    }
    else if(rng >= 89 && rng <= 99){
        name = "Câncer de Pulmão";
        gravity = 6;
    }

    return create_condition(name, gravity);
}

void print_condition(Condition *condition){
    printf("Condição: %s, Gravidade: %d\n", get_condition_name(condition), get_condition_gravity(condition));
}