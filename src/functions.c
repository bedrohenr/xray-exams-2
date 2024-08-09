// Arquivo de cabeçalho criado localmente
#include "functions.h"

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
    srand(time(0));
    return rand() % (max_number + 1);
}

struct tm create_date(int ano, int mes, int dia){
    struct tm date = {0}; // Inicializar a estrutura com zeros

    date.tm_year = ano; // Ano 1990
    date.tm_mon = mes; // Junho (0-indexed)
    date.tm_mday = dia; // Dia 
   
    return date;
}

struct tm* get_time(){
    // Definindo uma data e hora fictícias para o exame
    time_t current_time;
    current_time = time(NULL); // Obter o tempo atual em segundos desde 01/01/1970
    return localtime(&current_time); // Converter o tempo para a hora local
}

