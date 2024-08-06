#include "patient.h" // Arquivo header
#include "functions.h" // Arquivo header com funções

#include <stdio.h> // perror
#include <stdlib.h> // malloc
#include <string.h> // strdup

struct patient {
    int id;
    char *name;
    struct tm *birthdate;
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
    if( validate_id(id, "id paciente") ) new_patient->id = id;
    if( validate_name(name, id) ) new_patient->name = strdup(name); // Reserva espaço de armazenamento para uma cópia da string name
    if( validate_time(birthdate, "Data nascimento do paciente") ) new_patient->birthdate = birthdate;

    return new_patient;
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