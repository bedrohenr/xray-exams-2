#include "definitions.h"

#include <stdio.h>

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

    fprintf(file_pointer, "%s;", content);

    fclose(file_pointer);
}