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
    // Resetando os arquivos db
    db_reset();

   // Iniciando rand.
    srand(time(0));

    // Timer.
    int time = 0;

    // id counters.
    int patient_id_counter = 1;
    int exam_id_counter = 1;
    int report_id_counter = 1;

    // Propriedades do paciente.
    char* name;
    struct tm birthdate;
    int year;
    int month;
    int day;

    // Variaveis auxiliares
    int timestamp;
    int arrival;

    // Variáveis para o relatório de tempo do exame
    int sim_report_timer = SIM_REPORT_TIME; // A cada quantas u.t. mostrar o relatório
    int condition_id; // aux
    int novo_paciente; // Armazena se chegou novo paciente
    int exam_queue_time = 0;
    int condition_count[9] = {0}; // Quantos exames tiveram de cada condition.
    int condition_time[9]  = {0}; // Tempo que levou cada condition do exame.
    int condition_array_length;
    int exam_at_defined_time_limit = 0;

    // Variáveis de struct.
    Patient *patient, *next_patient;
    Exam *exam, *new_exam;
    Report *report;

    // Quantidade de maquina de raio X.
    Patient *XRMachineManager[XRAY_MACHINES_QUANTITY] = {};
    int XRMachineTimer[XRAY_MACHINES_QUANTITY]; // Usada para armazenar o timer de cada Maquina Raio X.

    // Filas.
    Queue *PatientQueue = q_create();
    Queue *ExamPriorityQueue = q_create();

    printf("Simulação iniciada.");
    // Programa irá rodar até o tempo definido em RUNTIME (43200 ut)
    while(time <= RUNTIME){
        // Salva a quantidade de pacientes no tempo estabelecido, no relatorio subtrai pelo final
        if(time == TIME_LIMIT){
            exam_at_defined_time_limit = patient_id_counter;
        }
        // Relatório
        if(time == sim_report_timer){
            // Tamanho do array de conditions
            condition_array_length = sizeof(condition_count)/sizeof(condition_count[0]);
            // Chamada para a função do relatório
            simulation_report(patient_id_counter, q_size(PatientQueue), exam_id_counter, report_id_counter, exam_queue_time, condition_time, condition_count, condition_array_length, exam_at_defined_time_limit);
            printf("\nRetornando a simulação...");
            sim_report_timer += time; // Incrementa o timer
        }
        // 20% de chance de chegada de paciente
        // Gera um número de 0 a 4 -> 1/5
        novo_paciente = get_random_number(4) == 0;
        if(novo_paciente){ // Checa se novo paciente
            // Obtém nome do paciente aleatoriamente
            name = get_name(); 

            // Salvando a hora de chegada do paciente
            arrival = time;

            // Definindo uma data de nascimento fictícia para o paciente.
            year = get_random_number(124); // Gera um número de 0 a 124, que vai ser adicionado a 1900
            month = get_random_number(11); // Gera um número de 0 a 11
            day = get_random_number(31);   // Gera um número de 0 a 31
            birthdate = create_date(year, month, day);  // Recebe um struct tm com os números

            // Criando um paciente
            patient = create_patient(patient_id_counter++, name, &birthdate, arrival);

            // Paciente entra na fila de pacientes.
            q_enqueue(PatientQueue, TYPE_PATIENT, patient);
        }

        // Checando se alguma maquina de raio x está desocupada
        // A primeira desocupada será atrelada ao primeiro usuário na fil
        for(int i = 0; i < XRAY_MACHINES_QUANTITY; i++){
            if(XRMachineManager[i] == NULL && !q_is_empty(PatientQueue)){
                // Retira o paciente da fila e armazena na variável.
                Patient *next_patient = (Patient *) q_dequeue(PatientQueue);

                // Máquina de raio-X recebe novo paciente.
                XRMachineManager[i] = next_patient;
                XRMachineTimer[i] = time + XRAY_DURATION; // Atualizado timer da máquina: Daqui a 10 unidades de tempo. 
            }
        }

        // Checando se algum exame ja terminou
        for(int i = 0; i < XRAY_MACHINES_QUANTITY; i++){
            if(XRMachineManager[i] != NULL && XRMachineTimer[i] == time){
                // Recebe o paciente que estava na máquina de raio-X.
                next_patient = (Patient *) XRMachineManager[i];

                // Salvando timestamp
                timestamp = time;

                // Finalizado o uso da máquina de raio-X.
                // Criando novo Exame.
                new_exam = create_exam(exam_id_counter++, get_patient_id(next_patient), (i+1), timestamp);

                // Exame entra na fila de prioridade de exames.
                q_enqueue_exam_prio(ExamPriorityQueue, TYPE_EXAM, new_exam);

                // Variável da máquina de raio-X atualizada: Vazia.
                XRMachineManager[i] = NULL;
                XRMachineTimer[i] = 0; // Timer da máquina resetado.
            }
        }

        // Verifica se a fila de prioridade de exames está vazia.
        if(!q_is_empty(ExamPriorityQueue)){
            
            // Pega o primeira exame na fila de prioridade.
            exam = (Exam *) q_dequeue(ExamPriorityQueue);

            // Salvando timestamp
            timestamp = time;

            // Incrementando total de tempo na fila para o relatório;
            exam_queue_time += time - get_exam_time(exam);

            // Cria um novo laudo com as informações do exame.
            report = create_report(report_id_counter++, get_exam_id(exam), get_exam_condition(exam), timestamp);
            
            // Checa pela condição se precisará ser reavaliado uma nova condição pela % definida.
            check_condition(report);

            // Faz com que obtenha o id da condition após reavaliação, se houver.
            condition_id = get_report_condition_id(report) - 1; // Ids começa em 1, arrays em 0
            condition_count[condition_id] += 1;  // Armazena quantidade de cada condition
            condition_time[condition_id] += time - get_exam_time(exam); // Tempo acumulado de cada condition.

            // Libera memória do laudo recém criado.
            destroy_report(report);
        }
        // Incrementa unidade de tempo.
        time++;
    }

    printf("Simulação concluída.");

    // Liberando memória.
    destroy_patient(patient);
    destroy_patient(next_patient);
    destroy_exam(exam);
    destroy_exam(new_exam);
    q_free(PatientQueue);
    q_free(ExamPriorityQueue);
}