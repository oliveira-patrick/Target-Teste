/*
  Biblioteca de operações para a série de Fibonacci. 
  
  Bibliotecas importadas:
    • stdio: Entrada e saída de dados 
    • stdlib: Padrão e de propósito geral
    • stdbool: Definição de tipos lógicos (true e false)
  Funções:
    • ValorAbsoluto: Determinar o valor absoluto de um número
    • RaizQuadrada: Calcular a raíz quadrada de um número       
    • VerificarQuadradoPerfeito: Verificar se um número é um quadrado perfeito
    • VerificarFibonacci: Averiguar se um número faz parte da série de Fibonacci
*/

//----------------  Diretrizes de pré-processador
#ifndef FIBO_H
#define FIBO_H

//----------------  Dependências/bibliotecas
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

//----------------  Funções
double ValorAbsoluto              (double numero);
double RaizQuadrada               (double n);
bool   VerificarQuadradoPerfeito  (int numero);
bool   VerificarFibonacci         (int numero);

#endif //----------------  Fim fibo.h