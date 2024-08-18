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

Define uma struct **Exam** que consiste de:

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

Define a struct **Patient**, que consiste de:

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

Define a struct **Condition**, que consiste de:

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

Define a struct **Report**, que consiste de:

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

## Functions
Implementada por conter funções úteis para ambas **Exam** e **Patient**.

### Funções

| Função                                           |  Recebe                                  | Execução | Retorna     |
| ------------------------------------------------ | ---------------------------------------- | -------- | ----------- |
| [error_exit(...)](src/functions.c?#L10)          | **int** error_code                       | Finaliza o programa com um código de erro, normalmente, EXIT_FAILURE.|  |
| [error_message_id(...)](src/functions.c?#L14)    | const  **char**  *msg,  **int**  id | Mostra na tela uma mensagem de erro com um id, seja do paciente ou do exame. |  |
| [error_message_field(...)](src/functions.c?#L18) | const  **char**  *msg,  **char** campo | Mostra na tela uma mensagem de erro com o campo de onde foi encontrado o erro. |  |
| [validate_int(...)](src/functions.c?#L23)         | **int**  num,  **char**  *campo          | Verifica se o número é maior que zero, assim, confirmando se é um número válido. Caso não seja, usa as outras funções para mostrar uma mensagem de erro e terminando a execução.| Char * |
| [validate_time(...)](src/functions.c?#L36)       | const  **struct  tm***  time,  **char**  *campo | Verifica se o ano, mês e dia, com a variável do tipo struct tm passada como argumento, são iguais a 0. Caso seja, utiliza das outras funções para mostrar uma mensagem de erro e terminar a execução.|  Inteiro     |
| [validate_name(...)](src/functions.c?#L55)       | const  **char**  *name,  **int**  id     | Verifica se a variável char* passada com argumento é vazia. Caso seja, utiliza as outras funções para mostrar uma mensagem de erro e terminar a execução. | Struct tm * |
