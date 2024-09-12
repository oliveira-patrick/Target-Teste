#include <stdio.h>
#include <stdlib.h>
#include "./lib/myStrings.h"

int main(int argc, char *argv[]) {
  // Declaração de dados
  char *string = "PrYtHiAn";
  char *chave = "chave muito complexa e legal";

  if(argc > 1) 
  {
    string = argv[1];
  }

  ImprimirString(string, chave);

  // Fim main
  printf("\nAperte ENTER para encerrar o programa...");
  getchar();  
  return(0);
}
