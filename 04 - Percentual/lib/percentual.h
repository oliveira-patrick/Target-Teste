/*
  Biblioteca de operações com arquivos JSON. 
  
  Bibliotecas importadas:
    • stdio: Entrada e saída de dados 
    • stdlib: Padrão e de propósito geral
    • string: Definição de tipos lógicos (true e false)
    • math: Operações e dados matemáticos
    • cJSON: Manipulação de arquivos json
  Estruturas:
    • Representacao: Estrutura designada para armazenar e operar os dados de participação do faturamento
    mensal.
  Funções:
    • LerArquivo: Ler o arquivo json
    • ProcessarJson: Converter os dados lidos em uma string       
    • ObterEstados: Processar os estados do arquivo de faturamento
    • ProcessarEstado: Extrair e processar o nome e o faturamento. 
    • ExtrairEstados: processa cada estado e armazena as informações em um array de estruturas 
    • do tipo Representacao
  Procedimentos:
    • CalcularParticipacao: Calcula o percentual de participação de cada estado
    • ExibirParticipacao: Imprime a porcentagem de participação de cada estado
*/

//----------------  Diretrizes de pré-processador
#ifndef PERCENTUAL_H
#define PERCENTUAL_H

//----------------  Dependências/bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cJSON.h"

//----------------  Estruturas/Definições globais
typedef struct {
  char   *nome;
  double faturamento;
  double percentual;
} Representacao;

//----------------  Funções/Procedimentos
char   *LerArquivo          (const char *nome_arquivo);
cJSON  *ProcessarJson       (const char *json_string);
cJSON  *ObterEstados        (cJSON *raiz, const char *nome_array);
cJSON  *ProcessarEstado     (cJSON *estado_json, Representacao *estado, double *total);
cJSON  *ExtrairEstados      (cJSON *raiz, Representacao **estados, size_t *num_estados, double *total);
void   CalcularParticipacao (Representacao *estados, size_t num_estados, double total);
void   ExibirParticipacao   (Representacao *estados, size_t num_estados);

#endif //----------------  Fim fatEstado.h
