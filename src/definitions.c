#include "definitions.h"

void print_by_struct_type(StructType type, void *p) {
    switch (type) {
        case TYPE_PATIENT:
            print_patient(p);
            break;

        case TYPE_EXAM:
            print_exam(p);
            break;

        // case TYPE_REPORT:
        //     print_report(p);
        //     break;

        default:
            break;
    }
}