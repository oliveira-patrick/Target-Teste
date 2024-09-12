/*
  Biblioteca de operações com strings 
  
  Bibliotecas importadas:
    • stdio: Entrada e saída de dados 
    • stdlib: Padrão e de propósito geral
    • stdbool: Definição de tipos lógicos (true e false)
    • string.h: Manipulação de strings
    • math.h: Operações matemáticas
  Definições:
    • Elemento: Estabelece um tipo de dado flexível
  Estruturas:
    • Matriz: Representa uma matriz do tipo elemento
  Funções:
    • IniciarMatriz: Inicializa (Aloca memória) uma matriz do tipo elemento
    • Maiuscula: Testa se um caractere é uma letra maiúscula
    • Minuscula: Testa se um caractere é uma letra minúscula
    • Digito: Testa se um caractere é um digito
    • Letra: Testa se um caractere é uma letra (seja ela maiúscula ou minúscula)
    • Alfanumerico: Testa se um caractere é um alfanumérico (letras ou números)
    • Subtrair: Desloca um caractere no conjunto de caracteres ASCII.
    • Somar: Desloca um caractere no conjunto de caracteres ASCII.
    • ConverterLetras: Converte as letras de uma string (Maiúscula -> Minúscula ou Minúscula -> Maiúscula)
    • InverterString: Inverte as posições dos caracteres de uma string
    • CifraCesar: Criptografa o conteúdo da string ao substituir cada caractere por outro através de um
      deslocamento fixo (Exemplo com deslocamento = 3: 'A' -> 'D', 'B' -> 'E', 'C' -> 'F'... 'Z' -> 'C')
    • CifraTransposicao: Criptografa o conteúdo da string ao rearranjar a ordem dos caracteres
      sem substituí-las(Exemplo: "Gato" -> "aGto")
  Procedimentos:
    • LiberarMatriz: Libera a memória alocada para uma matriz
    • OrdenacaoIndice:  Ordenar os índices das colunas da matriz de acordo com a chave.
    • PreencherMatriz: Preenche a matriz com o conteúdo da string
    • ImprimirString: Exibe no prompt os resultados das operações com a string
*/

//----------------  Diretrizes de pré-processador
#ifndef MYSTRINGS_H
#define MYSTRINGS_H

//----------------  Dependências/bibliotecas
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>

//----------------  Estruturas/Definições globais
typedef char elemento;
typedef struct {
  elemento linhas;
  elemento colunas;
  elemento **dados;
} Matriz;

//----------------  Funções/Procedimentos
Matriz  *IniciarMatriz      (int linhas, int colunas);
bool    Maiuscula           (char caractere);
bool    Minuscula           (char caractere);
char    Subtrair            (char caractere, int valor);
char    Somar               (char caractere, int valor);
char    *ConverterLetras    (char *string, int opcao);
char    *InverterString     (char *string);
char    *CifraCesar         (char *string, int deslocamento);
char    *CifraTransposicao  (char *string, char *chave);
void    LiberarMatriz       (Matriz *matriz);
void    PreencherMatriz     (Matriz *matriz, int linhas, int colunas, char *string, size_t indice_string);
void    OrdenacaoIndice     (char *chave, int *indice_chave, int colunas, size_t indice_string);
void    ImprimirString      (char *string, char *chave);
#endif //----------------  Fim myStrings.h
