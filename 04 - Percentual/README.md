# Código 04 - Percentual
Dado o valor de faturamento mensal de uma distribuidora, detalhado por estado:

```bash
• SP – R$67.836,43
• RJ – R$36.678,66
• MG – R$29.229,88
• ES – R$27.165,48
• Outros – R$19.849,53
```

Escreva um programa na linguagem que desejar onde calcule o percentual de representação que cada estado teve dentro do valor total mensal da distribuidora.  

## Estrutura do diretório

```bash
04 - Percentual
├── json
│   └── estados.json
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

Biblioteca 02 - percentual:

```bash
 gcc -c ./lib/percentual.c -o percentual.o
````
**Passo 3 - Compilar a solução e gerar um executável**

```bash
 gcc -o main main.c percentual.o cJSON.o
````

**Testar o executável da solução**

Ainda no prompt, temos duas opções:

1 - Execução via linha de comando

Execute:

```bash
 .\main.exe
````

2 - Abrir o executável manualmente no diretório da solução.
