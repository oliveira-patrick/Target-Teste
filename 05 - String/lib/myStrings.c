//----------------  Cabeçalho
#include "myStrings.h"

//----------------  Implementações
Matriz *IniciarMatriz(int linhas, int colunas)
{
  Matriz *matriz;

  matriz = (Matriz *) malloc(sizeof(Matriz));
  if (matriz == NULL) 
  {
    printf("Erro: falha ao alocar memoria");
    exit(1);
  }

  matriz->linhas = linhas;
  matriz->colunas = colunas;

  matriz->dados = (elemento **) malloc(linhas *sizeof(elemento *));
  if (matriz->dados == NULL) 
  {
        printf("Erro: falha ao alocar memoria para as linhas da matriz.\n");
        free(matriz);
        exit(1);
  }

  // Alocar memória para cada linha
  for (size_t indice_externo = 0; indice_externo < linhas; indice_externo++) 
  {
    matriz->dados[indice_externo] = (elemento*)malloc(colunas * sizeof(elemento));
    if (matriz->dados[indice_externo] == NULL) 
    {
      printf("Erro: falha ao alocar memoria para a linha %d da matriz.\n", indice_externo);
      for (size_t indice_interno = 0; indice_interno< indice_externo; indice_interno++) 
      {
        free(matriz->dados[indice_interno]);
      }
      free(matriz->dados);
      free(matriz);
      exit(1);
    }
  }

  return(matriz);
}

bool Maiuscula(char caractere) 
{
  return((caractere >= 'A') && (caractere <= 'Z'));
}

bool Minuscula(char caractere)
{
  return((caractere >= 'a') && (caractere <= 'z'));
}

char Subtrair(char caractere, int valor)
{
  return(caractere - valor);
}

char Somar(char caractere, int valor)
{
  return(caractere + valor);
}

char *ConverterLetras(char *string, int opcao)
{
  size_t indice  = 0, valor = 32, tamanho = 0;
  bool (*teste)(char) = NULL;
  char (*operacao)(char, int) = NULL;
  char *string_convertida = NULL;

  tamanho = strlen(string);

  string_convertida = (char *) malloc(tamanho + 1);
  if(string_convertida == NULL)
  {
    printf("Erro: falha ao alocar memoria");
    return NULL;
  }

  switch(opcao)
  {
    case(1):
      teste = Maiuscula; // Maiúsculas para minúsculas
      operacao = Somar;
      break;
    case(2):
      teste = Minuscula; // Minúsculas para maiúsculas
      operacao = Subtrair;
      break;
    default:
      printf("Erro: Opcao invalida\n");
      break;;
  }

  while(string[indice] != '\0')
  {
    if(teste(string[indice]))
    {
      string_convertida[indice] = operacao(string[indice], valor);
    } else {
      string_convertida[indice] = string[indice];
    }
    indice++;
  }
  string_convertida[indice] = '\0';

  return(string_convertida);
}

char *InverterString(char *string)
{
  size_t tamanho = 0, indice = 0;
  char *string_invertida = NULL; 

  tamanho = strlen(string);

  string_invertida = (char *) malloc(tamanho + 1);
  if(string_invertida == NULL)
  {
    printf("Erro: falha ao alocar memoria");
    exit(1);
  }
  
  while(indice < tamanho)
  {
    string_invertida[indice] = string[tamanho - indice - 1];
    indice++;
  }
  string_invertida[tamanho] = '\0';

  return(string_invertida);
}

char *CifraCesar(char *string, int deslocamento)
{
  size_t indice = 0, tamanho = 0;
  char caractere;
  char *string_cifrada = NULL;

  tamanho = strlen(string);

  string_cifrada = (char *) malloc((tamanho + 1) * sizeof(char));
  if(string_cifrada == NULL)
  {
    printf("Erro: falha ao alocar memoria");
    return NULL;
  }

  for(indice = 0; string[indice] != '\0'; indice++)
  {
    caractere = string[indice];

    if(Maiuscula(caractere))
    {
      caractere = ((caractere - 'A') + deslocamento) % 26 + 'A';
    } else if(Minuscula) {
      caractere = ((caractere - 'a') + deslocamento) % 26 + 'a';
    }
    string_cifrada[indice] = caractere;
  }
  string_cifrada[indice] = '\0';

  return(string_cifrada);
}

char *CifraTransposicao(char *string, char *chave)
{
  size_t tamanho = 0, indice_externo = 0, indice_interno = 0, indice_chave[100], indice_string = 0;
  int linhas = 0, colunas = 0;
  char *string_transposta = NULL; 
  Matriz *matriz;

  tamanho = strlen(string);

  string_transposta = (char *) malloc(tamanho + 1);
  if(string_transposta == NULL)
  {
    printf("Erro: falha ao alocar memoria");
    exit(1);
  }

  colunas = strlen(chave);
  linhas = (int) ceil((double) strlen(string) / colunas);

  matriz = IniciarMatriz(linhas, colunas);
  
  PreencherMatriz(matriz, linhas, colunas, string, indice_string);

  OrdenacaoIndice(chave, indice_chave, colunas, indice_string);

  indice_string = 0;

  // Reconstroi o texto cifrado lendo as colunas na ordem da chave
  for (indice_externo = 0; indice_externo < colunas; indice_externo++) 
  {
    for (indice_interno = 0; indice_interno < linhas; indice_interno++) 
    {
      if (matriz->dados[indice_interno][indice_chave[indice_externo]] != ' ') 
      {
        string_transposta[indice_string] = matriz->dados[indice_interno][indice_chave[indice_externo]];
        indice_string++;
      }
    }
  }
  string_transposta[indice_string] = '\0';

  LiberarMatriz(matriz);
  
  return(string_transposta);
}

void LiberarMatriz(Matriz *matriz)
{
  if (matriz != NULL && matriz->dados != NULL) 
  {
    for (size_t indice = 0; indice < matriz->linhas; indice++) 
    {
      free(matriz->dados[indice]);
    }

    free(matriz->dados);
    free(matriz);
  }
}

void PreencherMatriz(Matriz *matriz, int linhas, int colunas, char *string, size_t indice_string) 
{
  size_t indice_externo = 0, indice_interno = 0;

  for(indice_externo = 0; indice_externo < linhas; indice_externo++)
  {
    for(indice_interno = 0; indice_interno < colunas; indice_interno++)
    {
      matriz->dados[indice_externo][indice_interno] = ' ';
    }
  }

  for(indice_externo = 0; indice_externo < linhas; indice_externo++)
  {
    for(indice_interno = 0; indice_interno < colunas; indice_interno++)
    { 
      if(indice_string < strlen(string))
      {
        matriz->dados[indice_externo][indice_interno] = string[indice_string];
        indice_string++;
      }
    }
  }
}

void OrdenacaoIndice(char *chave, int *indice_chave, int colunas, size_t indice_string) 
{
  int temp = 0;

  for(size_t indice = 0; indice < colunas; indice++)
  {
    indice_chave[indice] = indice;
  }

  for (size_t indice_externo = 0; indice_externo < colunas - 1; indice_externo++) 
  {
    for (size_t indice_interno = indice_externo + 1; indice_interno < colunas; indice_interno++) 
    {
      if(chave[indice_chave[indice_externo]] > chave[indice_chave[indice_interno]]) 
      {
        temp = indice_chave[indice_externo];
        indice_chave[indice_externo] = indice_chave[indice_interno];
        indice_chave[indice_interno] = temp;
      }
    }
  }
}

void ImprimirString(char *string, char *chave)
{ 
  char **string_manipulada = (char **) malloc(5 * sizeof(char *));

  string_manipulada[0] =  InverterString(string);
  string_manipulada[1] =  ConverterLetras(string, 2);
  string_manipulada[2] =  ConverterLetras(string, 1);
  string_manipulada[3] =  CifraCesar(string, 3);
  string_manipulada[4] =  CifraTransposicao(string, chave);

  printf("\n--------------------------------------|\n");
  printf("      String Original: %s       |\n", string);
  printf("--------------------------------------|\n");
  printf("     Operacao     |     Resultado     |\n");
  printf("--------------------------------------|\n");
  printf("     Inverso      |     %-10s    |\n", string_manipulada[0]);
  printf("     Maiuscula    |     %-10s    |\n", string_manipulada[1]);
  printf("     Minuscula    |     %-10s    |\n", string_manipulada[2]);
  printf("     Cesar        |     %-10s    |\n", string_manipulada[3]);
  printf("     Transposicao |     %-10s    |\n", string_manipulada[4]);
  printf("--------------------------------------|\n");

  free(string_manipulada);
}
