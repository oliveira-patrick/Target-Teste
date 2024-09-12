# Código 03 - Faturamento

Dado um vetor que guarda o valor de faturamento diário de uma distribuidora, faça um programa, na linguagem que desejar, que calcule e retorne:
```bash
• O menor valor de faturamento ocorrido em um dia do mês;
• O maior valor de faturamento ocorrido em um dia do mês;
• Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.
```
IMPORTANTE:
```bash
a) Usar o json ou xml disponível como fonte dos dados do faturamento mensal;
b) Podem existir dias sem faturamento, como nos finais de semana e feriados. Estes dias devem ser ignorados no cálculo da média;
```

## Estrutura do diretório

```bash
03 - Faturamento
├── json
│   ├── dados.json
│   └── data.json
├── lib
│   ├── cJSON.c
│   ├── cJSON.h
│   ├── faturamento.c
│   └── faturamento.h
├── README.md
└── main.c
````


## Uso/Exemplos

**Passo 1 - Acessar o diretório**

Use o prompt de comandos e rode o seguinte comando:

```bash
    cd [caminho da pasta]
````

**Passo 2 - Compilar as bibliotecas**

Compile as bibliotecas contendo as funções necessárias para a execução da solução:

Biblioteca 01 - cJSON:

```bash
    gcc -c ./lib/cJSON.c -o cJSON.o
````

Biblioteca 02 - faturamento:

```bash
   gcc -c ./lib/faturamento.c -o faturamento.o
````
**Passo 3 - Compilar a solução e gerar um executável**

```bash
    gcc -o main main.c faturamento.o cJSON.o
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

Aqui você é capaz de fornecer o arquivo a ser testado diretamente na linha de comando, junto da execução do programa.

```bash
    .\main.exe [caminho do arquivo]
````

3 - Abrir o executável manualmente no diretório da solução.
