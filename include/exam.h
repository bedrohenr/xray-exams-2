#ifndef EXAM
#define EXAM

#include "condition.h"

#include <time.h> // struct tm

typedef struct exam Exam;

/**
 * Cria um novo exame, alocando memória para a estrutura, preenchendo os campos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada.
 *
 * @param id  Número identificador do Exame.
 * @param patient_id  Número identificador do paciente vinculado ao Exame.
 * @param rx_id  Número da máquina de raio-X usada para o Exame.
 * @param time  Timestamp de realização do Exame.
 * 
 * @return Ponteiro para o Exame recém criado com os parâmetros.
 */
Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time);

// 
/**
 * Libera a memória alocada para a estrutura de exame.
 */
void destroy_exam(Exam *exam);

/**
 * Retorna o número de identificação do Exame passado no argumento
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return Número identificador do Exame.
 */
int get_exam_id(const Exam *exam);

/**
 * Retorna a identificação única do paciente associado ao exame.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return Número identificador do paciente do Exame.
 */
int get_exam_patient_id(const Exam *exam);

// Retorna a identificação única do aparelho de raio-X utilizado no exame.
int get_exam_rx_id(const Exam *exam);

/**
 * Retorna a Data/Hora de realização do Exame.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return Data/Hora de realização do Exame.
 */
struct tm* get_exam_time(const Exam *exam);

/**
 * Retorna a Data/Hora de realização do Exame no formato String.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return Data/Hora no formato String.
 */
char* get_exam_time_string(const Exam *exam);

/**
 * Retorna o ponteiro para a Condition do Exame.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return Ponteiro do tipo Condition.
 */
Condition* get_exam_condition(Exam *exam);

/**
 * Retorna o nível de gravidade da Condition associada ao Exame.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return Inteiro do nível de gravidade da Condition no Exame.
 */
int get_exam_condition_gravity(Exam *exam);

/**
 * Retorna o nome da Condition associada ao Exame.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return String do nome da Condition no Exame.
 */
char* get_exam_condition_name(Exam *exam);

/**
 * Muda manualmente as propriedades da Condition associada ao Exame.
 *
 * @param exam  Ponteiro do tipo Exam.
 * @param id  Número identificador da Condition.
 * @param nome_cond  Nome da Condition.
 * @param grav  Nível de gravidade da Condition.
 * 
 * @return String do nome da Condition no Exame.
 */
void set_exam_condition(Exam *exam, int id, char* nome_cond, int grav);

/**
 * Imprime na tela as propriedades do Exame
 * 
 * @param exam  Ponteiro do tipo Exam.
 * 
 */
void print_exam(Exam *exam);

/**
 * Retorna as propriedades do Exame em String.
 *
 * @param exam  Ponteiro do tipo Exam.
 * 
 * @return String com propriedades do Exame.
 */
char* exam_output(Exam *exam);

#endif