# Código 02 - Fibonacci

Dado a sequência de Fibonacci, onde se inicia por 0 e 1 e o próximo valor sempre será a soma dos 2 valores anteriores (exemplo: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...), escreva um programa na linguagem que desejar onde, informado um número, ele calcule a sequência de Fibonacci e retorne uma mensagem avisando se o número informado pertence ou não a sequência.


## Estrutura do diretório


```bash
02 - Fibonacci
├── lib
│   ├── fibo.c
│   └── fibo.h
├── README.md
└── main.c
````

## Uso/Exemplos

**Passo 1 - Acessar o diretório**

Use o prompt de comandos e rode o seguinte comando:

```bash
 cd [caminho da pasta]
````

**Passo 2 - Compilar a biblioteca**

Compile a biblioteca contendo as funções necessárias para a execução da solução:

```bash
 gcc -c ./lib/fibo.c -o fibo.o
````

**Passo 3 - Compilar a solução e gerar um executável**

```bash
 gcc -o main main.c fibo.o
````
**Testar o executável da solução**

Ainda no prompt, temos três opções:

1 - Execução interativa

Execute:

```bash
 .\main.exe
````
Após isso basta seguir as instruções exibidas na tela e fornecer os dados através do teclado.

2 - Execução via linha

Aqui você é capaz de fornecer o valor diretamente na linha de comando, junto da execução do programa.

```bash
 .\main.exe [valor da sua preferência]
````

3 - Abrir o executável manualmente no diretório da solução.
