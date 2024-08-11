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
#include <windows.h>

// Mostra uma mensagem de erro e para o programa com o código de erro
void error_exit(int err_code){
    exit(err_code);
}

void error_message_id(const char *msg, int id){
    printf("%s: %d.", msg, id);
}

void error_message_field(const char *msg, char *campo){
    printf("%s: %s.", msg, campo);
}

// Verifica se o inteiro id é válido, maior que zero
int validate_id(int num, char *campo){
    if ( num > 0 ) {
        return 1;
    } else {
        // Mensagem de erro
        error_message_field("Erro.\nNumero inválido em campo", campo);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
        return 0;
    }
}

// Verifica se o Dia, Mês e Ano é igual a zero  
int validate_time(const struct tm* time, char *campo){

    if( time->tm_year == 0 &&
        time->tm_mon  == 0 &&
        time->tm_mday == 0 ){

        char msg[] = "Data/Hora não informada no campo: ";
        strcat(msg, campo);

        // Mensagem de erro
        error_message_field("Erro.\nData/Hora não informada no campo", campo);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
        return 0;
    } 
    return 1;
}

// Verifica se o a variável string está vazia
int validate_name(const char* name, int id){
    if( strcmp(name, "") == 0 || strcmp(name, " ") == 0){
        // Mensagem de erro
        error_message_id("Erro.\nNão foi possível encontrar o nome do paciente com id", id);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
        return 0;
    }
    return 1;
}

int get_random_number(int max_number){
    srand(time(NULL));
    return rand() % (max_number + 1);
}

float get_random_float_number(float max_number){
    srand((unsigned int)time(NULL));

    return ((rand()/(float)(RAND_MAX)) * max_number);
}

int validate_day_of_month(int month, int day){
    if(month > 11)
        month = 11;

    int DAYS_IN_MONTH[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(day > DAYS_IN_MONTH[month])
        return DAYS_IN_MONTH[month];
    else
        return day;
}

struct tm create_date(int year, int month, int day){
    struct tm date = {0}; // Inicializar a estrutura com zeros

    day = validate_day_of_month(month, day);

    date.tm_year = year; // Ano 1990
    date.tm_mon = month; // Junho (0-indexed)
    date.tm_mday = day; // Dia 
   
    return date;
}

struct tm* get_time(){
    // Definindo uma data e hora fictícias para o exame
    time_t current_time;
    current_time = time(NULL); // Obter o tempo atual em segundos desde 01/01/1970
    return localtime(&current_time); // Converter o tempo para a hora local
}

// YY-mm-dd HH:MM:SS
char* get_timestamp_from_datetime(struct tm* date){
    char *output = (char *)malloc(sizeof(char) * 32);
    // date->tm_year retorna quantos anos desde 1900
    sprintf(output, "%d-%d-%d %d:%d:%d", (1900 + date->tm_year), date->tm_mon, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
    return output;
}

// YY-mm-dd
char* get_date_from_datetime(struct tm* date){
    char *output = (char *)malloc(sizeof(char) * 32);
    // date->tm_year retorna quantos anos desde 1900
    sprintf(output, "%d-%d-%d", (1900 + date->tm_year), date->tm_mon, date->tm_mday);
    return output;
}

void print_by_struct_type(StructType type, void *p) {
    switch (type) {
        case TYPE_PATIENT:
            print_patient(p);
            break;

        case TYPE_EXAM:
            print_exam(p);
            break;

        case TYPE_REPORT:
            print_report(p);
            break;

        default:
            break;
    }
}

char* output_by_struct_type(StructType type, void *p) {
    switch (type) {
        case TYPE_PATIENT:
                return patient_output(p);
                break;

        case TYPE_EXAM:
            return exam_output(p);
            break;

        case TYPE_REPORT:
            return report_output(p);
            break;
    }
}

void db_save(char *content, StructType type){
    char *path;
    switch (type) {
        case TYPE_PATIENT:
            printf("flag patient");
            path = "./src/static/db_patient.txt";
            break;
        
        case TYPE_EXAM:
            printf("flag exam");
            path = "./src/static/db_exam.txt";
            break;
        
        case TYPE_REPORT:
            printf("flag report");
            path = "./src/static/db_report.txt";
            break;

        default:
            break;
    }

    FILE *file_pointer; 

    file_pointer = fopen(path, "a");

    fprintf(file_pointer, "%s\n", content);

    fclose(file_pointer);
}

void free_by_struct_type(StructType type, void *p) {
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

        default:
            break;
    }
}
