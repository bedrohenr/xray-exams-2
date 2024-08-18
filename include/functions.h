#ifndef FUNCTIONS
#define FUNCTIONS

#include "definitions.h"

#include <time.h> // struct tm

/**
 * Para execução do programa com o código de erro
 *
 * @param err_code  Código do erro.
 */
void error_exit(int err_code);

/**
 * Verifica se o número é maior ou igual a zero.
 *
 * @param num Variável time a ser testada.
 * @param msg String de indentificação de onde ocorreu o erro, para caso falhe a validação.
 *
 * @returns 1 para válido, 0 para invalidado.
 */
int validate_int(int num, const char *msg);

/**
 * Verifica se o Dia, Mês e Ano são igual a zero.
 *
 * @param time Variável time a ser testada.
 * @param msg Campo de identificação de onde ocorreu o erro, para caso falhe a validação.
 *
 * @returns 1 para válido, 0 para invalidado.
 */
int validate_time(const struct tm* time, const char *msg);

/**
 * Checa se a string é vazia.
 *
 * @param str String a ser testada.
 * @param message Mensagem caso a validação falhe.
 *
 * @returns 1 para válido, 0 para invalidado.
 */
int validate_string(const char* str, const char* message);

/**
 * Gera aleatóriamente um número. Precisa-se inicializar srand() anteriormente de sua execução.
 *
 * @param max_number Número máximo.
 *
 * @returns Número inteiro.
 */
int get_random_number(int max_number);

/**
 * Gera aleatóriamente um número float. Precisa-se inicializar srand() anteriormente de sua execução.
 *
 * @param max_number Número máximo.
 *
 * @returns Número de ponto flutuante.
 */
float get_random_float_number(float max_number);

/**
 * Verifica se o número de dias está correto para aquele mês.
 *
 * @param month Mêses no ano, desde janeiro (0 - 11).
 * @param day Dias do mês (0 - 31).
 *
 * @returns Retorna o dia inserido se válido, caso não seja, retorna o número máximo de dias naquele mês.
 */
int validate_day_of_month(int month, int day);

/**
 * Cria uma data com os paramentros inseridos.
 *
 * @param year Ano, anos passados após 1900 (0 - 124).
 * @param month Mêses no ano, desde janeiro (0 - 11).
 * @param day Dias do mês (0 - 31).
 *
 * @returns Data/Hora.
 */
struct tm create_date(int year, int month, int day);

/**
 * Retorna data/hora atual.
 *
 * @returns Data/Hora.
 */
struct tm* get_time();

/**
 * Retorna um timestamp em string no formato YY-mm-dd HH:MM:SS
 *
 * @param date Variável datetime.
 *
 * @returns em string.
 */
char* get_timestamp_from_datetime(const struct tm* date);

/**
 * Retorna data em string no formato YY-mm-dd de uma variável datetime
 *
 * @param date Variável datetime.
 *
 * @returns Data em string.
 */
char* get_date_from_datetime(const struct tm* date);

/**
 * Imprime na tela as propriedades de acordo com o tipo da estrutura.
 *  
 * @param type Tipo da estrutura.
 * @param p Tipo da estrutura.
 */
void print_by_struct_type(StructType type, void *p);

/**
 * Retorna uma string com as propriedades de acordo com o tipo da estrutura.
 *  
 * @param type Tipo da estrutura.
 * @param p Tipo da estrutura.
 * 
 * @return String com as propriedades da estrutura do ponteiro.
 */
char* output_by_struct_type(StructType type, void *p);

/**
 * Retorna em string o endereço do arquivo db da estrutura.
 * *  
 * @param type Tipo da estrutura.
 * 
 * @returns String com endereço do arquivo db da estrutura.
 */
char* get_db_path(StructType type);

/**
 * Salva o conteúdo em um arquivo de acordo com o tipo da estrutura.
 *  
 * @param content String com o texto a ser armazenado no arquivo.
 * @param type Tipo da estrutura.
 */
void db_save(StructType type, const char *content);

/**
 * Libera memória da estrutura devido a seu tipo, usando as funções corretas 
 * 
 * @param type Tipo do ponteiro.
 * @param p Ponteiro a ter sua memória liberada.
 */
void free_by_struct_type(StructType type, void *p);

/**
 * Calcula quanto tempo passou desde um ponto anterior onde originou a variavel t
 * 
 * @param t  Ponto anterior.
 */
double time_passed(clock_t t);

/**
 * Executa testando a função q_enqueue_prio(), para checagem da prioridade do nível de gravidade de cada Exame.
 *  
 */
void test_enqueue_prio();

/**
 * 
// Retorna uma string com nome e sobrenome gerado aleatoriamente.
 * 
 * @return String com nome e sobrenome gerados aleatóriamente. 
 */
char* get_name();


/**
 * Mostra um relatório, informações da simulação, na tela. 
 * 
 * @param patient_count Número de pacientes que passarm pelo hospital.
 * @param patient_queue_count Número de pacientes na fila aguardando exame.
 * @param exam_count Número de exames feitos no hospital.
 * @param report_count Número de laudos gerados no hospital.
 */
void simulation_report(int patient_count, int patient_queue_count, int exam_count, int report_count, int time_exam_in_queue, int *condition_time, int *condition_count, int condition_array_length, int exam_at_defined_time_limit);

// Apaga o conteúdo dos arquivos db.
void db_reset();

#endif