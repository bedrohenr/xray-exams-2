#include "patient.h"
#include "exam.h"
#include "condition.h"
#include "functions.h"
#include "report.h"
#include "queue.h"
#include "definitions.h"

#include <stdlib.h> // srand
#include <stdio.h> // printf...

// Função principal de teste
int main() {
   // Iniciando rand.
    srand(time(0));

    // Timer.
    int time_units = 0;

    // id counters.
    int patient_id_counter = 1;
    int exam_id_counter = 1;
    int report_id_counter = 1;

    // Propriedades do paciente.
    char* name;
    struct tm *arrival;
    struct tm birthdate;

    // Variaveis auxiliares
    struct tm *timestamp;

    // Variáveis de struct.
    Patient *patient, *next_patient;
    Exam *exam, *new_exam;
    Report *report;

    // Quantidade de maquina de raio X.
    Patient *XRMachineManager[5] = {};
    int timers[5]; // Usada para armazenar o timer de cada Maquina Raio X.

    // Filas.
    Queue *PatientQueue = q_create();
    Queue *ExamPriorityQueue = q_create();

    while(time_units <= RUNTIME){
        if(time_units == 10000){
            simulation_report(patient_id_counter, q_size(PatientQueue), exam_id_counter, report_id_counter);
        }
        // 20% de chance de chegada de paciente: 1/5.
        if(get_random_number(99) < 20){
            // Obtém nome do paciente
            name = get_name();

            // Horário de chegada do paciente
            arrival = get_time();

            // Definindo uma data de nascimento fictícia para o paciente.
            birthdate = create_date(get_random_number(124), get_random_number(11), get_random_number(31));

            // Criando um paciente
            patient = create_patient(patient_id_counter++, name, &birthdate, arrival);

            // Paciente entra na fila de pacientes.
            q_enqueue(PatientQueue, TYPE_PATIENT, patient);
        }

        // Checando se alguma maquina de raio x está desocupada
        // A primeira desocupada será atrelada ao primeiro usuário na fil
        for(int i = 0; i < 5; i++){
            if(XRMachineManager[i] == NULL && !q_is_empty(PatientQueue)){
                // Retira o paciente da fila e armazena na variável.
                Patient *next_patient = (Patient *) q_dequeue(PatientQueue);

                // Máquina de raio-X recebe novo paciente.
                XRMachineManager[i] = next_patient;
                timers[i] = time_units + 10; // Atualizado timer da máquina: Daqui a 10 unidades de tempo. 
            }
        }

        // Checando se algum exame ja terminou
        for(int i = 0; i < 5; i++){
            if(XRMachineManager[i] != NULL && timers[i] == time_units){
                // Recebe o paciente que estava na máquina de raio-X.
                next_patient = (Patient *) XRMachineManager[i];

                // Salvando timestamp
                timestamp = get_time();

                // Finalizado o uso da máquina de raio-X.
                // Criando novo Exame.
                new_exam = create_exam(exam_id_counter++, get_patient_id(next_patient), (i+1), timestamp);

                // Exame entra na fila de prioridade de exames.
                q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_exam);

                // Variável da máquina de raio-X atualizada: Vazia.
                XRMachineManager[i] = NULL;
                timers[i] = 0; // Timer da máquina resetado.
            }
        }

        // Verifica se a fila de prioridade de exames está vazia.
        if(!q_is_empty(ExamPriorityQueue)){
            
            // Pega o primeira exame na fila de prioridade.
            exam = (Exam *) q_dequeue(ExamPriorityQueue);

            // Salvando timestamp
            timestamp = get_time();

            // Cria um novo laudo com as informações do exame.
            report = create_report(report_id_counter++, get_exam_id(exam), get_exam_condition(exam), timestamp);
            
            // Checa pela condição se precisará ser reavaliado uma nova condição pela % definida.
            check_condition(report);
        }
        // Incrementa unidade de tempo.
        time_units++;

    }

    // Liberando memória.
    destroy_patient(patient);
    destroy_patient(next_patient);
    destroy_exam(exam);
    destroy_exam(new_exam);
    destroy_report(report);
    q_free(PatientQueue);
    q_free(ExamPriorityQueue);
}