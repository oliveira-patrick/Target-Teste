//----------------  Cabeçalho
#include "fibo.h"

//----------------  Implementações
double ValorAbsoluto(double numero) 
{
  if(numero >= 0) {
    return(numero);
  } else {
    return(-numero);
  }
}

double RaizQuadrada(double n) 
{
  double numero  = 0.0;
  double epsilon = 0.0;

  if(n < 0) 
  {
    printf("Erro: Nao eh possivel extrair raiz quadrada de um numero negativo");
    return(-1);
  }

  numero  = (n / 2);
  epsilon = 0.000001;

  while (ValorAbsoluto((numero * numero) - n) > epsilon)
  {
    numero = 0.5 * (numero + n / numero);
  }
  return(numero);
}

bool VerificarQuadradoPerfeito(int numero) 
{
  int square = (int) RaizQuadrada(numero);

  if((square * square) == numero)
  {
    return(true);
  } else {
    return(false);
  }
}

bool VerificarFibonacci(int numero) 
{
  int exp = 0;

  exp = (5 * numero * numero);

  if(VerificarQuadradoPerfeito(exp + 4) || VerificarQuadradoPerfeito(exp - 4))
  {
    return(true);
  } else {
    return(false);
  }
}
