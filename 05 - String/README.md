## Código 05 - String

Escreva um programa que inverta os caracteres de um string.

IMPORTANTE:
```bash
a) Essa string pode ser informada através de qualquer entrada de sua preferência ou pode ser previamente definida no código;
b) Evite usar funções prontas, como, por exemplo, reverse;
```



## Estrutura do diretório

```bash
05 - String
├── lib
│   ├── myStrings.c
│   └── myStrings.h
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
 gcc -c  ./lib/myStrings.c -o myStrings.o
````

**Passo 3 - Compilar a solução e gerar um executável**

```bash
 gcc -o main main.c myStrings.o
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

Aqui você é capaz de fornecer uma string diretamente na linha de comando, junto da execução do programa.

```bash
 .\main.exe [string da sua preferência]
````

3 - Abrir o executável manualmente no diretório da solução.
