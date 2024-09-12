#include <stdio.h>
#include <stdlib.h>
#include "./lib/fibo.h"

int main(int argc, char *argv[]) {
  // Declaração de dados
  int numero = 0;

  // Verifica se um argumento foi passado na linha de comando 
  if(argc > 1)
  {
    // Converte o argumento para um número inteiro
    char *pointer = NULL;
    numero = strtol(argv[1], &pointer, 10);

    // Verifica se a conversão foi bem-sucedida
    if(*pointer != '\0')
    {
      printf("Erro: '%s' nao eh um numero valido\n", argv[1]);
      return(1);
    }
  } else {
    // Solicita o número ao usuário
    printf("Digite um numero: ");
    if (scanf("%d", &numero) != 1) {
      printf("Erro: Entrada invalida.\n");
      return(1);
    }
  }

  // Verifica se o número pertence à sequência de Fibonacci
  if(VerificarFibonacci(numero))
  {
    printf("\n[%d] eh um numero da serie de Fibonacci.\n\n", numero);
  } else {
    printf("\n[%d] nao eh um numero da serie de Fibonacci.\n\n", numero);
  }

  // Fim main
  printf("\nAperte ENTER para encerrar o programa...");
  getchar();
  return(0);
}
