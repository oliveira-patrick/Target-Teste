#include <stdio.h>
#include <stdlib.h>
#include "./lib/faturamento.h"

int main(int argc, char *argv[]) {
    // Declaração de dados
    const char *arquivo = "./json/data.json";
    char *json_string = NULL;
    cJSON *raiz, *dias;
    Estatisticas faturamentos;
    
    // Verifica se um argumento foi passado na linha de comando
    if (argc > 1) 
    {
        arquivo = argv[1];
    }

    // Ler o conteúdo do arquivo JSON
    json_string = LerArquivo(arquivo);
    if (json_string == NULL) 
    {
        return(1); // Erro ao ler o arquivo
    }

    // Converter o conteúdo lido em uma string
    raiz = ProcessarJson(json_string);
    if (raiz == NULL) 
    {
        free(json_string);
        return(1); // Erro ao analisar o JSON
    }

    // Obter os dias
    dias = ObterDias(raiz, "dias");
    if (dias == NULL) 
    {
        cJSON_Delete(raiz);
        free(json_string);
        return(1); // Erro ao obter os dias
    }

    // Calcular os faturamentos
    faturamentos = CalcularEstatisticas(dias);

    // Imprimir os dados na tela
    ExibirEstatisticas(faturamentos, dias);

    // Liberar a memória do objeto JSON e da string JSON
    cJSON_Delete(raiz);
    free(json_string);

    // Fim main
    printf("\nAperte ENTER para encerrar o programa...");
    getchar();
    return 0;
}
