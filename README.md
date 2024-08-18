# X-Ray Exams
Este código em C consiste em simular o processo de realização de exames de raio-X de tórax em um hospital, com ênfase na organização da fila para laudo médico.

## Dependências
- **[GCC](https://gcc.gnu.org/install/index.html)**, posteriormente usado para compilar o código em C.

## Execução

### Compilação
... Após clonar o repositório, ou baixar:
``` bash
$ cd ./xray-exams
$ make
```
Isso irá executar o arquivo Makefile no _root_ do repositório.

### Testando
Para executar o teste bastas executar o comando abaixo:

``` bash
$ make run
```
ou, opcionalmente, após compilar:
``` bash
$ ./main	
```
Assim, recebendo os outputs do arquivo **main.c**, utilizando os arquivos de cabeçalho e testando-os.

# Arquivos
Aqui especificaremos os conteúdos dos arquivos de cabeçalho e o conteúdo dessas funções criados neste repositório.

## Exam

Define uma struct **Exam** (**Exame**), que consiste de:

### Variáveis

| Variável                        | Tipo          | Finalidade |
| --------------------------------| ------------- | ---------- |
| [id](src/exam.c?#L14)           | Inteiro       | Armazena o número identificador do exame. |
| [patient_id](src/exam.c?#L15)   | Inteiro       | Armazena o número identificador do paciente vinculado ao exame. |
| [rx_id](src/exam.c?#L16)        | Inteiro       | Armazena o número identificador do exame de raio-x deste exame. |
| [condition_IA](src/exam.c?#L17) | Condition *   | Armazena as informações da condição do paciente. Ponteiro para a estrutura Condition. | 
| [time](src/exam.c?#L18)         | Inteiro       | Armazena a instante de tempo que o exame foi feito. |

### Funções
 
| Função                    | Recebe           | Execução | Retorna       |
| ------------------------- | ---------------- | -------- | ------------- |
| [create_exam(...)](src/exam.c?#L22)         | **int**  id,  **int**  patient_id,  **int**  rx_id,  **int** time | Realiza a alocação de memória e atribuições para as variáveis, criando um novo exame. |Exam *       |
| [destroy_exam(...)](src/exam.c?#L54)        | **Exam**  *exam  | Apaga o registro do exame em questão, desalocando-o da memória. |  |
| [get_exam_id(...)](src/exam.c?#L61)         | const **Exam**  *exam  | Retorna o id do paciente passado no argumento. | Inteiro       |
| [get_exam_patient_id(...)](src/exam.c?#L66) | const **Exam**  *exam  | Retorna o id do paciente vinculado ao Exame. | Inteiro       |
| [get_exam_rx_id(...)](src/exam.c?#L71)      | const **Exam**  *exam  | Retorna o id do raio x vinculado ao Exame. | Inteiro       |
| [get_exam_time(...)](src/exam.c?#L76)       | const **Exam**  *exam  | Retorna a unidade de tempo que foi realizado o Exame. | Inteiro       |
| [get_exam_condition(...)](src/exam.c?#L81)  | const **Exam**  *exam  | Ponteiro para o tipo Condition associado ao Exame. | Condition *      |
| [get_exam_condition_id(...)](src/exam.c?#L86)  | const **Exam**  *exam  | Ponteiro para o tipo condition associado ao Exame. | Inteiro       |
| [get_exam_condition_gravity(...)](src/exam.c?#L91)  | const **Exam**  *exam  | Retorna o nível de gravidade da Condition associada ao Exame. | Inteiro       |
| [get_exam_condition_name(...)](src/exam.c?#L96)  | const **Exam**  *exam  | Nome da Condition associada ao Exame. | Char *      |
| [set_exam_condition(...)](src/exam.c?#L102)  | const **Exam**  *exam  | Muda manualmente as propriedades da Condition associada ao Exame. |     |
| [print_exam(...)](src/exam.c?#L113)  | const **Exam**  *exam  | Imprime na tela as propriedades do Exame. |     |
| [exam_output(...)](src/exam.c?#L122)  | const **Exam**  *exam  | Retorna as propriedades do Exame em String. | Char *    |

## Patient

Define a struct **Patient** (**Paciente**), que consiste de:

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [id](src/patient.c?#L11)        | Inteiro        | Armazena o número identificador do exame.                       |
| [name](src/patient.c?#L12)      | Char *         | Armazena o número identificador do paciente vinculado ao exame. |
| [birthdate](src/patient.c?#L13) | Struct tm *    | Armazena o número identificador do exame de raio-x deste exame. |
| [arrival](src/patient.c?#L14)   | Inteiro        | Armazena o número identificador do exame de raio-x deste exame. |

### Funções

| Função                                           | Recebe                | Execução | Retorna        |
| ------------------------------------------------ | --------------------- | -------- |-------------- |
| [create_patient(...)](src/patient.c?#L18)        | **int**  id,  const **char**  *name, **struct  tm**  *birthdate, **int** arrival | Realiza a alocação de memória e atribuições para as variáveis, criando um novo paciente.| Patient * |
| [destroy_patient(...)](src/patient.c?#L47)       | **Patient**  *patient | Apaga o registro do paciente em questão, desalocando-o da memória.|  |
| [get_patient_id(...)](src/patient.c?#L52)        | const **Patient**  *patient | Retorna o id do paciente passado no argumento.| Inteiro |
| [get_patient_name(...)](src/patient.c?#L57)      | const **Patient**  *patient | Retorna o nome do paciente passado no argumento.| Char * |
| [get_patient_birthdate(...)](src/patient.c?#L62) | const **Patient**  *patient | Retorna a data de aniversário do paciente.| Struct tm * |
| [get_patient_arrival(...)](src/patient.c?#L67) | const **Patient**  *patient | Retorna a unidade de tempo de chegada do Patient.| Inteiro |
| [get_patient_birthdate_string(...)](src/patient.c?#L72) | const **Patient**  *patient | Retorna a data de nascimento do Patient em formato YY-mm-dd.| Char * |
| [print_patient(...)](src/patient.c?#L77) | const **Patient**  *patient | Imprime na tela as propriedades do Patient passado no argumento. |  |
| [patient_output(...)](src/patient.c?#L84) | const **Patient**  *patient | Retorna as propriedades do Patient passado como arguemento em uma string. |  |

## Condition

I
Define a struct **Condition** (**Condição**), que consiste de:

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [id](src/condition.c?#L26)        | Inteiro      | Armazena o número identificador da Condition.                       |
| [name](src/condition.c?#L27)      | Char *       | Armazena o nome da Condition. |
| [gravity](src/condition.c?#L28)   | Inteiro      | Armazena o nível de gravidade da Condition. |

### Funções

| Função                                           | Recebe                | Execução | Retorna        |
| ------------------------------------------------ | --------------------- | -------- |-------------- |
| [create_condition(...)](src/condition.c?#L32)    | **int**  id,  const **char**  *name, **int**  gravity | Realiza a alocação de memória e atribuições para as variáveis, criando uma nova Condition.| Condition * |
| [destroy_condition(...)](src/condition.c?#L54)   | **Condition**  condition | Remove e libera alocação de memória do ponteiro do tipo Condition. |  |
| [get_condition_id(...)](src/condition.c?#L59)   | const **Condition**  condition | Retorna o número identificador da Condition passada no argumento. | Inteiro |
| [get_condition_name(...)](src/condition.c?#L64)   | const **Condition**  condition | Retorna o nome da Condition passada no argumento. | Char * |
| [get_condition_name_by_id(...)](src/condition.c?#L69)   | const **Condition**  condition | Retorna o nome da Condition pelo número de identificação. | Char * |
| [get_condition_gravity(...)](src/condition.c?#L76)   | const **Condition**  condition | Retorna a gravidade da Condition passada no argumento. | Char * |
| [get_condition(...)](src/condition.c?#L81)   |  | Retorna um ponteiro criado com a condição escolhida pela probabilidade definida. | Condition * |
| [print_condition(...)](src/condition.c?#L140)   | const **Condition**  condition | Imprime na tela  passada no argumento. |  |
| [condition_output(...)](src/condition.c?#L145)   | const **Condition**  condition | Retorna string com todas informações da Condition passada no argumento em uma string. | Char * |


## Report

Define a struct **Report** (**Laudo**), que consiste de:

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [id](src/report.c?#L10)        | Inteiro      | Armazena o número identificador do Report.                       |
| [exam_id](src/report.c?#L11)     | Inteiro       | Armazena o número identificado do Exame vinculado ao Report. |
| [condition](src/report.c?#L12)   | Condition *      | Armazena a Condition vinculada ao Report. |
| [timestamp](src/report.c?#L13)   | Inteiro      | Armazena a unidade de tempo que foi gerado o Report. |

### Funções

| Função                                           | Recebe                | Execução | Retorna        |
| ------------------------------------------------ | --------------------- | -------- |-------------- |
| [create_report(...)](src/report.c?#L17)    | **int**  id,  **int** exam_id, **Condition** *condition **int** timestamp | Cria um novo Laudo, alocando memória para a estrutura e retornando um ponteiro para a estrutura criada. | Condition * |
| [destroy_report(...)](src/report.c?#L37)    | **Report** report | Libera a memória alocada a estrutura passada no argumento. |  |
| [get_report_id(...)](src/report.c?#L44)    | const **Report** report | Retorna o número identificador do Report. | Inteiro |
| [get_report_exam_id(...)](src/report.c?#L49)    | const **Report** report | Retorna o número identificador do Exame associado ao Report. | Inteiro |
| [get_report_condition(...)](src/report.c?#L54)    | const **Report** report | Retorna a Condition associada ao Report. | Condition * |
| [get_report_condition_id(...)](src/report.c?#L59)    | const **Report** report | Retorna o número identificador da Condition associada ao Report. | Inteiro |
| [get_report_time(...)](src/report.c?#L64)    | const **Report** report | Retorna a unidade de tempo de realização do Report. | Inteiro |
| [check_condition(...)](src/report.c?#L69)    |  **Report** report | Gera um número aleatório e decide se mudará a Condition do Report ou não. |  |
| [change_condition(...)](src/report.c?#L76)    |  **Report** report | Gera uma nova Condition, mudando a atual do Report. |  |
| [print_report(...)](src/report.c?#L92)    |  const **Report** report | Imprime na tela as propriedades do Report passado no argumento. |  |
| [report_output(...)](src/report.c?#L100)    |  const **Report** report | Retorna uma string das propriedades do Report passado no argumento | Char * |

## Queue

Implementação de fila de pointeiros genéricos.
Define a struct **Queue** e **QueueNode**, que consiste de:

**Queue**:

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [front](src/queue.c?#L12)        | QueueNode *     | Armazena o primeiro ponteiro da fila.                       |
| [rear](src/queue.c?#L13)     | QueueNode *      | Armazena o último ponteiro da fila. |

**QueueNode**:

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [info](src/queue.c?#L18)    | void *      | Armazena um ponteiro genérico.                       |
| [type](src/queue.c?#L19)    | StructType       | Armazena o tipo de estrutura do ponteiro genérico. |
| [next](src/queue.c?#L20)    | QueueNode *      | Armazena a posição do próximo nó, ou QueueNode. |

### Funções

| Função                                           | Recebe                | Execução | Retorna        |
| ------------------------------------------------ | --------------------- | -------- |-------------- |
| [q_create(...)](src/queue.c?#L24)    |  | Cria uma nova fila, Queue, alocando memória para a estrutura e retornando um ponteiro para a estrutura criada. | Queue * |
| [q_size(...)](src/queue.c?#L32)    | const **Queue** q | Percorre a fila e retorna a quantidade de elementos na fila. | Inteiro |
| [q_is_empty(...)](src/queue.c?#L41)    | const **Queue** q | Retorna se a fila está vazia ou não. | Inteiro |
| [q_enqueue(...)](src/queue.c?#L46)    | const **Queue** q, **StructType** type, **void** p | Enfileira um ponteiro genérico. |  |
| [q_enqueue_exam_prio(...)](src/queue.c?#L61)    | const **Queue** q, **StructType** type, **void** p | Enfileira um ponteiro Exam inserindo-o na posição da fila devido a prioridade do nível de gravidade da Condition vinculada ao Exam. |  |
| [q_dequeue(...)](src/queue.c?#L111)    | const **Queue** q | Retira o primeiro da fila. | void * |
| [q_free(...)](src/queue.c?#L128)    | const **Queue** q | // Imprime todos os elementos na fila. |  |
| [q_print(...)](src/queue.c?#L144)    | const **Queue** q | // Libera toda a memória da fila. |  |

## Definitions

Consiste nas constantes definidas para o sistema.

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [RUNTIME](src/definitions.c?#L12)        | Inteiro    | Tempo total de execução do programa.                       |
| [SIM_RERPOT_TIME](src/definitions.c?#L13)     | Inteiro       | A cada quantas unidades de tempo mostrar o relatório. |
| [SIM_RERPOT_WAITING_TIME](src/definitions.c?#L13)     | Inteiro | Quanto tempo esperar ao mostrar o relatório. |
| [RNG_DISTRIBUTION](src/definitions.c?#L13)     | Inteiro | Distribuição do número gerado aleatóriamente das Conditions. |
| [I_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número minimo para a I Condition. |
| [I_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a I Condition. |
| [II_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a II Condition. |
| [II_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a II Condition. |
| [III_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a III Condition. |
| [III_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a III Condition. |
| [IV_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a IV Condition. |
| [IV_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a IV Condition. |
| [V_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a V Condition. |
| [V_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a V Condition. |
| [VI_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a VI Condition. |
| [VI_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a VI Condition. |
| [VII_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a VII Condition. |
| [VII_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a VII Condition. |
| [VIII_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a VIII Condition. |
| [VIII_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a VIII Condition. |
| [IX_CONDITION_L](src/definitions.c?#L13)     | Inteiro      | Número mínimo para a IX Condition. |
| [IX_CONDITION_H](src/definitions.c?#L13)     | Inteiro      | Número máximo para a II Condition. |

## Functions
Implementada para conter funções úteis para toda execução do programa.

### Funções

| Função                                           |  Recebe                                  | Execução | Retorna     |
| ------------------------------------------------ | ---------------------------------------- | -------- | ----------- |
| [error_exit(...)](src/functions.c?#L15)          | **int** error_code                       | Finaliza o programa com um código de erro, normalmente, EXIT_FAILURE.|  |
| [validate_int(...)](src/functions.c?#L20)        | **int** num, const **char**  *msg        | Verifica se o número inteiro id é válido, maior que zero. Retorna 0, caso a validação falhe.| Char * |
| [validate_time(...)](src/functions.c?#L33)       | const **struct tm***  time,  **char**  *campo | Verifica se o ano, mês e dia, com a variável do tipo struct tm passada como argumento, são iguais a 0. Caso seja, utiliza das outras funções para mostrar uma mensagem de erro e terminar a execução.|  Inteiro     |
| [validate_string(...)](src/functions.c?#L51)       | const **char** *name,  **int**  id     | Verifica se o a variável string está vazia e mostra mensagem de erro. | Struct tm * |
| [get_random_number(...)](src/functions.c?#L63)       | **int** max_number     | Gera um número aleatório entre 0 e o  número máximo especificado. | Inteiro |
| [get_random_float_number(...)](src/functions.c?#L68)       | **int** max_number     | Gera um número de ponto flutuante aleatório entre 0 e o número máximo especificado. | Inteiro |
| [validate_day_of_month(...)](src/functions.c?#L75)       | **int** month, **int** day | Verifica se o número de dias está correto para o mês especificado. Retorna o dia máximo de dias do mês especificado caso falhe. | Inteiro |
| [create_date(...)](src/functions.c?#L90)       | **int** year, **int** month, **int** day | Cria e retorna uma data com os parâmetros especificados. | Struct tm |
| [get_time(...)](src/functions.c?#L103)  |  | Retorna a Data/Hora atual. | Struct tm * |
| [get_timestamp_from_datetime(...)](src/functions.c?#L110)  | const **struct tm** *date | Retorna um timestamp em string no formato YY-mm-dd HH:MM:SS. | Char * |
| [get_date_from_datetime(...)](src/functions.c?#L119)  | const **struct tm** *date | Retorna data em string no formato YY-mm-dd de uma variável datetime. | Char * |
| [print_by_structure_type(...)](src/functions.c?#L129)  | **StructType** type, **void** *p | Imprime na tela as informações das estruturas. É usado a função correta de cada estrutura. |  |
| [output_by_structure_type(...)](src/functions.c?#L153)  | **StructType** type, **void** *p | Retorna as informações das estruturas em string. É usado a função correta de cada estrutura |  |
| [static create_file(...)](src/functions.c?#L171)  | const **char** *path | Cria um arquivo. | Inteiro |
| [static file_exists(...)](src/functions.c?#L186)  | const **char** *path | Verifica se o arquivo no endereço inserido existe. Retorna 1 se o arquivo existe. | Inteiro |
| [get_db_path(...)](src/functions.c?#L202)  | const **StructType** type | Retorna o arquivo db da estrutura passada no argumento. | Char * |
| [db_save(...)](src/functions.c?#L228)  | const **StructType** type, const **char** *content | Adiciona uma linha no arquivo especificado. | Char * |
| [free_by_structure_type(...)](src/functions.c?#L250)  | const **StructType** type, **void** *p | Libera memória da estrutura devido a seu tipo, usando as funções corretas. | Char * |
| [time_passed(...)](src/functions.c?#L268)  | **clock_t** t | Calcula quanto tempo passou desde um ponto anterior onde originou a variavel t. | double |
| [test_enqueue_prio(...)](src/functions.c?#L276)  | | Cria exames de prioridades diferentes, de forma não sequencial para checar se a lista de prioridade de exame esta funcionando. |  |
| [get_name(...)](src/functions.c?#L335)  | | Retorna uma string com nome e sobrenome gerado aleatoriamente. | Char * |
| [simulation_report(...)](src/functions.c?#L359) | **int** patient_count, **int** patient_queue_count, **int** exam_count, **int** report_count, **int** time_exam_in_queue, **int** *condition_time, **int** *condition_count, **int** condition_array_length, **int** exam_at_defined_time_limit| Mostra os valores selecionados da simulação na tela. | void |
