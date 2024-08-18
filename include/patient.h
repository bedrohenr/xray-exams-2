#ifndef PATIENT
#define PATIENT

#include <time.h> // struct tm

typedef struct patient Patient;

/**
 * Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada. 
 *
 * @param id  Número identificador do Paciente.
 * @param name  Nome do Paciente.
 * @param birthdate  Data de aniversário do Paciente.
 * @param arrival  Timestamp do horário de chegada do Paciente.
 * 
 * @return Ponteiro para o Paciente recém criado com os parâmetros.
 */
Patient *create_patient(int id, const char *name, struct tm *birthdate, int arrival);

/**
 * Libera a memória alocada para a estrutura Patient. 
 *
 * @param patient Ponteiro do tipo Patient.
 */
void destroy_patient(Patient *patient);

/**
 * Retorna o número de identificação do Patient. 
 *
 * @param patient Ponteiro do tipo Patient.
 * 
 * @return Inteiro com o número de identificação do Patient.
 */
int get_patient_id(const Patient *patient);

/**
 * Retorna o nome do Patient. 
 *
 * @param patient Ponteiro do tipo Patient.
 * 
 * @return String com o nome do Patient.
 */
const char* get_patient_name(const Patient *patient);

/**
 * Retorna a data de nascimento do Patient.
 *
 * @param patient Ponteiro do tipo Patient.
 * 
 * @return Struct tm com a data de nascimento do Patient.
 */
struct tm* get_patient_birthdate(const Patient *patient);

/**
 * Retorna a timestamp de chegada do Patient.
 *
 * @param patient Ponteiro do tipo Patient.
 * 
 * @return Struct tm com a data de chegada do Patient.
 */
int get_patient_arrival(const Patient *patient);

/**
 * Retorna a data de nascimento do Patient em formato YY-mm-dd.
 *
 * @param patient Ponteiro do tipo Patient.
 * 
 * @return String com a data de nascimento do Patient.
 */
char* get_patient_birthdate_string(const Patient *patient);

/**
 * Imprime na tela as propriedades do Patient passado no argumento.
 *
 * @param patient Ponteiro do tipo Patient.
 */
void print_patient(const Patient *patient);

/**
 * Retorna as propriedades do Patient passado como arguemento em uma string.
 *
 * @param patient Ponteiro do tipo Patient.
 * 
 * @return String com as propriedades do Patient.
 */
char* patient_output(const Patient *patient);

#endif