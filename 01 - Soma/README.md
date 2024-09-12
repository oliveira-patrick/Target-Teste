# Código 01 - Soma

**Observe o trecho de código abaixo:**
```bash

int INDICE = 13, SOMA = 0, K = 0;

Enquanto K < INDICE faça 
{ 
    K = K + 1; 
    SOMA = SOMA + K; 
}
Imprimir(SOMA);
```

**Ao final do processamento, qual será o valor da variável SOMA?**
## Resposta

Antes de tudo, é **fundamental** observamos a declaração dos dados do programa. Pois é através desses dados que conseguiremos chegar ao valor final.

Com isso mente, vamos prosseguir:

```bash
 int INDICE = 13, SOMA = 0, K = 0;
```
Aqui observamos que foram declarados três variáveis do tipo inteiro e apenas **indice** tem um valor acima de zero. 

Indo adiante no código, podemos observar que um **laço de repetição** foi estabelecido. 

```bash
 Enquanto K < INDICE faça { ... }
```
Este diz que irá continuar suas operações **enquanto** o valor armazenado em K for **menor** que o valor armazenado em **indice**.

Dentro deste laço temos as seguintes operações:

```bash
 K = K + 1
 SOMA = SOMA + K
```
Essas operações indicam que **a cada ciclo** (iteração) do laço, o valor de **K** será **incrementado** em **1** e logo em seguida **SOMA** irá receber o seu **valor atual** somado ao **valor atual de K**.

Assim, em uma tabela, temos:

```bash
    ----------------------------------
    | Ciclo | K |     Soma           |
    ----------------------------------
    |   1   | 1 |   1 (0 + 1)        |
    ----------------------------------
    |   2   | 2 |   3 (1 + 2)        |
    ----------------------------------
    |   3   | 3 |   6 (3 + 3)        |
    ----------------------------------
    |  ...  |...|      ...           | 
    ----------------------------------
    |  12  | 12 |   78 (66 + 12)     |
    ----------------------------------
    |  13  | 13 |   91 (78 + 13)     |
    ----------------------------------
```
Desta maneira, ao final de treze ciclos, concluímos que o **valor final de SOMA é igual a 91**
