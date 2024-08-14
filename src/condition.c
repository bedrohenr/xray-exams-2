/*
    Condição            |   Probabilidade   |  Nível de Gravidade   |   Range   |
    Saúde Normal        |   0.3             |   1                   |    0 - 5  |
    Bronquite           |   0.2             |   2                   |    6 - 9  |
    Pneumonia           |   0.1             |   3                   |   10 - 11 |
    COVID               |   0.1             |   4                   |   12 - 13 |
    Embolia pulmonar    |   0.05            |   4                   |   14      |
    Derrame pleural     |   0.05            |   4                   |   15      |
    Fibrose pulmonar    |   0.05            |   5                   |   16      |
    Tuberculose         |   0.05            |   5                   |   17      |
    Câncer de pulmão    |   0.1             |   6                   |   18 - 10 |
                                                            Total:  |    0 - 19 |
*/

#include "condition.h"
#include "functions.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

struct condition{
    int id;
    char *name;
    // float prob;
    int gravity;
} condition;

Condition* create_condition(int id, char *name, int gravity){
    Condition *new_condition = (Condition *)malloc(sizeof(Condition));

    if(new_condition == NULL){
        // Mensagem de erro
        printf("\nErro.\nNao foi possível alocar memória para a condição deste paciente");
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
    }   

    new_condition->id = id;
    new_condition->name = strdup(name);
    new_condition->gravity = gravity;

    return new_condition;
}

void destroy_condition(Condition *condition){
    free(condition);
}

int get_condition_id(Condition *condition){
    return condition->id;
}

char* get_condition_name(Condition *condition){
    return condition->name;
}

int get_condition_gravity(Condition *condition){
    return condition->gravity;
}

Condition* get_condition(){
    int id, gravity;
    char *name;

    // Gera um número de 0 até 19
    int rng = get_random_number(19); 

    if(rng <= 5) {
        id = 1;
        name = "Saúde Normal";
        gravity = 1;
    }
    else if(rng >= 6 && rng <= 9){
        id = 2;
        name = "Bronquite";
        gravity = 2;
    }
    else if(rng >= 10 && rng <= 11){
        id = 3;
        name = "Pneumonia";
        gravity = 3;
    }
    else if(rng >= 12 && rng <= 13){
        id = 4;
        name = "COVID";
        gravity = 4;
    }
    else if(rng == 14){
        id = 5;
        name = "Embolia Pulmonar";
        gravity = 4;
    }
    else if(rng >= 15){
        id = 6;
        name = "Derrame Pleural";
        gravity = 4;
    }
    else if(rng >= 16){
        id = 7;
        name = "Fibrose Pulmonar";
        gravity = 5;
    }
    else if(rng >= 17){
        id = 8;
        name = "Tuberculose";
        gravity = 5;
    }
    else if(rng >= 18 && rng <= 19){
        id = 9;
        name = "Câncer de Pulmão";
        gravity = 6;
    }

    return create_condition(id, name, gravity);
}

void print_condition(Condition *condition){
    printf("Condição: %s, Gravidade: %d\n", get_condition_name(condition), get_condition_gravity(condition));
}

char* condition_output(Condition *condition){
    char *output = (char *)malloc(sizeof(char) * 32);
    // sprintf(output, "Condição: %s, Gravidade: %d\n", get_condition_name(condition), get_condition_gravity(condition));
    sprintf(output, "%s", get_condition_name(condition));
    return output;
}