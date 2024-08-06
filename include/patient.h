#ifndef PATIENT
#define PATIENT

#include <time.h> // struct tm

typedef struct patient Patient;

// Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada. 
// struct tm *arrival ???
Patient *create_patient(int id, const char *name, struct tm *birthdate);

// Libera a memória alocada para a estrutura do paciente. 
void destroy_patient(Patient *patient);

// Retorna a identificação única do paciente. 
int get_patient_id(const Patient *patient);

// Retorna o nome do paciente.
const char* get_patient_name(const Patient *patient);

// Retorna a data de nascimento do paciente. 
struct tm* get_patient_birthdate(const Patient *patient);

#endif