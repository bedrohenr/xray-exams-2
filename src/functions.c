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

// Verifica se o número inteiro id é válido, maior que zero.
int validate_int(int num, const char *msg){
    if ( num >= 0 ) {
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

        printf("\n%s", get_timestamp_from_datetime(time));
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
    return rand() % (max_number + 1); // Retorna o número aleatório.
}

// Gera um número de ponto flutuante aleatório com número máximo especificado.
float get_random_float_number(float max_number){
    srand((unsigned int)time(NULL));

    return ((rand()/(float)(RAND_MAX)) * max_number);
}

// Verifica se o número de dias está correto para o mês especificado.
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
    return localtime(&current_time); // Retorna o ponteiro tempo convertido para a hora local.
}

// Retorna um timestamp em string no formato YY-mm-dd HH:MM:SS.
char* get_timestamp_from_datetime(const struct tm* date){
    // Alocação de memória para o ponteiro.
    char *output = (char *)malloc(sizeof(char) * 32);
    check_malloc(output, "Erro.\nNão foi possível alocar memória para a string em get_timestamp_from_datetime()");
    // Estrutura da string.
    sprintf(output, "%d-%d-%d %d:%d:%d", (1900 + date->tm_year), date->tm_mon, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
    return output; // Retorna o ponteiro.
}

// Retorna data em string no formato YY-mm-dd de uma variável datetime.
char* get_date_from_datetime(const struct tm* date){
    // Alocação de memória do ponteiro.
    char *output = (char *)malloc(sizeof(char) * 32);
    check_malloc(output, "Erro.\nNão foi possível alocar memória para a string em get_date_from_datetime()");
    // date->tm_year retorna quantos anos desde 1900.
    sprintf(output, "%d-%d-%d", (1900 + date->tm_year), date->tm_mon, date->tm_mday);
    return output; // Retorna o ponteiro.
}

// Imprime na tela as informações das estruturas
// É usado a função correta de cada estrutura
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
// É usado a função correta de cada estrutura
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

// Cria um arquivo.
static int create_file(const char* path){

    // Cria um arquivo novo com o modo escrita.
    FILE *fp = fopen(path, "w"); 

    // Testa se o ponteiro recebe um endereço.
    if(fp != NULL){
        fclose(fp); // Fecha o arquivo.
        return 1; // Arquivo encontrado.
    }

    return 0; // Arquivo não encontrado.
}

// Verifica se o arquivo no endereço inserido existe.
static int file_exists(const char* path){

    // Tenta abrir o arquivo no modo leitura.
    FILE *fp = NULL;
    fp = fopen(path, "r"); 

    // Testa se o ponteiro recebe um endereço, provando que o arquivo existe.
    if(fp != NULL){
        fclose(fp); // Fecha o arquivo.
        return 1;
    } else {
        return create_file(path); // Cria o arquivo caso não exista.
    }
}

// Salva os registros de novas estruturas em seus arquivos db
char* get_db_path(StructType type){
    char* path;

    // Resolve o endereço do arquivo pelo tipo da estrutura
    switch (type) {
        case TYPE_PATIENT:
            path = DB_PATIENT_PATH;
            break;
            
        case TYPE_EXAM:
            path = DB_EXAM_PATH;
            break;
        
        case TYPE_REPORT:
            path = DB_REPORT_PATH;
            break;
    }

    // Testa se o arquivo existe.
    if(file_exists(path)) // Se nao existe cria um.
        return path; // Retorna o endereço do arquivo.
    else
        return ""; // -Wall enchendo o saco.
}

// Adiciona uma linha no arquivo especificado.
void db_save(StructType type, const char* content){
    // Endereço do arquivo.
    char *path = NULL;
    path = get_db_path(type); 

    // Checa se string path esta vazia.
    if(strcmp(path, "") == 0 || path == NULL){
        printf("Erro ao salvar em arquivo: %s.\n", path);
        error_exit(EXIT_FAILURE); // Para a execução com o erro.
    }

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

    // Instante de tempo para teste
    int time = 1;

    struct tm birthdate = create_date(get_random_number(124), get_random_number(11), get_random_number(31));

    Patient *patient = create_patient(patient_id_counter++, "João Silva", &birthdate, time);

    Queue *ExamPriorityQueue = q_create();

    char* condition = "Muito sono";

    Exam *new_aexam;

    // Instanciamentos de exames com nivel de gravidade diferentes.
    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 4);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 1);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 5);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 3);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 2);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 5);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    new_aexam = create_exam(exam_id_counter++, get_patient_id(patient), (1), time);
    set_exam_condition(new_aexam, 10, condition, 5);

    q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_aexam);

    q_print(ExamPriorityQueue); // Checagem na tela se a função enfileirou corretamente.
}

// Retorna uma string com nome e sobrenome gerado aleatoriamente
char* get_name(){
    // Array com primeiros nome
    char *first_names[] = {
        "Lucas","Gabriel","Ana","Pedro","Maria","João","Isabela","Miguel","Sophia","Arthur","Rafael","Bruna","Carla","Felipe","Mariana","Fernanda","Caio","Larissa","Thiago","Amanda"
    };

    // Array com sobrenomes
    char *last_names[] = {
        "Silva","Santos","Oliveira","Souza","Pereira","Costa","Ferreira","Alves","Ribeiro","Carvalho","Moura","Gomes","Martins","Barbosa","Rocha","Lima","Araújo","Cardoso","Correia","Duarte"
    };

    // Escolhe com ajuda de numero aleatório
    char* first_name = first_names[get_random_number(19)];
    char* last_name = last_names[get_random_number(19)];

    // Alocando memória para retornar o ponteiro char
    char* full_name = (char *)malloc(sizeof(char) * 20);
    check_malloc(full_name, "Erro.\nNão foi possível alocar memória para a string em get_name()");
    // Atribuindo a string com formatação
    sprintf(full_name, "%s %s", first_name, last_name);

    return full_name; // Retorna o ponteiro
}

void simulation_report(int patient_count, int patient_queue_count, int exam_count, int report_count, int time_exam_in_queue, int *condition_time, int *condition_count, int condition_array_length, int exam_at_defined_time_limit){
    int report_percentage;
    int median_exam_report = 0;
    int exam_at_time_limit = 0;
    printf("\n-- RELATÓRIO -- ");
    // Número de pacientes que visitaram o hospital.
    printf("\nVisitaram o hospital: %d.", patient_count);

    // Número de pacientes na fila aguardando exame.
    printf("\nNa fila aguardando exame %d.", patient_queue_count);

    // Número de pacientes que já realizaram exame e, dentre estes, a porcentagem do que já receberam laudo.
    report_percentage = (100*report_count/exam_count);
    printf("\nRealizaram exame: %d, %d%% receberam laudo.", exam_count, report_percentage);

    // Tempo médio de laudo: Tempo médio que os exames ocupam a fila de prioridades.
    median_exam_report = time_exam_in_queue/exam_count;
    printf("\nTempo médio de laudo: %d ut.", median_exam_report);

    // Tempo médio de laudo por condição: Tempo médio que os exames de uma condição específica (assinalada pelo médico) ocupam a fila de prioridades.
    printf("\nTempo médio de laudo por condição:"); 
    for(int i = 0; i < condition_array_length; i++){
        median_exam_report = 0;
        // Não contenha divisão por zero
        if(condition_count[i] > 0)
            median_exam_report = condition_time[i]/condition_count[i];

        // printf("\nCondição %d: %d, %d", i, condition_time[i], condition_count[i]);
        printf("\nCondição %s: %d ut.", get_condition_name_by_id(i), median_exam_report);
    }

    // Número de exames realizados após o limite de tempo estabelecido (7200 unidades de tempo).
    if(exam_at_defined_time_limit != 0)
        exam_at_time_limit = patient_count - exam_at_defined_time_limit;

    printf("\nExames realizados após limite de tempo estabelecido: %d.", exam_at_time_limit);

    printf("\n-- FIM RELATÓRIO -- ");
}

// Apaga o conteúdo dos arquivos db
void db_reset(){
    char* path;

    // Resetando arquivo db_patient.
    path = DB_PATIENT_PATH;
    create_file(path);

    // Resetando db_exam.
    path = DB_EXAM_PATH;
    create_file(path);

    // Resetando db_report.
    path = DB_REPORT_PATH;
    create_file(path);
}

// Testa e mostra a distribuição de probabiliade das Conditions.
void show_condition_rng(){
    printf("Teste de distribuição de probabilidade das Conditions");
    printf("\nNúmeros gerados de [0, %.0f].", RNG_DISTRIBUTION);
    printf("\nCondition  %d: %d => rng <= %.0f", 1, I_CONDITION_L, I_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 2, II_CONDITION_L, II_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 3, III_CONDITION_L, III_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 4, IV_CONDITION_L, IV_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 5, V_CONDITION_L, V_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 6, VI_CONDITION_L, VI_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 7, VII_CONDITION_L, VII_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 8, VIII_CONDITION_L, VIII_CONDITION_H);
    printf("\nCondition %d: %.0f => rng <= %.0f", 9, IX_CONDITION_L, IX_CONDITION_H);
}

// Checa se a variável ponteiro é nulo.
void check_malloc(void *p, char *msg){
    // Alocação de memória
    if(p == NULL){
        // Mensagem de erro
        printf("%s", msg);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
    }   
}

// Tempo de espera da execução em milissegundos.
void wait(int milliseconds){
    clock_t t = clock(); // Armazena o tempo que inicou a função
    double time_since; // Armazenará a diferença dos milisegundos
    do{
        time_since = time_passed(t) * 1000; // Convertido para milissegundos
    } while(time_since < milliseconds);
}