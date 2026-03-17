# Listas Encadeadas

Listas encadeadas sao estruturas lineares formadas por nos. Cada no guarda um valor e uma referencia para o proximo elemento da sequencia. Diferente das listas sequenciais, os elementos nao precisam ficar em posicoes contiguas de memoria.

Essa estrutura e importante porque mostra bem a ideia de ligacao entre elementos e ajuda a entender melhor:

- uso de ponteiros;
- alocacao dinamica de memoria;
- insercoes e remocoes sem deslocamento de varios elementos;
- diferenca entre acesso sequencial e acesso direto.

## 1. O que e uma Lista Encadeada

Uma lista encadeada e uma colecao de elementos em que cada item aponta para o proximo.

Exemplo conceitual:

```text
[10 | *] -> [20 | *] -> [30 | *] -> NULL
```

Cada bloco representa um no:

- a primeira parte guarda o valor;
- a segunda parte guarda o endereco do proximo no;
- `NULL` indica o fim da lista.

## 2. Ideia Central

Em uma lista encadeada simples, temos normalmente:

- um ponteiro para o primeiro no;
- um contador de elementos;
- nos criados dinamicamente conforme a necessidade.

Exemplo:

```text
inicio
  |
  v
[10 | *] -> [20 | *] -> [30 | *] -> NULL
```

Isso significa que a lista cresce conforme novos nos sao alocados, sem depender de um vetor com tamanho fixo.

## 3. Quando usar

Listas encadeadas sao boas quando:

- ha muitas insercoes e remocoes no inicio ou no meio;
- nao queremos deslocar elementos na memoria;
- o tamanho da estrutura varia com frequencia;
- queremos alocacao dinamica conforme a necessidade.

Elas nao sao tao boas quando:

- precisamos acessar rapidamente um elemento por indice;
- queremos melhor localidade de memoria;
- a simplicidade de um vetor fixo ja resolve o problema.

## 4. Estrutura Basica em C

Uma forma didatica de representar uma lista encadeada simples e esta:

```c
typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;
```

Aqui:

- `No` representa cada elemento da lista;
- `valor` guarda o dado;
- `proximo` aponta para o no seguinte;
- `inicio` aponta para o primeiro elemento;
- `tamanho` informa quantos nos existem na lista.

## 5. Criacao da Lista

Uma lista vazia comeca sem nenhum no.

```c
void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}
```

### Explicacao

- `inicio = NULL` indica que a lista esta vazia;
- nenhum no foi alocado ainda;
- `tamanho` sera atualizado a cada insercao ou remocao.

## 6. Acesso a um No por Posicao

Como os elementos nao ficam em indices contiguos, precisamos caminhar pela lista.

```c
No *no_na_posicao(const Lista *lista, int posicao) {
    No *atual;
    int i;

    atual = lista->inicio;

    for (i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    return atual;
}
```

### Explicacao

- comecamos no primeiro no;
- avancamos de referencia em referencia;
- so chegamos ao elemento desejado depois de percorrer a lista ate aquela posicao.

## 7. Insercao em uma Posicao

Para inserir, criamos um novo no e ajustamos os ponteiros.

```c
int inserir_posicao(Lista *lista, int valor, int posicao) {
    No *novo_no;
    No *anterior;

    if (posicao < 0 || posicao > lista->tamanho) {
        return 0;
    }

    novo_no = (No *) malloc(sizeof(No));

    if (novo_no == NULL) {
        return 0;
    }

    novo_no->valor = valor;

    if (posicao == 0) {
        novo_no->proximo = lista->inicio;
        lista->inicio = novo_no;
        lista->tamanho++;
        return 1;
    }

    anterior = no_na_posicao(lista, posicao - 1);
    novo_no->proximo = anterior->proximo;
    anterior->proximo = novo_no;
    lista->tamanho++;

    return 1;
}
```

### Explicacao

- validamos se a posicao existe;
- alocamos memoria para o novo no;
- se a insercao for no inicio, o novo no passa a apontar para o antigo primeiro;
- caso contrario, localizamos o no anterior e ajustamos os encadeamentos;
- ao final, incrementamos `tamanho`.

## 8. Remocao de uma Posicao

Ao remover, precisamos religar os nos vizinhos e liberar a memoria do no excluido.

```c
int remover_posicao(Lista *lista, int posicao, int *valor_removido) {
    No *anterior;
    No *removido;

    if (posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }

    if (posicao == 0) {
        removido = lista->inicio;
        lista->inicio = removido->proximo;
        *valor_removido = removido->valor;
        free(removido);
        lista->tamanho--;
        return 1;
    }

    anterior = no_na_posicao(lista, posicao - 1);
    removido = anterior->proximo;
    anterior->proximo = removido->proximo;
    *valor_removido = removido->valor;
    free(removido);
    lista->tamanho--;

    return 1;
}
```

### Explicacao

- validamos se a posicao contem um no valido;
- se for o primeiro elemento, movemos `inicio` para o proximo no;
- nos outros casos, ajustamos o ponteiro do no anterior;
- guardamos o valor removido;
- liberamos a memoria com `free`;
- reduzimos `tamanho`.

## 9. Busca

Em listas encadeadas, a busca acontece de forma sequencial.

```c
int buscar_valor(const Lista *lista, int valor) {
    No *atual;
    int posicao;

    atual = lista->inicio;
    posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }

        atual = atual->proximo;
        posicao++;
    }

    return -1;
}
```

### Explicacao

- comecamos no primeiro no;
- percorremos a lista ate encontrar o valor;
- se chegarmos em `NULL`, significa que o elemento nao existe.

## 10. Percurso

Percorrer uma lista encadeada significa visitar os nos em ordem, do inicio ate o fim.

```c
void imprimir_lista(const Lista *lista) {
    No *atual;

    printf("[");

    atual = lista->inicio;

    while (atual != NULL) {
        printf("%d", atual->valor);

        if (atual->proximo != NULL) {
            printf(" -> ");
        }

        atual = atual->proximo;
    }

    printf("]\n");
}
```

Essa operacao aparece em testes, depuracao e visualizacao do encadeamento entre os elementos.

## 11. Liberacao de Memoria

Como os nos sao criados dinamicamente, eles precisam ser liberados ao final do uso.

```c
void liberar_lista(Lista *lista) {
    No *atual;
    No *proximo;

    atual = lista->inicio;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->tamanho = 0;
}
```

### Explicacao

- percorremos a lista inteira;
- guardamos o proximo no antes de liberar o atual;
- ao final, a lista volta ao estado vazio;
- essa etapa e essencial para evitar vazamento de memoria.

## 12. Vantagens

- tamanho dinamico;
- insercoes e remocoes sem deslocar varios elementos;
- boa estrutura para trabalhar com alocacao dinamica;
- facilita a representacao de encadeamentos.

## 13. Desvantagens

- nao ha acesso direto por indice;
- cada no precisa de memoria extra para o ponteiro;
- localidade de memoria pior do que em vetores;
- implementacao mais sensivel a erros com ponteiros;
- exige cuidado com `malloc` e `free`.

## 14. Complexidade

| Operacao | Custo |
|---|---|
| Acesso por posicao | O(n) |
| Insercao no inicio | O(1) |
| Insercao no meio | O(n) |
| Remocao no inicio | O(1) |
| Remocao no meio | O(n) |
| Busca por valor | O(n) |
| Percurso completo | O(n) |

Observacao importante:

Mesmo quando a insercao ou remocao em si e simples, o custo pode aumentar se for necessario percorrer a lista para encontrar a posicao correta.

## 15. Comparacao com Listas Sequenciais

Em resumo:

- listas sequenciais acessam rapidamente por indice, mas deslocam elementos em insercoes e remocoes internas;
- listas encadeadas evitam esses deslocamentos, mas precisam percorrer os nos para localizar posicoes;
- a escolha depende do tipo de operacao mais frequente no problema.

## 16. Conclusao

Listas encadeadas sao uma estrutura fundamental para entender ponteiros, alocacao dinamica e organizacao linear sem depender de memoria contigua. Elas aparecem como base para pilhas, filas, listas duplamente encadeadas e varias outras estruturas mais avancadas.
