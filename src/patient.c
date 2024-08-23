#include "patient.h" // Arquivo header
#include "functions.h" // Arquivo header com funções
#include "definitions.h"

#include <stdio.h> // perror
#include <stdlib.h> // malloc
#include <string.h> // strdup

// Definição da estrutura Patient
struct patient {
    int id;
    char *name;
    struct tm *birthdate;
    int arrival;
} patient;

// Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada. 
Patient *create_patient(int id, const char *name, struct tm *birthdate, int arrival){
    // Alocação de memória
    Patient *new_patient = (Patient *)malloc(sizeof(Patient));

    // Verifica se falha na alocação de memória
    check_malloc(new_patient, "\nErro.\nNao foi possível alocar memória para o Patient.");

    // Verificações das variáveis antes das atribuições
    if(validate_int(id, "Patient id"))
        new_patient->id = id;
    if(validate_string(name, "Patient name"))
        new_patient->name = strdup(name); // Reserva espaço de armazenamento para uma cópia da string name
    new_patient->birthdate = birthdate;  // Data de Nascimento puramente cosmética, não precisa de tratamento
    if(validate_int(arrival, "Patient arrival"))
        new_patient->arrival = arrival;

    // Salva no arquivo ao criar o novo Patient
    db_save(TYPE_PATIENT, patient_output(new_patient));

    return new_patient; // Retorna o ponteiro
}

// Libera a memória alocada para a estrutura do paciente. 
void destroy_patient(Patient *patient){
    free(patient);
}

// Retorna a identificação única do paciente. 
int get_patient_id(const Patient *patient){
    return patient->id;
}

// Retorna o nome do paciente.
const char* get_patient_name(const Patient *patient){
    return patient->name;
}

// Retorna a data de nascimento do paciente. 
struct tm* get_patient_birthdate(const Patient *patient){
    return patient->birthdate;
}

// Retorna a data de que o paciente foi criado. 
int get_patient_arrival(const Patient *patient){
    return patient->arrival;
}

// Retorna a data de nascimento do paciente.
char* get_patient_birthdate_string(const Patient *patient){
    return get_date_from_datetime(get_patient_birthdate(patient));
}

// Imprime na tela as propriedades do Patient
void print_patient(const Patient *patient){
    printf("Paciente\nId: %d\n", get_patient_id(patient));
    printf("Nome: %s\n", get_patient_name(patient));
    printf("Data de Nascimento: %s\n", get_patient_birthdate_string(patient));
}

// Retorna uma string com as propriedades do Patient
char* patient_output(const Patient *patient){
    // Alocação de memória para a string
    char *output = (char *)malloc(sizeof(char) * 128);
    check_malloc(output, "Erro.\nNão foi possível alocar memória para o output do Patient, em patient_output()");
    // Estrutura da string
    sprintf(output, "%d,%s,%d", get_patient_id(patient), get_patient_name(patient), get_patient_arrival(patient));
    return output; // Retorna o ponteiro
}