#ifndef FUNCTIONS
#define FUNCTIONS

#include <time.h> // struct tm

// Para o programa com o código de erro
void error_exit(int err_code);

// Mostra a mensagem de erro com especificação do campo
void error_message_field(const char *msg, char *campo);

// Mostra a mensagem de erro com especificação do id
void error_message_id(const char *msg, int id);

// Verifica se o inteiro id é válido, maior que zero
int validate_id(int num, char *campo);

// Verifica se o Dia, Mês e Ano é igual a zero  
int validate_time(const struct tm* time, char *campo);

// Verifica se o a variável string está vazia
int validate_name(const char* name, int id);

int get_random_number();

#endif