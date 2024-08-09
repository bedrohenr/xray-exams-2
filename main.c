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
    // Definindo uma data de nascimento fictícia para o paciente
    struct tm birthdate = create_date(90, 5, 15);

    // Criando um paciente
    Patient *patient = create_patient(1, "João Silva", &birthdate);

    // Imprimindo informações do paciente criado
    printf("Paciente criado:\n");
    printf("ID: %d\n", get_patient_id(patient));
    printf("Nome: %s\n", get_patient_name(patient));
    printf("Data de Nascimento: %s\n", asctime(get_patient_birthdate(patient)));
    // Definindo uma data e hora fictícias para o exame
    // time_t current_time;
    struct tm *exam_time = get_time();

    // Tempo do exame éo tempo atual
    // current_time = time(NULL); // Obter o tempo atual em segundos desde 01/01/1970
    // exam_time = localtime(&current_time); // Converter o tempo para a hora local
    
    // Criando um exame associado ao paciente criado
    Exam *exam = create_exam(101, get_patient_id(patient), 1, exam_time);
    
    // Imprimindo informações do exame criado
    printf("\nExame criado:\n");
    printf("ID: %d\n", get_exam_id(exam));
    printf("ID do Paciente: %d\n", get_exam_patient_id(exam));
    printf("ID do Aparelho de Raio-X: %d\n", get_exam_rx_id(exam));
    printf("Data e Hora do Exame: %s\n", asctime(get_exam_time(exam)));


    // Liberando a memória alocada
    destroy_exam(exam);
    // destroy_patient(patient);
    Patient *patient2 = create_patient(3, "Jona", &birthdate);
    Patient *patient3 = create_patient(4, "Andre", &birthdate);
    Patient *patient4 = create_patient(5, "Marcela", &birthdate);


    Queue *PatientQueue = q_create();
    q_enqueue(PatientQueue, TYPE_PATIENT, patient);
    q_enqueue(PatientQueue, TYPE_PATIENT, patient2);
    q_enqueue(PatientQueue, TYPE_PATIENT, patient3);
    q_enqueue(PatientQueue, TYPE_PATIENT, patient4);
    q_print(PatientQueue);

    printf("End Patient Queue\n");

    Queue *XRMachineManager = q_create();

    Exam *exam2 = create_exam(101, get_patient_id(patient), 1, get_time());
    Exam *exam3 = create_exam(102, get_patient_id(patient2), 2, get_time());
    Exam *exam4 = create_exam(103, get_patient_id(patient3), 3, get_time());
    Exam *exam5 = create_exam(104, get_patient_id(patient4), 4, get_time());

    q_enqueue(XRMachineManager, TYPE_EXAM, exam);
    q_enqueue(XRMachineManager, TYPE_EXAM, exam2);
    q_enqueue(XRMachineManager, TYPE_EXAM, exam3);
    q_enqueue(XRMachineManager, TYPE_EXAM, exam4);
    q_enqueue(XRMachineManager, TYPE_EXAM, exam5);

    q_print(XRMachineManager);


    Report *rep1 = create_report(1, 2, get_condition(), get_time());

    Report *rep2 = create_report(1, 2, get_condition(), get_time());
    printf("\nEnded.");

    return 0;
}