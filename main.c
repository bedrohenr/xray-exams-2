#include "patient.h"
#include "exam.h"
#include "condition.h"
#include "functions.h"
#include "report.h"
#include "queue.h"
#include "definitions.h"

#include <stdio.h> // printf...
#include <time.h>

// Função principal de teste
int main() {
    // Timer
    int time_units = 0;

    // id counters
    int patient_id_counter = 1;
    int exam_id_counter = 1;
    int report_id_counter = 1;

    struct tm birthdate;

    // Variáveis de struct
    Patient *patient, *next_patient;
    Exam *exam, *new_exam;
    Report *report;

    // Quantidade de maquina de raio X
    Patient *XRMachineManager[5] = {};
    int timers[5]; // Usada para o timer de cada Maquina Raio X

    // Filas
    Queue *PatientQueue = q_create();
    Queue *ExamPriorityQueue = q_create();

    while(time_units <= RUNTIME){
        // Data de anivesario gera todos aleatorios
        birthdate = create_date(get_random_number(124), get_random_number(11), get_random_number(31));

        // 20% de chance de chegada de paciente
        if(get_random_number(5) > 1){
            // Definindo uma data de nascimento fictícia para o paciente
            birthdate = create_date(get_random_number(124), get_random_number(11), get_random_number(31));

            // Criando um paciente
            patient = create_patient(patient_id_counter++, "João Silva", &birthdate);

            q_enqueue(PatientQueue, TYPE_PATIENT, patient);
        }

        // Checando se alguma maquina de raio x está desocupada
        // A primeira desocupada será atrelada ao primeiro usuário na fil
        for(int i = 0; i < 5; i++){
            if(XRMachineManager[i] == NULL && !q_is_empty(PatientQueue)){
                // printf("flag if, i: %d", i);
                Patient *next_patient = (Patient *) q_dequeue(PatientQueue);
                XRMachineManager[i] = next_patient;
                printf("\n");
                print_patient(XRMachineManager[i]);
                timers[i] = time_units + 10;
                break;
            }
        }

        // Checando se algum exame ja terminou
        for(int i = 0; i < 5; i++){
            if(XRMachineManager[i] != NULL && timers[i] == time_units){
                next_patient = XRMachineManager[i];
                // printf("test");
                // print_patient(next_patient);
                new_exam = create_exam(exam_id_counter++, get_patient_id(next_patient), (i+1), get_time());

                q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_exam);
                XRMachineManager[i] = NULL;
                timers[i] = 0;
            }
        }

        if(!q_is_empty(ExamPriorityQueue)){
            printf("\nflag report\n");
            // Pega o primeira exame na fila de prioridade
            exam = q_dequeue(ExamPriorityQueue);

            printf("\n");
            print_exam(exam);

            // Cria um novo laudo com as informações do exame
            report = create_report(report_id_counter++, get_exam_id(exam), get_exam_condition(exam), get_time());
            
            // Checa pela condição se precisará ser reavaliado uma nova condição pela % definida
            check_condition(report);

            printf("\n");
            print_report(report);
        }

        printf("hello\n");
        time_units++;
    }
    destroy_report(report);
    q_free(PatientQueue);
    q_free(ExamPriorityQueue);
}