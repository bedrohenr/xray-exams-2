#ifndef REPORT_H
#define REPORT_H

#include "condition.h"

#include <time.h>

typedef struct report Report;

Report* create_report(int id, int exam_id, Condition *condition, struct tm *timestamp);

void destroy_report(Report *report);

int get_report_id(Report *report);

int get_report_exam_id(Report *report);

Condition* get_report_condition(Report *report);

struct tm* get_report_time(Report *report);

char* get_report_time_string(Report *report);

void check_condition(Report *report);

void change_condition(Report *report);

void print_report(Report *report);

char* report_output(Report *report);

#endif