#ifndef REPORT_H
#define REPORT_H

#include "condition.h"

#include <time.h>

typedef struct report Report;

/**
 * Cria um novo Laudo, alocando memória para a estrutura e retornando um ponteiro para a estrutura criada. 
 *
 * @param id  Número identificador do Report.
 * @param exam_id  Número identificador do exame associado ao Report.
 * @param condition  Condition associada ao Report.
 * @param timestamp  Data/Hora de realização do Report.
 * 
 * @return Ponteiro para o Report recém criado com os parâmetros.
 */
Report* create_report(int id, int exam_id, Condition *condition, struct tm *timestamp);

/**
 * Libera a memória alocada a estrutura passada no argumento
 *
 */
void destroy_report(Report *report);

/**
 * Retorna o número identificador do Report.
 * 
 * @param report Ponteiro para a estrutura Report.
 * 
 * @return Número identificador do Report passado no argumento.
 */
int get_report_id(const Report *report);

/**
 * Retorna o número identificador do Exame associado ao Report. 
 * *
 * @param report Ponteiro para a estrutura Report.
 * 
 * @return Número identificador do Exame associado ao Report.
 */
int get_report_exam_id(const Report *report);

/**
 * Retorna a Condition associada ao Report. 
 * *
 * @param report Ponteiro para a estrutura Report.
 * 
 * @return Ponteiro para a estrutura Condition associada ao Report.
 */
Condition* get_report_condition(const Report *report);

/**
 * Retorna a Data/Hora de realização do Report. 
 * *
 * @param report Ponteiro para a estrutura Report.
 * 
 * @return Datetime da hora de realização do Report.
 */
struct tm* get_report_time(const Report *report);

/**
 * Retorna a Data/Hora de realização do Report em string.
 * 
 * @param report Ponteiro para a estrutura Report.
 * 
 * @return String do Datetime da hora de realização do Report.
 */
char* get_report_time_string(const Report *report);

/**
 * Gera um número aleatório e decide se mudará a Condition do Report ou não.
 * *
 * @param report Ponteiro para a estrutura Report.
 */
void check_condition(Report *report);

/**
 * Gera uma nova Condition, mudando a atual do Report.
 * 
 * @param report Ponteiro para a estrutura Report.
 */
void change_condition(Report *report);

/**
 * Imprime na tela as propriedades do Report passado no argumento.
 * 
 * @param report Ponteiro para a estrutura Report.
 */
void print_report(const Report *report);

/**
 * Retorna uma string das propriedades do Report passado no argumento.
 * *
 * @param report Ponteiro para a estrutura Report.
 * 
 * @returns String com as propriedades do Report.
 */
char* report_output(const Report *report);

#endif