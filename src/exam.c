// Arquivos de cabeçalho criados localmente
#include "exam.h"
#include "functions.h"
#include "condition.h"
#include "definitions.h"

// Arquivos de cabeçalho
#include <time.h> // struct tm
#include <stdio.h> // perror
#include <stdlib.h> // malloc
#include <string.h>

struct exam {
    int id;
    int patient_id;
    int rx_id;
    Condition *condition_IA;
    struct tm *time;
} exam;

// Cria um novo exame, alocando memória para a estrutura, preenchendo os campos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada.
Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time){
    // Alocação de memória
    Exam *new_exam = (Exam *)malloc(sizeof(Exam)); 

    // Verifica se falha na alocação de memória
    if(new_exam == NULL) {
        // Mensagem de erro
        error_message_id("\nErro.\nNao foi possível alocar memória para o exame com id", id);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
    }

    // Verificações das variáveis antes das atribuições
    if(validate_id(id, "id exame")) new_exam->id = id;
    if(validate_id(patient_id, "exame, id paciente")) new_exam->patient_id = patient_id;
    if(validate_id(rx_id, "id raio-x")) new_exam->rx_id = rx_id;
    if(validate_time(time, "exame time")) new_exam->time = time;
    new_exam->condition_IA = get_condition();

    db_save(exam_output(new_exam), TYPE_EXAM);

    return new_exam;
} 

// Libera a memória alocada para a estrutura de exame.
void destroy_exam(Exam *exam){
    free(exam);
} 

// Retorna a identificação única do exame.
int get_exam_id(const Exam *exam){
    return exam->id;
} 

// Retorna a identificação única do paciente associado ao exame.
int get_exam_patient_id(const Exam *exam){
    return exam->patient_id;
}

// Retorna a identificação única do aparelho de raio-X utilizado no exame.
int get_exam_rx_id(const Exam *exam){
    return exam->rx_id;
}

// Retorna o horário de realização do exame.
struct tm* get_exam_time(const Exam *exam){
    return exam->time;
}

char* get_exam_time_string(const Exam *exam){
    return asctime(exam->time);
}

Condition* get_exam_condition(Exam *exam){
    return exam->condition_IA;
}

char* get_exam_condition_name(Exam *exam){
    return get_condition_name(exam->condition_IA);
}

void print_exam(Exam *exam){
    printf("Exame\nId: %d\n", get_exam_id(exam));
    printf("Id do Paciente: %d\n", get_exam_patient_id(exam));
    printf("Id do Raio X: %d\n", get_exam_rx_id(exam));
    print_condition(get_exam_condition(exam));
    printf("Data/Hora do Exame: %s", get_exam_time_string(exam));
}

char* exam_output(Exam *exam){
    char *output = (char *)malloc(sizeof(char) * 128);
    sprintf(output, "%d,%d,%d,%s,%s", get_exam_id(exam), get_exam_patient_id(exam), get_exam_rx_id(exam), condition_output(get_exam_condition(exam)), get_timestamp_from_datetime(get_exam_time(exam)));
    return output;
}