# Listas Sequenciais

Listas sequenciais sao estruturas lineares em que os elementos ficam armazenados em posicoes contiguas de memoria. Na pratica, a implementacao mais comum em `C` usa um vetor e uma variavel para controlar a quantidade de elementos atualmente armazenados.

Essa estrutura e uma das portas de entrada para Estrutura de Dados porque mostra bem a diferenca entre:

- capacidade total da estrutura;
- quantidade de elementos em uso;
- custo de acessar, inserir e remover dados.

## 1. O que e uma Lista Sequencial

Uma lista sequencial e uma colecao de elementos organizada em sequencia, normalmente indexada por posicao.

Exemplo conceitual:

```text
Indice:    0   1   2   3   4
Valores:  10  20  30  40  50
```

Os elementos ficam lado a lado na memoria, o que facilita o acesso direto por indice.

## 2. Ideia Central

Em uma lista sequencial, temos geralmente:

- um vetor para armazenar os dados;
- uma capacidade maxima;
- um contador de elementos validos.

Isso significa que o vetor pode ter espacos livres, mesmo quando a lista ja possui alguns elementos.

Exemplo:

```text
Capacidade total: 8
Quantidade atual: 5

Indices:    0   1   2   3   4   5   6   7
Valores:   10  20  30  40  50   -   -   -
```

Os tres ultimos espacos ainda nao fazem parte da lista em uso.

## 3. Quando usar

Listas sequenciais sao boas quando:

- precisamos de acesso rapido por indice;
- a quantidade maxima de elementos e conhecida ou previsivel;
- insercoes e remocoes acontecem mais no final da estrutura;
- queremos uma implementacao simples e eficiente em memoria contigua.

Elas nao sao tao boas quando:

- ha muitas insercoes no inicio ou no meio;
- o tamanho cresce e diminui com frequencia;
- precisamos evitar deslocamento de elementos.

## 4. Estrutura Basica em C

Uma forma didatica de representar uma lista sequencial e esta:

```c
#define MAX 100

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;
```

Aqui:

- `dados` guarda os elementos da lista;
- `tamanho` informa quantas posicoes estao realmente ocupadas.

## 5. Criacao da Lista

Uma lista vazia comeca com `tamanho = 0`.

```c
void inicializar(Lista *lista) {
    lista->tamanho = 0;
}
```

### Explicacao

- a lista ainda nao tem elementos;
- o vetor ja existe, mas nenhuma posicao esta em uso;
- `tamanho` sera atualizado a cada insercao ou remocao.

## 6. Insercao no Final

Inserir no final e uma das operacoes mais simples nessa estrutura.

```c
int inserir_final(Lista *lista, int valor) {
    if (lista->tamanho == MAX) {
        return 0;
    }

    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}
```

### Explicacao

- primeiro verificamos se ainda existe espaco;
- o novo valor e colocado na proxima posicao livre;
- depois incrementamos `tamanho`.

Se a lista estiver cheia, a insercao falha.

## 7. Insercao em uma Posicao

Quando inserimos no meio, precisamos abrir espaco deslocando elementos para a direita.

```c
int inserir_posicao(Lista *lista, int valor, int posicao) {
    int i;

    if (lista->tamanho == MAX) {
        return 0;
    }

    if (posicao < 0 || posicao > lista->tamanho) {
        return 0;
    }

    for (i = lista->tamanho; i > posicao; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return 1;
}
```

### Explicacao

- validamos se a posicao existe;
- deslocamos os elementos a partir do fim em direcao a direita;
- gravamos o novo valor na posicao desejada;
- atualizamos o tamanho.

## 8. Remocao de uma Posicao

Ao remover, o espaco vazio precisa ser fechado.

```c
int remover_posicao(Lista *lista, int posicao) {
    int i;

    if (posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }

    for (i = posicao; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->tamanho--;
    return 1;
}
```

### Explicacao

- validamos se a posicao contem um elemento valido;
- deslocamos os elementos seguintes para a esquerda;
- reduzimos `tamanho`;
- o ultimo valor antigo passa a ser irrelevante, porque ficou fora da area em uso.

## 9. Busca

Existem duas ideias importantes de busca em listas sequenciais.

### Acesso direto por indice

```c
int obter_elemento(Lista *lista, int posicao, int *valor) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }

    *valor = lista->dados[posicao];
    return 1;
}
```

Esse acesso e rapido porque basta ir direto ao indice.

### Busca por valor

```c
int buscar_valor(Lista *lista, int valor) {
    int i;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            return i;
        }
    }

    return -1;
}
```

Nesse caso, percorremos a lista ate encontrar o valor.

## 10. Percurso

Percorrer uma lista significa visitar seus elementos em ordem.

```c
void imprimir(Lista *lista) {
    int i;

    for (i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}
```

Essa operacao aparece o tempo inteiro em testes, depuracao e exibicao de resultados.

## 11. Vantagens

- acesso direto por indice;
- implementacao simples;
- bom aproveitamento de cache por causa da memoria contigua;
- insercao no final pode ser bem eficiente;
- estrutura facil de entender e testar.

## 12. Desvantagens

- tamanho maximo fixo na versao estatica;
- insercoes no inicio ou no meio exigem deslocamento;
- remocoes no inicio ou no meio tambem exigem deslocamento;
- pode haver desperdicio de espaco se a capacidade for grande e pouco usada.

## 13. Complexidade

| Operacao | Custo |
|---|---|
| Acesso por indice | O(1) |
| Insercao no final | O(1) |
| Insercao no inicio ou meio | O(n) |
| Remocao no inicio ou meio | O(n) |
| Busca por valor | O(n) |
| Percurso completo | O(n) |

Observacao importante:

- a insercao no final e `O(1)` quando ainda existe espaco e nao ha necessidade de realocacao;
- em listas sequenciais dinamicas, o custo pode variar se a memoria precisar ser expandida.

## 14. Erros Comuns

- confundir `tamanho` com capacidade maxima;
- inserir sem verificar se a lista esta cheia;
- remover sem validar a posicao;
- percorrer o vetor inteiro em vez de percorrer apenas ate `tamanho`;
- esquecer que insercao e remocao podem deslocar elementos.

## 15. Comparacao com Lista Encadeada

Comparacao direta:

- lista sequencial usa memoria contigua;
- lista encadeada usa nos ligados por ponteiros;
- lista sequencial acessa indice rapidamente;
- lista encadeada facilita insercoes e remocoes sem deslocamento fisico dos elementos.

Por isso, listas sequenciais sao boas para acesso por posicao, enquanto listas encadeadas costumam ser melhores quando ha muitas alteracoes estruturais.

## 16. O que voce deve guardar

Ao estudar listas sequenciais, o essencial e entender:

- a lista ocupa um vetor;
- `tamanho` define quantos elementos sao validos;
- inserir e remover no meio custa mais por causa do deslocamento;
- acessar um indice e rapido;
- essa estrutura serve de base para varias outras implementacoes.

## 17. Proximo Passo

Depois de dominar listas sequenciais, faz sentido avancar para:

- listas encadeadas;
- pilhas;
- filas;
- deques.

Nesses proximos assuntos, a principal mudanca sera a forma de organizacao dos dados e o custo das operacoes.
