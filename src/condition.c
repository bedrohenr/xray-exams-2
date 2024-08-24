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
#include "definitions.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

// Definição da struct Condition
struct condition{
    int id;
    char *name;
    int gravity;
} condition;

// Cria a Condition
Condition* create_condition(int id, const char *name, int gravity){
    Condition *new_condition = (Condition *)malloc(sizeof(Condition));

    // Alocação de memória
    check_malloc(new_condition, "\nErro.\nNao foi possível alocar memória para esta Condition.");

    if(validate_int(id, "Condition id")) 
        new_condition->id = id;
    if(validate_string(name, "Condition name"))  
        new_condition->name = strdup(name); // Reserva espaço de armazenamento para uma cópia da string name
    if(validate_int(gravity, "Condition gravity"))
        new_condition->gravity = gravity;

    return new_condition;
}

// Remove a alocação de memória do ponteiro Condition
void destroy_condition(Condition *condition){
    free(condition);
}

// Retorna o id da Condition
int get_condition_id(const Condition *condition){
    return condition->id;
}

// Retorna o nome da Condition
char* get_condition_name(const Condition *condition){
    return condition->name;
}

// Retorna o nome da Condition
char* get_condition_name_by_id(int id){
    char* condition_names[] = {"Saúde Normal","Bronquite","Pneumonia","COVID","Embolia Pulmonar","Derrame Pleural", "Fibrose Pulmonar","Tuberculose","Câncer de Pulmão"};

    return condition_names[id - 1];
}

// Retorna a gravidade da Condition
int get_condition_gravity(const Condition *condition){
    return condition->gravity;
}

// Retorna uma nova Condition escolhida pela probabilidade definida.
Condition* get_condition(){
    int id, gravity;
    char *name;

    // Gera um número de 0 até 19
    int rng = get_random_number(RNG_DISTRIBUTION); 

    // if com suas distribuições com a probilidade e número total definido
    if(rng>= I_CONDITION_L && rng <= I_CONDITION_H) {
        id = 1; // Saúde Normal
        gravity = 1;
    }
    else if(rng >= II_CONDITION_L && rng <= II_CONDITION_H){
        id = 2; // Bronquite
        gravity = 2;
    }
    else if(rng >= III_CONDITION_L && rng <= III_CONDITION_H){
        id = 3; // Pneumonia
        gravity = 3;
    }
    else if(rng >= IV_CONDITION_L && rng <= IV_CONDITION_H){
        id = 4; // COVID
        gravity = 4;
    }
    else if(rng >= V_CONDITION_L && rng <= V_CONDITION_H){
        id = 5; // Embolia Pulmonar
        gravity = 4;
    }
    else if(rng >= VI_CONDITION_L && rng <= VI_CONDITION_H){
        id = 6; // Derrame Pleural
        gravity = 4;
    }
    else if(rng >= VII_CONDITION_L && rng <= VII_CONDITION_H){
        id = 7; // Fibrose Pulmonar
        gravity = 5;
    }
    else if(rng >= VIII_CONDITION_L && rng <= VIII_CONDITION_H){
        id = 8; // Tuberculose
        gravity = 5;
    }
    else if(rng >= IX_CONDITION_L && rng <= IX_CONDITION_H){
        id = 9; // Câncer de Pulmão
        gravity = 6;
    }

    name = get_condition_name_by_id(id);
    // Utiliza a função create usando os parametros definidos por chance
    return create_condition(id, name, gravity);
}

// Imprime a Condition na tela
void print_condition(const Condition *condition){
    printf("Condição: %s, Gravidade: %d\n", get_condition_name(condition), get_condition_gravity(condition));
}

// Retorna uma string com as propriedades relevantes da Condition para inserir no arquivo
char* condition_output(const Condition *condition){
    char *output = (char *)malloc(sizeof(char) * 16); // Alocação de memória para novo ponteiro string
    sprintf(output, "%s", get_condition_name(condition)); // Preenche a string
    return output; // Retorna o ponteiro
}