// Arquivo de cabeçalho criado localmente
#include "functions.h"

#include "patient.h"
#include "exam.h"
#include "report.h"
#include "queue.h"

// Arquivos de cabeçalho
#include <stdlib.h> // malloc, EXIT_FAILURE
#include <string.h> // strcmp
#include <stdio.h> // printf

// Para a execução do programa com o código de erro.
void error_exit(int err_code){
    exit(err_code); 
}

// Imprime uma mensagem na tela com id.
void error_message_id(const char *msg, int id){
    printf("%s: %d.", msg, id);
}

// Imprime uma mensagem na tela com especificação do campo.
void error_message_field(const char *msg, char *campo){
    printf("%s: %s.", msg, campo);
}

// Verifica se o número inteiro id é válido, maior que zero.
int validate_id(int num, const char *msg){
    if ( num > 0 ) {
        return 1;
    } else {
        // Mensagem de erro.
        printf("Erro.\nNumero inválido em %s.", msg);
        // Finaliza execução.
        error_exit(EXIT_FAILURE);
        return 0;
    }
}

// Verifica se o Dia, Mês e Ano é igual a zero.
int validate_time(const struct tm* time, const char *msg){

    // Checa por números zerados
    if( time->tm_year == 0 &&
        time->tm_mon  == 0 &&
        time->tm_mday == 0 ){

        // Mensagem de erro.
        printf("Erro.\nData/Hora não informada em %s.", msg);
        // Função para mostrar o erro e finaliza execução.
        error_exit(EXIT_FAILURE);
        return 0;
    }
    return 1;
}

// Verifica se o a variável string está vazia e mostra mensagem de erro.
int validate_string(const char* str, const char* message){
    if( strcmp(str, "") == 0 || strcmp(str, " ") == 0){
        // Mensagem de erro
        printf("Erro.\nString vazia em %s.", message);
        // Função para mostrar o erro e finaliza execução.
        error_exit(EXIT_FAILURE);
        return 0;
    }
    return 1;
}

// Gera um número aleatório com número máximo especificado.
int get_random_number(int max_number){
    srand(time(NULL));
    return rand() % (max_number + 1); // Retorna o número aleatório.
}

// Gera um número de ponto flutuante aleatório com número máximo especificado.
float get_random_float_number(float max_number){
    srand((unsigned int)time(NULL));

    return ((rand()/(float)(RAND_MAX)) * max_number);
}

// Verifica se o número de dias está correto para aquele mês.
int validate_day_of_month(int month, int day){
    if(month > 11) // Verifica se o número do mês é válido.
        month = 11;

    // Máximo de dias em cada mês
    int DAYS_IN_MONTH[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Checa se número de dias equivale ao mês.
    if(day > DAYS_IN_MONTH[month])
        return DAYS_IN_MONTH[month]; // Retorna o máximo de dias naquele mês.
    else
        return day; // Retorna o dia inserido.
}

// Cria e retorna uma data com os parâmetros especificados.
struct tm create_date(int year, int month, int day){
    struct tm date = {0}; // Inicializar a estrutura com zeros.

    day = validate_day_of_month(month, day);

    date.tm_year = year; // Anos após 1990
    date.tm_mon = month; // (0-indexed)
    date.tm_mday = day; // Dia 
   
    return date; // Retorna a data.
}

// Retorna a Data/Hora atual.
struct tm* get_time(){
    time_t current_time;
    current_time = time(NULL); // Obter o tempo atual em segundos desde 01/01/1970.
    return localtime(&current_time); // Retorna o tempo convertido para a hora local.
}

// Retorna um timestamp em string no formato YY-mm-dd HH:MM:SS.
char* get_timestamp_from_datetime(struct tm* date){
    // Alocação de memória para o ponteiro.
    char *output = (char *)malloc(sizeof(char) * 32);
    // Estrutura da string.
    sprintf(output, "%d-%d-%d %d:%d:%d", (1900 + date->tm_year), date->tm_mon, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
    return output; // Retorna o ponteiro.
}

// Retorna data em string no formato YY-mm-dd de uma variável datetime.
char* get_date_from_datetime(struct tm* date){
    // Alocação de memória do ponteiro.
    char *output = (char *)malloc(sizeof(char) * 32);
    // date->tm_year retorna quantos anos desde 1900.
    sprintf(output, "%d-%d-%d", (1900 + date->tm_year), date->tm_mon, date->tm_mday);
    return output; // Retorna o ponteiro.
}

// Imprime na tela as informações das estruturas
// É usado a função correta de cada estruturda
void print_by_struct_type(StructType type, void *p) {
    switch (type) {
        case TYPE_PATIENT:
            print_patient(p); // Patient
            break;

        case TYPE_EXAM:
            print_exam(p); // Exam
            break;

        case TYPE_REPORT:
            print_report(p); // Report
            break;

        default:
            printf("Não foi possível imprimir essa estrutura.");
            printf("\nStructType não encontrado.");
            break;
    }
}

// Retorna as informações das estruturas em string
// É usado a função correta de cada estruturda
char* output_by_struct_type(StructType type, void *p) {
    switch (type) {
        case TYPE_PATIENT:
                return patient_output(p); // Patient
                break;

        case TYPE_EXAM:
            return exam_output(p); // Exam
            break;

        case TYPE_REPORT:
            return report_output(p); // Report
            break;
    }
    return "Error. StructType inválida.";
}

// Salva os registros de novas estruturas em seus arquivos db
char* get_db_path(StructType type){

    // Resolve o endereço do arquivo pelo tipo da estrutura
    switch (type) {
        case TYPE_PATIENT:
            return "./src/static/db_patient.txt";
        
        case TYPE_EXAM:
            return "./src/static/db_exam.txt";
        
        case TYPE_REPORT:
            return "./src/static/db_report.txt";
    }
    return "";

}

// Adiciona uma linha no arquivo especificado.
void db_save(StructType type, char* content){
    // Endereço do arquivo.
    char *path = get_db_path(type); 
    FILE *file_pointer; 

    // Abre o arquivo em appending mode.
    file_pointer = fopen(path, "a"); 
    // Adiciona a linha ao arquivo.
    fprintf(file_pointer, "%s\n", content);
    // Fecha o arquivo.
    fclose(file_pointer);
}

// Libera memória da estrutura devido a seu tipo, usando as funções corretas 
void free_by_struct_type(StructType type, void *p) {
    // Decide qual função usar baseado no tipo da estrutura.
    switch (type) {
        case TYPE_PATIENT:
            destroy_patient(p);
            break;

        case TYPE_EXAM:
            destroy_exam(p);
            break;

        case TYPE_REPORT:
            destroy_report(p);
            break;
    }
}


// Calcula quanto tempo passou desde um ponto anterior onde originou a variavel t
double time_passed(clock_t t){
    clock_t t2 = clock() - t; // Calcula o tempo atual e o tempo da variavel t
    double time_taken = ((double)t2)/CLOCKS_PER_SEC; // Converte em segundos dividindo por CLOCKS_PER_SEC

    return time_taken; // Retorna a diferença de tempo
}

// Cria exames de prioridades diferentes, de forma não sequencial para checar se a lista de prioridade de exame esta funcionando.
void test_enqueue_prio(){

    // id counters
    int patient_id_counter = 1;
    int exam_id_counter = 1;

    struct tm birthdate = create_date(get_random_number(124), get_random_number(11), get_random_number(31));

    Patient *patient = create_patient(patient_id_counter++, "João Silva", &birthdate);

    Queue *ExamPriorityQueue = q_create();

    char* condition = "Muito sono";

    Exam *new_aexam;
    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 4);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 1);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 5);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 3);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 2);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 5);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), get_time());
    set_exam_condition(new_aexam, 10, condition, 5);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    q_print(ExamPriorityQueue);
}

void simulation_report(int patient_count, int patient_queue_count, int exam_count, int report_count){
    // Número de pacientes que visitaram o hospital.
    printf("\n%d visitaram o hospital.", patient_count);
    // Número de pacientes na fila aguardando exame.
    printf("\n%d na fila aguardando exame.", patient_queue_count);
    // Número de pacientes que já realizaram exame e, dentre estes, a porcentagem do que já receberam laudo.
    printf("\nNumeros report_count: %d, exam_count: %d.", report_count, exam_count);
    int report_percentage = (100*report_count/exam_count);
    printf("\n%d já realizaram exame, %d%% receberam laudo.", exam_count, report_percentage);
    // Tempo médio de laudo: Tempo médio que os exames ocupam a fila de prioridades.
    // Tempo médio de laudo por condição: Tempo médio que os exames de uma condição específica (assinalada pelo médico) ocupam a fila de prioridades.
    // Número de exames realizados após o limite de tempo estabelecido (7200 unidades de tempo).
}