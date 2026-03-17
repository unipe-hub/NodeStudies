# Revisão Antes de Estrutura de Dados I

Antes de estudar listas, pilhas, filas e árvores, precisamos estar confortáveis com três bases: lógica de programação, ponteiros e memória. Estrutura de dados não é só "guardar valores"; é decidir como organizar dados na memória e como acessá-los com eficiência.

## 1. Lógica de Programação

Lógica de programação é a capacidade de descrever uma solução passo a passo, de forma precisa e executável. Antes de pensar em código, precisamos entender o problema, os dados de entrada, o processamento e a saída esperada.

### O que precisamos dominar

- Sequência de instruções.
- Tomada de decisão com `if`, `else` e `switch`.
- Repetição com `for`, `while` e `do while`.
- Funções para dividir o problema em partes menores.
- Variáveis, tipos básicos e operadores.
- Leitura e escrita de dados.
- Raciocínio algorítmico: identificar entradas, regras e resultados.

### Exemplo simples

```c
int soma(int a, int b) {
    return a + b;
}
```

Esse exemplo já mostra uma ideia central: um algoritmo recebe dados, processa e devolve um resultado.

### O que revisar bem

- Diferença entre atribuição (`=`) e comparação (`==`).
- Condições compostas com `&&`, `||` e `!`.
- Laços infinitos e como evitá-los.
- Passagem de parâmetros para funções.
- Escopo de variáveis: onde uma variável existe e pode ser usada.

## 2. Ponteiros

Ponteiros são variáveis que armazenam endereços de memória. Eles são fundamentais em Estrutura de Dados porque muitas estruturas dinâmicas dependem de ligar um elemento ao outro por meio de endereços.

Sem ponteiros, fica difícil entender listas encadeadas, árvores e alocação dinâmica.

### Ideias que precisam estar claras

- Uma variável comum guarda um valor.
- Um ponteiro guarda o endereço onde um valor está armazenado.
- O operador `&` pega o endereço de uma variável.
- O operador `*` acessa o valor apontado por um ponteiro.

### Exemplo

```c
int x = 10;
int *p = &x;
```

Aqui:

- `x` guarda o valor `10`.
- `&x` é o endereço de `x`.
- `p` guarda esse endereço.
- `*p` acessa o valor armazenado naquele endereço, ou seja, `10`.

### Exemplo de alteração indireta

```c
int x = 10;
int *p = &x;
*p = 20;
```

Depois disso, `x` passa a valer `20`, porque alteramos o conteúdo do endereço apontado por `p`.

### O que revisar bem

- Declaração de ponteiros.
- Diferença entre `p`, `*p` e `&p`.
- Ponteiro nulo: `NULL`.
- Passagem por referência com ponteiros.
- Vetores e sua relação com endereços.

## 3. Memória

Estrutura de dados depende diretamente da forma como a memória é usada. Quando estudamos desempenho, inserção, remoção e acesso, estamos estudando também como os dados ocupam espaço na memória.

### Conceitos básicos

- Memória é o espaço onde variáveis e estruturas ficam armazenadas.
- Cada dado ocupa uma região com endereço.
- Tipos diferentes ocupam quantidades diferentes de bytes.
- O programa acessa os dados por referência direta ou por endereços.

### Regiões importantes da memória

#### Stack

A `stack` é a memória usada automaticamente pelo programa para controlar chamadas de função e armazenar variáveis locais. Sempre que uma função é chamada, uma nova área é empilhada; quando a função termina, essa área é removida.

Exemplo:

```c
void teste() {
    int x = 5;
}
```

`x` normalmente fica na `stack`, porque é uma variável local da função.

Características da `stack`:

- gerenciamento automático;
- acesso rápido;
- usada para variáveis locais e parâmetros de função;
- possui tamanho limitado;
- os dados deixam de existir quando a função termina.

Isso significa que não podemos retornar o endereço de uma variável local esperando que ela continue válida depois do fim da função.

#### Heap

A `heap` é a região usada para alocação dinâmica de memória. Ela é essencial quando o tamanho da estrutura não é conhecido em tempo de compilação, ou quando os dados precisam continuar existindo mesmo após o fim de uma função.

Exemplo:

```c
int *p = malloc(sizeof(int));
*p = 10;
free(p);
```

Aqui, o valor foi criado dinamicamente na `heap`. Isso será muito importante ao estudar listas encadeadas e árvores, porque os nós dessas estruturas normalmente são criados em tempo de execução.

Características da `heap`:

- gerenciamento manual na linguagem C;
- mais flexível que a `stack`;
- usada para estruturas dinâmicas;
- exige cuidado com `malloc` e `free`;
- pode causar vazamento ou acesso inválido se for mal utilizada.

## Diferença prática entre Stack e Heap

Resumo direto:

- `stack`: memória automática, rápida e temporária;
- `heap`: memória dinâmica, flexível e controlada manualmente.

### Analogia simples

Podemos pensar assim:

- a `stack` funciona como uma pilha de pratos: o último prato colocado é o primeiro a sair;
- a `heap` funciona como um depósito: você pode guardar caixas em posições variadas, mas precisa controlar manualmente o que foi guardado e quando retirar.

Na `stack`, o programa organiza quase tudo sozinho.
Na `heap`, o programa dá mais liberdade, mas também mais responsabilidade.

Exemplo conceitual:

- uma variável local como `int x = 5;` normalmente vai para a `stack`;
- um nó criado com `malloc` para uma lista encadeada vai para a `heap`.

Na disciplina, quase toda estrutura dinâmica importante usa `heap`, porque precisamos criar e remover elementos ao longo da execução.

### Diagrama em ASCII

```text
MEMORIA DO PROGRAMA

+-----------------------------+
| Stack                       |
|-----------------------------|
| funcao C                    |
| variavel local z            |
|-----------------------------|
| funcao B                    |
| variavel local y            |
|-----------------------------|
| funcao A                    |
| variavel local x            |
+-----------------------------+

+-----------------------------+
| Heap                        |
|-----------------------------|
| bloco alocado com malloc    |
| bloco alocado para um no    |
| outro bloco dinamico        |
+-----------------------------+
```

Leitura do diagrama:

- a `stack` cresce e diminui conforme funções são chamadas e encerradas;
- a `heap` armazena blocos criados dinamicamente durante a execução;
- estruturas como listas encadeadas e árvores normalmente criam seus nós na `heap`.

## Problemas comuns com Heap e Stack

### Erro com stack

Retornar endereço de variável local:

```c
int *erro() {
    int x = 10;
    return &x;
}
```

Esse código é incorreto porque `x` deixa de existir quando a função termina.

### Erro com heap

Esquecer de liberar memória:

```c
int *p = malloc(sizeof(int));
*p = 10;
```

Se `free(p);` não for chamado quando a memória não for mais necessária, ocorre vazamento de memória.

### O que revisar bem

- Diferença entre stack e heap.
- `malloc`, `calloc`, `realloc` e `free`.
- Vazamento de memória quando se aloca e não libera.
- Acesso inválido a memória.
- Ponteiro pendente: quando o endereço não é mais válido.

## 4. Relação Entre Esses Assuntos e Estrutura de Dados

Esses três temas se conectam diretamente:

- Lógica de programação ajuda a construir os algoritmos de inserção, remoção, busca e percurso.
- Ponteiros permitem ligar nós, navegar entre elementos e modificar estruturas dinamicamente.
- Memória explica onde os dados ficam, como são criados e por que certas operações custam mais que outras.

Quando começarmos listas encadeadas, por exemplo, vamos usar:

- lógica para definir o passo a passo;
- ponteiros para ligar os nós;
- memória dinâmica para criar os nós em tempo de execução.

## 5. Erros Comuns que Precisamos Evitar

- Confundir valor com endereço.
- Usar ponteiro sem inicialização.
- Acessar memória já liberada.
- Esquecer de liberar memória alocada dinamicamente.
- Criar algoritmos sem pensar nos casos de borda, como lista vazia ou posição inválida.
- Fazer laços sem condição correta de parada.

## 6. O Mínimo que Você Deve Saber Antes de Avançar

Antes de entrar no conteúdo principal da disciplina, o ideal é conseguir:

- escrever funções simples;
- usar condicionais e laços com segurança;
- entender vetores e manipulação de índices;
- declarar e usar ponteiros;
- explicar a diferença entre stack e heap;
- alocar e liberar memória em exemplos simples;
- ler um algoritmo e prever seu comportamento.

## Fechamento

Estrutura de Dados I não começa de verdade nas listas ou nas árvores. Ela começa na capacidade de pensar algoritmicamente e entender como os dados existem na memória. Se a base de lógica, ponteiros e memória estiver sólida, o restante da disciplina fica muito mais claro.
