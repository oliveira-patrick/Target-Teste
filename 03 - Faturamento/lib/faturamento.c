//----------------  Cabeçalho
#include "faturamento.h"

//----------------  Implementações
char *LerArquivo(const char *nome_arquivo) 
{   
    size_t tamanho = 0;
    char *json_string = NULL;
    FILE *arquivo;

    arquivo = fopen(nome_arquivo, "rb");

    if (!arquivo) 
    {
        fprintf(stderr, "Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
        return(NULL);
    }

    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    json_string = (char *) malloc(tamanho + 1);

    if (!json_string) 
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        fclose(arquivo);
        free(json_string);
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
        fprintf(stderr, "Erro ao analisar o JSON.\n");
        cJSON_Delete(raiz);
        return(NULL);
    }

    return(raiz);
}

cJSON *ObterDias(cJSON *raiz, const char *nome_array) 
{
    cJSON *dias;

    dias = cJSON_GetObjectItem(raiz, nome_array);

    if (dias == NULL || !cJSON_IsArray(dias)) 
    {
        return(raiz);
    }

    return(dias);
}

Estatisticas IniciarEstatisticas() 
{ 
    Estatisticas estatisticas;

    estatisticas.soma = 0.0;
    estatisticas.media = 0.0;
    estatisticas.num_dias = 0;
    estatisticas.min_valor = INFINITY;
    estatisticas.max_valor = -INFINITY;
    estatisticas.dias_acima_media = 0;
    estatisticas.data_min_valor = NULL;
    estatisticas.data_max_valor = NULL;

    return(estatisticas);
}

Estatisticas CalcularMedia(cJSON *dias, Estatisticas estatisticas) 
{   
    size_t num_dias = 0, tamanho = 0;
    double soma = 0.0, valor = 0.0;
    cJSON *dia, *valor_;

    if (!cJSON_IsArray(dias)) 
    {
        return(estatisticas);
    }
    
    tamanho = cJSON_GetArraySize(dias);

    for (size_t indice = 0; indice < tamanho; indice++) 
    {
        dia = cJSON_GetArrayItem(dias, indice);
        valor_ = cJSON_GetObjectItem(dia, "valor");

        if (valor_ && cJSON_IsNumber(valor_)) 
        {
            valor = valor_->valuedouble;

            if (valor != 0.0) 
            {
                num_dias++;
                soma += valor;
            }
        }
    }

    if (num_dias > 0) 
    {
        estatisticas.media = soma / num_dias;
    }

    estatisticas.soma = soma;
    estatisticas.num_dias = num_dias;

    return(estatisticas);
}

Estatisticas CalcularExtremos(cJSON *dias, Estatisticas estatisticas) 
{   
    size_t tamanho = 0; tamanho = 0;
    double valor = 0.0;
    cJSON *dia, *data_, *valor_;

    if (!cJSON_IsArray(dias)) 
    {
        return(estatisticas);
    }

    tamanho = cJSON_GetArraySize(dias);

    for (size_t indice = 0; indice < tamanho; indice++) 
    {
        dia = cJSON_GetArrayItem(dias, indice);
        data_ = cJSON_GetObjectItem(dia, "data");
        valor_ = cJSON_GetObjectItem(dia, "valor");

        if (data_ && cJSON_IsString(data_) && valor_ && cJSON_IsNumber(valor_)) 
        {
            valor = valor_->valuedouble;
            if (valor < estatisticas.min_valor) 
            {
                estatisticas.min_valor = valor;
                estatisticas.data_min_valor = data_->valuestring;
            }
            if (valor > estatisticas.max_valor) 
            {
                estatisticas.max_valor = valor;
                estatisticas.data_max_valor = data_->valuestring;
            }
            if (valor > estatisticas.media) 
            {
                estatisticas.dias_acima_media++;
            }
        }
    }

    return(estatisticas);
}

Estatisticas CalcularEstatisticas(cJSON *dias) 
{
    Estatisticas estatisticas;

    estatisticas = IniciarEstatisticas();
    estatisticas = CalcularMedia(dias, estatisticas);
    estatisticas = CalcularExtremos(dias, estatisticas);

    return(estatisticas);
}

void ExibirEstatisticas(Estatisticas faturamentos, cJSON *dias)
{
    size_t tamanho = 0;
    cJSON *dia, *data_, *valor_;

    printf("\n---------------------------|\n");
    printf("        Faturamento        |\n");
    printf("---------------------------|\n");
    printf("    Data    |    Valor     |\n");
    printf("---------------------------|\n");

    tamanho = cJSON_GetArraySize(dias);

    for (size_t indice = 0; indice < tamanho; indice++) 
    {
        dia = cJSON_GetArrayItem(dias, indice);
        data_ = cJSON_GetObjectItem(dia, "data");
        valor_ = cJSON_GetObjectItem(dia, "valor");

        if (data_ && cJSON_IsString(data_) && valor_ && cJSON_IsNumber(valor_)) 
        {
            printf(" %-10s |  %8.2lf    |\n", data_->valuestring, valor_->valuedouble);
        }
    }

    printf("-------------------------------------------------------------|\n");
    printf("                       Estatisticas                          |\n");
    printf("-------------------------------------------------------------|\n");
    printf(" Menor faturamento                   | %s - %6.2lf   |\n", faturamentos.data_min_valor ? faturamentos.data_min_valor : "N/A", faturamentos.min_valor);
    printf(" Maior faturamento                   | %s - %6.2lf  |\n", faturamentos.data_max_valor ? faturamentos.data_max_valor : "N/A", faturamentos.max_valor);
    printf(" Media                               | %6.2lf                |\n", faturamentos.media);
    printf(" Numero de dias com faturamento      | %d                     |\n", faturamentos.num_dias);
    printf(" Dias com faturamento acima da media | %d                     |\n", faturamentos.dias_acima_media);
    printf("-------------------------------------------------------------|\n");
}
