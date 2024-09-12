//----------------  Cabeçalho
#include "percentual.h"

//----------------  Implementações
char *LerArquivo(const char *nome_arquivo) 
{   
    size_t tamanho = 0;
    char *json_string = NULL;
    FILE *arquivo;

    arquivo = fopen(nome_arquivo, "rb");

    if (!arquivo) 
    {
        fprintf(stderr, "Erro: falha ao abrir o arquivo '%s'.\n", nome_arquivo);
        return(NULL);
    }

    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    json_string = (char *) malloc(tamanho + 1);

    if (!json_string) 
    {
        printf("Erro: falha ao alocar memoria");
        fclose(arquivo);
        return(NULL);
    }

    fread(json_string, 1, tamanho, arquivo);
    fclose(arquivo);
    json_string[tamanho] = '\0';

    return(json_string);
}

cJSON *ProcessarJson(const char *json_string) 
{
    cJSON *raiz;

    raiz = cJSON_Parse(json_string);

    if (raiz == NULL) 
    {
        fprintf(stderr, "Erro: falha ao analisar o JSON.\n");
        return(NULL);
    }

    return(raiz);
}

cJSON *ObterEstados(cJSON *raiz, const char *nome_array) 
{
    cJSON *estados;

    estados = cJSON_GetObjectItem(raiz, nome_array);

    if (estados == NULL || !cJSON_IsArray(estados)) 
    {   fprintf(stderr, "Erro: O item '%s' nao foi encontrado no objeto JSON.\n", nome_array);
        return(NULL);
    }

    return(estados);
}

cJSON *ProcessarEstado(cJSON *estado_json, Representacao *estado, double *total) 
{
    cJSON *nome_json = cJSON_GetObjectItem(estado_json, "estado");
    cJSON *faturamento_json = cJSON_GetObjectItem(estado_json, "faturamento");

    if (!cJSON_IsString(nome_json) || !cJSON_IsNumber(faturamento_json)) 
    {
        fprintf(stderr, "Erro: O formato do JSON eh invalido para um estado\n");
        return(NULL);
    }

    estado->nome = strdup(nome_json->valuestring);
    estado->faturamento = faturamento_json->valuedouble;
    *total += estado->faturamento;

    return(estado_json);
}

cJSON *ExtrairEstados(cJSON *raiz, Representacao **estados, size_t *num_estados, double *total) 
{
    cJSON *estados_json = ObterEstados(raiz, "estados");

    if (estados_json == NULL) 
    {
        fprintf(stderr, "Erro: Nao foi possivel obter a lista de estados\n");
        return(NULL);
    }

    *num_estados = cJSON_GetArraySize(estados_json);
    *estados = (Representacao *) malloc(*num_estados * sizeof(Representacao));

    if (!*estados) 
    {
        printf("Erro: falha ao alocar memoria");
        return(NULL);
    }

    *total = 0.0;

    for (size_t indice = 0; indice < *num_estados; indice++) 
    {
        cJSON *estado_json = cJSON_GetArrayItem(estados_json, indice);

        if (ProcessarEstado(estado_json, &(*estados)[indice], total) == NULL) 
        {
            free(*estados);
            return(NULL);
        }
    }

    return(estados_json); 
}

void CalcularParticipacao(Representacao *estados, size_t num_estados, double total) 
{
    for (size_t indice = 0; indice < num_estados; indice++) 
    {
        estados[indice].percentual = (estados[indice].faturamento / total) * 100;
    }
}

void ExibirParticipacao(Representacao *estados, size_t num_estados) 
{
    printf("\n-----------------------------------|\n");
    printf("       Faturamento Estadual        |\n");
    printf("-----------------------------------|\n");
    printf("     Estado      |  Participacao   |\n");
    printf("-----------------------------------|\n");


    for (size_t indice = 0; indice < num_estados; indice++) 
    {
        printf("      %-10s |   %8.2lf%%     |\n", estados[indice].nome, estados[indice].percentual);
        free(estados[indice].nome);
    }

    printf("-----------------------------------|\n");
}
