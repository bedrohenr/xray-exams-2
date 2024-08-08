#include "definitions.h"

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