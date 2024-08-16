#include "report.h"
#include "definitions.h"
#include "functions.h"

#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura Report
struct report {
    int id;
    int exam_id;
    Condition *condition;
    struct tm *timestamp;
} report;

// Cria um novo Laudo, alocando memória para a estrutura e retornando um ponteiro para a estrutura criada. 
Report* create_report(int id, int exam_id, Condition *condition, struct tm *timestamp){
    Report *new_report = (Report *)malloc(sizeof(Report));

    // Verificações das variáveis antes das atribuições.
    if(validate_id(id, "Report id"))
        new_report->id = id;
    if(validate_id(exam_id, "Report exam_id"))
        new_report->exam_id = exam_id;
    if(validate_time(timestamp, "Report timestamp"))
        new_report->timestamp = timestamp;

    new_report->condition = condition;

    // Escreve novo registro no arquivo txt.
    db_save(TYPE_REPORT, report_output(new_report));

    return new_report; // Retorna o ponteiro.
}

// Libera a memória do Report.
void destroy_report(Report *report){
    // Libera a memória do Condition antes.
    destroy_condition(get_report_condition(report));
    free(report);
}

// Retorna o número identificador do Report
int get_report_id(const Report *report){
    return report->id;
}

// Retorna o número identificador do Exame associado ao Report. 
int get_report_exam_id(const Report *report){
    return report->exam_id;
}

// Retorna a Condition associada ao Report.
Condition* get_report_condition(const Report *report){
    return report->condition;
}

// Retorna a Data/Hora de realização do Report. 
struct tm* get_report_time(const Report *report){
    return report->timestamp;
}

// Retorna a Data/Hora de realização do Report em string.
char* get_report_time_string(const Report *report){
    return asctime(get_report_time(report));
}

// Gera um número aleatório e decide se mudará a Condition do Report ou não.
void check_condition(Report *report){
    int rng = get_random_number(10); // Recebe um número gerado aleatoriamento de 0 a 10
    if(rng > 8) 
        change_condition(report); // Gera aleatóriamente outra Condition
}

// Gera uma nova Condition, mudando a atual do Report.
void change_condition(Report *report){
    Condition *condition = get_report_condition(report);
    int last_condition_id = get_condition_id(condition); // Salva o id da Condition anterior
    int new_condition_id;

    do {
        destroy_condition(condition); // Libera a memória da condition anterior
        condition = get_condition(); // Recebe nova Condition
        new_condition_id = get_condition_id(condition); // Obtem o id da nova Condition
    } while (new_condition_id == last_condition_id); // Repete o processo de id nova Condition == id Condition anterior

    // Obtém nova Condition diferente.
    report->condition = condition;
}

// Imprime na tela as propriedades do Report passado no argumento.
void print_report(const Report *report){
    printf("Laudo\nId do Laudo: %d\n", get_report_id(report));
    printf("Id do Exame: %d\n", get_report_exam_id(report));
    print_condition(get_report_condition(report));
    printf("Laudo gerado em: %s", get_report_time_string(report)); 
}

// Retorna uma string das propriedades do Report passado no argumento.
char* report_output(const Report *report){
    char *output = (char *)malloc(sizeof(char) * 128); // Aloca memória para o ponteiro
    // Estrutura da string
    sprintf(output, "%d,%d,%s,%s", get_report_id(report), get_report_exam_id(report), condition_output(get_report_condition(report)), get_timestamp_from_datetime(get_report_time(report)));

    return output; // Retorna o ponteiro
}