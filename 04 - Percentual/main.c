#include <stdio.h>
#include <stdlib.h>
#include "./lib/percentual.h"

int main(int argc, char *argv[]) {
    const char *nome_arquivo = "./json/estados.json";
    char *json_str = NULL;
    double total = 0.0;
    cJSON *raiz;
    Representacao *estados = NULL;
    size_t num_estados = 0;

    json_str = LerArquivo(nome_arquivo);
    if (!json_str) 
    {
        return(1);
    }

    raiz = ProcessarJson(json_str);
    if (!raiz) 
    {
        free(json_str);
        return(1);
    }

    if (ExtrairEstados(raiz, &estados, &num_estados, &total) == NULL) 
    {
        free(json_str);
        cJSON_Delete(raiz);
        return(1);
    }

    CalcularParticipacao(estados, num_estados, total);
    ExibirParticipacao(estados, num_estados);

    free(estados);
    free(json_str);
    cJSON_Delete(raiz);

    printf("\nAperte ENTER para encerrar o programa...");
    getchar();
    return 0;
}
