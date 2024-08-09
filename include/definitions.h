#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "patient.h"
#include "exam.h"
#include "report.h"

typedef enum {
    TYPE_PATIENT,
    TYPE_EXAM,
    TYPE_REPORT
} StructType;

void print_by_struct_type(StructType type, void *p);

char* output_by_struct_type(StructType type, void *p);

void db_save(char *content, StructType type);

#endif