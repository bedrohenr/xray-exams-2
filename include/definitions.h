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

struct tm create_date(int ano, int mes, int dia);

struct tm* get_time();

#endif