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
    struct tm *arrival;
} patient;

// Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada. 
Patient *create_patient(int id, const char *name, struct tm *birthdate){
    // Alocação de memória
    Patient *new_patient = (Patient *)malloc(sizeof(Patient));

    // Verifica se falha na alocação de memória
    if(new_patient == NULL){
        // Mensagem de erro
        error_message_id("\nErro.\nNao foi possível alocar memória para o paciente com id", id);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
    }   

    // Verificações das variáveis antes das atribuições
    if(validate_id(id, "Patient id") )
        new_patient->id = id;
    if(validate_string(name, "Patient name") )
        new_patient->name = strdup(name); // Reserva espaço de armazenamento para uma cópia da string name
    if(validate_time(birthdate, "Patient birthdate") )
        new_patient->birthdate = birthdate;
    if(validate_time(arrival, "Patient arrival"))
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
struct tm* get_patient_arrival(const Patient *patient){
    return patient->arrival;
}

// Retorna a data de nascimento do paciente.
char* get_patient_birthdate_string(const Patient *patient){
    return get_date_from_datetime(get_patient_birthdate(patient));
}

// Retorna a data de que o paciente foi criado em string.
char* get_patient_arrival_string(const Patient *patient){
    return get_timestamp_from_datetime(get_patient_arrival(patient));
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
    // Estrutura da string
    sprintf(output, "%d,%s,%s", get_patient_id(patient), get_patient_name(patient), get_patient_arrival_string(patient));
    return output; // Retorna o ponteiro
}