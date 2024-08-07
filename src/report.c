#include "report.h"

#include <stdlib.h>
#include <stdio.h>

struct report {
    int id;
    int exam_id;
    Condition *condition;
    struct tm *timestamp;
} report;

Report* create_report(int id, int exam_id, Condition *condition, struct tm *timestamp){
    Report *new_report = (Report *)malloc(sizeof(Report));

    new_report->id = id;
    new_report->exam_id = exam_id;
    new_report->condition = condition;
    new_report->timestamp = timestamp;

    return new_report;
}

void destroy_report(Report *report){
    destroy_condition(report->condition);
    free(report);
}

int get_report_id(Report *report){
    return report->id;
}

int get_report_exam_id(Report *report){
    return report->exam_id;
}

Condition* get_report_condition(Report *report){
    return report->condition;
}

struct tm* get_report_time(Report *report){
    return report->timestamp;
}

char* get_report_time_string(Report *report){
    return asctime(get_report_time(report));
}

void print_report(Report *report){
    printf("Laudo\nId do Laudo: %d\n", get_report_id(report));
    printf("Id do Exame: %d\n", get_report_exam_id(report));
    print_condition(get_report_condition(report));
    printf("Laudo gerado em: %s", get_report_time_string(report)); 
}