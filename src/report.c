#include "report.h"
#include "definitions.h"
#include "functions.h"

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

    db_save(report_output(new_report), TYPE_REPORT);

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

char* report_output(Report *report){
    char *output = (char *)malloc(sizeof(char) * 128);
    sprintf(output, "%d,%d,%s,%s", get_report_id(report), get_report_exam_id(report), condition_output(get_report_condition(report)), get_timestamp_from_datetime(get_report_time(report)));
    return output;
}