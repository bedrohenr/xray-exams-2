#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Definição do enum de tipos de estruturas
typedef enum {
    TYPE_PATIENT,
    TYPE_EXAM,
    TYPE_REPORT
} StructType;

// Tempo total de execução do programa.
#define RUNTIME 43200

// A cada quantas unidades de tempo mostrar o relatório.
#define SIM_REPORT_TIME 10000

// Quanto tempo esperar ao mostrar o relatório.
#define SIM_REPORT_WAITING_TIME 5

// --- INÍCIO DEFINIÇÃO DA CONDITION

// Distribuição do número gerado aleatóriamente das Conditions.
#define RNG_DISTRIBUTION 19 // 0 é incluído.

// Número minimo para a I Condition
#define I_CONDITION_L 0
// Número máximo para a I Condition
#define I_CONDITION_H 5

// Número minimo para a II Condition
#define II_CONDITION_L 6
// Número máximo para a II Condition
#define II_CONDITION_H 9

// Número minimo para a III Condition
#define III_CONDITION_L 10
// Número máximo para a III Condition
#define III_CONDITION_H 11

// Número minimo para a IV Condition
#define IV_CONDITION_L 12
// Número máximo para a IV Condition
#define IV_CONDITION_H 13

// Número minimo para a V Condition
#define V_CONDITION_L 14
// Número máximo para a V Condition
#define V_CONDITION_H 14

// Número minimo para a VI Condition
#define VI_CONDITION_L 15
// Número máximo para a VI Condition
#define VI_CONDITION_H 15

// Número minimo para a VII Condition
#define VII_CONDITION_L 16
// Número máximo para a VII Condition
#define VII_CONDITION_H 16

// Número minimo para a VIII Condition
#define VIII_CONDITION_L 17
// Número máximo para a VIII Condition
#define VIII_CONDITION_H 17

// Número minimo para a IX Condition
#define IX_CONDITION_L 18
// Número máximo para a IX Condition
#define IX_CONDITION_H 19

// --- FIM DEFINIÇÃO DA CONDITION

// Tempo limite estabelecido
#define TIME_LIMIT 7200

#endif