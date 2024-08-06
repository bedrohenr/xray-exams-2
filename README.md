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
| [id](src/exam.c?#L12)           | Inteiro       | Armazena o número identificador do exame. |
| [patient_id](src/exam.c?#L13)   | Inteiro       | Armazena o número identificador do paciente vinculado ao exame. |
| [rx_id](src/exam.c?#L14)        | Inteiro       | Armazena o número identificador do exame de raio-x deste exame. |
| [time](src/exam.c?#L15)         | Struct tm *   | Armazena a data e hora que o exame foi feito. Consiste em um ponteiro para uma instanciação da struct **tm**, da biblioteca <time.h>. |

### Funções
 
| Função                    | Recebe           | Execução | Retorna       |
| ------------------------- | ---------------- | -------- | ------------- |
| [create_exam(...)](src/exam.c?#L19)         | **int**  id,  **int**  patient_id,  **int**  rx_id,  **struct  tm**  *time | Realiza a alocação de memória e atribuições para as variáveis, criando um novo exame. |Exam *       |
| [destroy_exam(...)](src/exam.c?#L41)        | **Exam**  *exam  | Apaga o registro do exame em questão, desalocando-o da memória. |  |
| [get_exam_id(...)](src/exam.c?#L46)         | const **Exam**  *exam  | Retorna o id do paciente passado no argumento. | Inteiro       |
| [get_exam_patient_id(...)](src/exam.c?#L51) | const **Exam**  *exam  | Retorna o id do paciente vinculado ao exame. | Inteiro       |
| [get_exam_rx_id(...)](src/exam.c?#L56)      | const **Exam**  *exam  | Retorna o id do raio x vinculado ao exame. | Inteiro       |
| [get_exam_time(...)](src/exam.c?#L61)       | const **Exam**  *exam  | Retorna a data e hora que foi realizado o exame. | Inteiro       |

## Patient

Define a struct **Patient**, que consiste de:

### Variáveis

| Variável                        | Tipo           | Finalidade |
| ------------------------------- | -------------- | --------------------------------------------------------------- |
| [id](src/patient.c?#L9)         | Inteiro        | Armazena o número identificador do exame.                       |
| [name](src/patient.c?#L10)      | Char *         | Armazena o número identificador do paciente vinculado ao exame. |
| [birthdate](src/patient.c?#L11) | Struct tm *    | Armazena o número identificador do exame de raio-x deste exame. |

### Funções

| Função                                           | Recebe                | Execução | Retorna        |
| ------------------------------------------------ | --------------------- | -------- |-------------- |
| [create_patient(...)](src/patient.c?#L15)        | **int**  id,  const **char**  *name, **struct  tm**  *birthdate | Realiza a alocação de memória e atribuições para as variáveis, criando um novo paciente.| Patient * |
| [destroy_patient(...)](src/patient.c?#L36)       | **Patient**  *patient | Apaga o registro do paciente em questão, desalocando-o da memória.|  |
| [get_patient_id(...)](src/patient.c?#L41)        | const **Patient**  *patient | Retorna o id do paciente passado no argumento.| Inteiro |
| [get_patient_name(...)](src/patient.c?#L46)      | const **Patient**  *patient | Retorna o nome do paciente passado no argumento.| Char * |
| [get_patient_birthdate(...)](src/patient.c?#L51) | const **Patient**  *patient | Retorna a data de aniversário do paciente.| Struct tm * |

## Functions
Implementada por conter funções úteis para ambas **Exam** e **Patient**.

### Funções

| Função                                           |  Recebe                                  | Execução | Retorna     |
| ------------------------------------------------ | ---------------------------------------- | -------- | ----------- |
| [error_exit(...)](src/functions.c?#L10)          | **int** error_code                       | Finaliza o programa com um código de erro, normalmente, EXIT_FAILURE.|  |
| [error_message_id(...)](src/functions.c?#L14)    | const  **char**  *msg,  **int**  id | Mostra na tela uma mensagem de erro com um id, seja do paciente ou do exame. |  |
| [error_message_field(...)](src/functions.c?#L18) | const  **char**  *msg,  **char** campo | Mostra na tela uma mensagem de erro com o campo de onde foi encontrado o erro. |  |
| [validate_id(...)](src/functions.c?#L23)         | **int**  num,  **char**  *campo          | Verifica se o número é maior que zero, assim, confirmando se é um número válido. Caso não seja, usa as outras funções para mostrar uma mensagem de erro e terminando a execução.| Char * |
| [validate_time(...)](src/functions.c?#L36)       | const  **struct  tm***  time,  **char**  *campo | Verifica se o ano, mês e dia, com a variável do tipo struct tm passada como argumento, são iguais a 0. Caso seja, utiliza das outras funções para mostrar uma mensagem de erro e terminar a execução.|  Inteiro     |
| [validate_name(...)](src/functions.c?#L55)       | const  **char**  *name,  **int**  id     | Verifica se a variável char* passada com argumento é vazia. Caso seja, utiliza as outras funções para mostrar uma mensagem de erro e terminar a execução. | Struct tm * |
