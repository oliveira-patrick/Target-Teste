/*
  Biblioteca de operações com arquivos JSON. 
  
  Bibliotecas importadas:
    • stdio: Entrada e saída de dados 
    • stdlib: Padrão e de propósito geral
    • string: Definição de tipos lógicos (true e false)
    • math: Operações e dados matemáticos
    • cJSON: Manipulação de arquivos json
  Estruturas:
    • Estatisticas: Estrutura designada para armazenar e operar os dados do faturamento.(Datas e Valores)
  Funções:
    • LerArquivo: Ler o arquivo json
    • ProcessarJson: Converter os dados lidos em uma string       
    • ObterDias: Processar os dias do arquivo de faturamento
    • IniciarEstatisticas: Iniciar as estatisticas do faturamento
    • CalcularMedia: Calcular a média do faturamento
    • CalcularExtremos: Determinar o maior e o menor faturamento, além de contar os dias acima da média
    • CalcularEstatisticas: Calcular e armazenar todas as estatísticas
  Procedimentos:
    • ExibirEstatisticas: Imprimir e formatar os resultados no prompt
*/

//----------------  Diretrizes de pré-processador
#ifndef FATURAMENTO_H
#define FATURAMENTO_H

//----------------  Dependências/bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cJSON.h"

//----------------  Estruturas/Definições globais
typedef struct {
    int num_dias; 
    int dias_acima_media;
    double soma;
    double media;
    double min_valor;
    double max_valor;
    const char *data_min_valor;
    const char *data_max_valor;
} Estatisticas;

//----------------  Funções/Procedimentos
char        *LerArquivo           (const char *nome_arquivo);
cJSON       *ProcessarJson        (const char *json_string);
cJSON       *ObterDias            (cJSON *raiz, const char *nome_array);
Estatisticas IniciarEstatisticas  ();
Estatisticas CalcularMedia        (cJSON *dias, Estatisticas resultados);
Estatisticas CalcularExtremos     (cJSON *dias, Estatisticas resultados);
Estatisticas CalcularEstatisticas (cJSON *dias);
void         ExibirEstatisticas   (Estatisticas faturamento, cJSON *dias);

#endif //----------------  Fim faturamento.h
