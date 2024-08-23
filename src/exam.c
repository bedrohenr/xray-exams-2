// Arquivos de cabeçalho criados localmente
#include "exam.h"
#include "functions.h"
#include "definitions.h"

// Arquivos de cabeçalho
#include <time.h> // struct tm
#include <stdio.h> // perror
#include <stdlib.h> // malloc
#include <string.h>

// Definição da struct Exam
struct exam {
    int id;
    int patient_id;
    int rx_id;
    Condition *condition_IA;
    int time;
} exam;

// Cria um novo exame, alocando memória para a estrutura, preenchendo os campos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada.
Exam* create_exam(int id, int patient_id, int rx_id, int time){
    // Alocação de memória
    Exam *new_exam = (Exam *)malloc(sizeof(Exam)); 

    // Verifica se falha na alocação de memória.
    check_malloc(new_exam, "\nErro.\nNao foi possível alocar memória para o Exam.");

    // Verificações das variáveis antes das atribuições.
    if(validate_int(id, "Exam id")) 
        new_exam->id = id;
    if(validate_int(patient_id, "Exam patient_id")) 
        new_exam->patient_id = patient_id;
    if(validate_int(rx_id, "Exam rx_id")) 
        new_exam->rx_id = rx_id;
    if(validate_int(time, "Exam time")) 
        new_exam->time = time;

    // Recebe uma condição e associa-a ao Exame recém criado.
    new_exam->condition_IA = get_condition();

    // Salva o novo Exame no arquivo.
    db_save(TYPE_EXAM, exam_output(new_exam));

    return new_exam; // Retorna o ponteiro.
} 

// Libera a memória alocada para a estrutura de exame.
void destroy_exam(Exam *exam){
    // Libera a memória para a ponteiro Condition
    destroy_condition(get_exam_condition(exam)); 
    free(exam); // Libera a memória do Exame
} 

// Retorna o núermo de identificação do exame.
int get_exam_id(const Exam *exam){
    return exam->id;
} 

// Retorna o núemro de identificação do paciente associado ao exame.
int get_exam_patient_id(const Exam *exam){
    return exam->patient_id;
}

// Retorna o número de identificação do aparelho de raio-X utilizado para o exame.
int get_exam_rx_id(const Exam *exam){
    return exam->rx_id;
}

// Retorna o horário de realização do exame.
int get_exam_time(const Exam *exam){
    return exam->time;
}

// Retorna o ponteiro da Condition assoaciada ao Exame .
Condition* get_exam_condition(const Exam *exam){
    return exam->condition_IA;
}

// Retorna o número de identificação da condition associada ao exame
int get_exam_condition_id(const Exam *exam){
    return get_condition_id(get_exam_condition(exam));
}

// Retorna o nome da Condition associada ao Exame.
char* get_exam_condition_name(const Exam *exam){
    return get_condition_name(exam->condition_IA);
}

// Retorna o nível de gravidade da Condition associada ao Exame.
int get_exam_condition_gravity(const Exam *exam){
    return get_condition_gravity(get_exam_condition(exam));
}

// Manualmente muda as propriedades da Condition associada ao Exame.
// Usada para testes.
void set_exam_condition(Exam *exam, int id, const char* nome_cond, int grav){
    Condition *old_condition = get_exam_condition(exam); // Aux

    // Recebe nova Condition com as propriedades inseridas.
    exam->condition_IA = create_condition(id, nome_cond, grav);

    // Libera memória da Condition anterior.
    destroy_condition(old_condition);
}

// Imprime na tela as propriedades do Exame.
void print_exam(const Exam *exam){
    printf("Exame\nId: %d\n", get_exam_id(exam));
    printf("Id do Paciente: %d\n", get_exam_patient_id(exam));
    printf("Id do Raio X: %d\n", get_exam_rx_id(exam));
    print_condition(get_exam_condition(exam)); // Propriedades da Condition
    printf("Tempo da Hora do Exame: %d", get_exam_time(exam));
}

// Retorna as propriedades do Exame em string.
char* exam_output(const Exam *exam){
    // Alocação de memória do ponteiro a ser retornado.
    char *output = (char *)malloc(sizeof(char) * 128);
    check_malloc(output, "Erro.\nNão foi possível alocar memória para o output do Exam, em exam_output()");
    // Estrutura da string a ser retornada.
    sprintf(output, "%d,%d,%d,%s,%d", get_exam_id(exam), get_exam_patient_id(exam), get_exam_rx_id(exam), condition_output(get_exam_condition(exam)), get_exam_time(exam));

    return output; // Retorna a string.
}