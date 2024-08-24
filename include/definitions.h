#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Definição do enum de tipos de estruturas
typedef enum {
    TYPE_PATIENT,
    TYPE_EXAM,
    TYPE_REPORT
} StructType;

// Endereço do arquivo db Patient.
#define DB_PATIENT_PATH "./src/static/db_patient.txt"

// Endereço do arquivo db Exam.
#define DB_EXAM_PATH "./src/static/db_exam.txt"

// Endereço do arquivo db Report.
#define DB_REPORT_PATH "./src/static/db_report.txt"

// Tempo total de execução do programa.
#define RUNTIME 43200

// A cada quantas unidades de tempo mostrar o relatório.
#define SIM_REPORT_TIME 8640 // 4320 * 2, relatório será mostrado 5 vezes durante a execução completa

// Quanto tempo (em milisegundos) esperar ao mostrar o relatório.
#define SIM_REPORT_WAITING_TIME 1125 // = 1,125s. 1s parecia muito pouco.


// --- INÍCIO DEFINIÇÃO DA CONDITION

// Faixa de números gerados para as Conditions.
#define RNG_INPUT 20

// Probabilidade da Condition I.
#define I_CONDITION_PROB 0.3
// Número minimo para a I Condition.
#define I_CONDITION_L 0
// Número máximo para a I Condition.
#define I_CONDITION_H (I_CONDITION_L + ((RNG_INPUT) * I_CONDITION_PROB) - 1) // 5

// Probabilidade da Condition II.
#define II_CONDITION_PROB 0.2
// Número minimo para a II Condition.
#define II_CONDITION_L (I_CONDITION_H + 1) // 6
// Número máximo para a II Condition.
#define II_CONDITION_H (II_CONDITION_L + (RNG_INPUT * II_CONDITION_PROB - 1)) // 9

// Probabilidade da Condition III.
#define III_CONDITION_PROB 0.1
// Número minimo para a III Condition.
#define III_CONDITION_L (II_CONDITION_H + 1) // 10
// Número máximo para a III Condition.
#define III_CONDITION_H (III_CONDITION_L + (RNG_INPUT * III_CONDITION_PROB - 1))  // 11

// Probabilidade da Condition IV.
#define IV_CONDITION_PROB 0.1
// Número minimo para a IV Condition.
#define IV_CONDITION_L (III_CONDITION_H + 1) // 12
// Número máximo para a IV Condition.
#define IV_CONDITION_H (IV_CONDITION_L + (RNG_INPUT * IV_CONDITION_PROB - 1))   // 13

// Probabilidade da Condition V.
#define V_CONDITION_PROB 0.05
// Número minimo para a V Condition.
#define V_CONDITION_L (IV_CONDITION_H + 1) // 14
// Número máximo para a V Condition.
#define V_CONDITION_H (V_CONDITION_L + (RNG_INPUT * V_CONDITION_PROB - 1))  // 14

// Probabilidade da Condition VI.
#define VI_CONDITION_PROB 0.05
// Número minimo para a VI Condition.
#define VI_CONDITION_L (V_CONDITION_H + 1) // 15
// Número máximo para a VI Condition.
#define VI_CONDITION_H (VI_CONDITION_L + (RNG_INPUT * VI_CONDITION_PROB - 1))  // 15

// Probabilidade da Condition VII.
#define VII_CONDITION_PROB 0.05
// Número minimo para a VII Condition.
#define VII_CONDITION_L (VI_CONDITION_L + 1) // 16
// Número máximo para a VII Condition.
#define VII_CONDITION_H (VII_CONDITION_L + (RNG_INPUT * VII_CONDITION_PROB - 1)) // 16

// Probabilidade da Condition VIII.
#define VIII_CONDITION_PROB 0.05
// Número minimo para a VIII Condition.
#define VIII_CONDITION_L (VII_CONDITION_H + 1) // 17
// Número máximo para a VIII Condition.
#define VIII_CONDITION_H (VIII_CONDITION_L + (RNG_INPUT * VIII_CONDITION_PROB - 1)) // 17

// Probabilidade da Condition IX.
#define IX_CONDITION_PROB 0.1
// Número minimo para a IX Condition.
#define IX_CONDITION_L (VIII_CONDITION_H + 1) // 18
// Número máximo para a IX Condition.
#define IX_CONDITION_H (IX_CONDITION_L + (RNG_INPUT * IX_CONDITION_PROB - 1)) // 19

// Distribuição real do número gerado aleatóriamente das Conditions.
// Recebe o valor da última condition como número máximo a ser gerarado.
#define RNG_DISTRIBUTION IX_CONDITION_H

// --- FIM DEFINIÇÃO DA CONDITION

// Tempo limite estabelecido.
#define TIME_LIMIT 7200

// Quantidade de maquinas de Raio-X.
#define XRAY_MACHINES_QUANTITY 5

// Duração do uso da máquina de Raio-X em unidade de tempo.
#define XRAY_DURATION 10

// Duração da criação do laudo.
#define REPORT_DURATION 20

#endif