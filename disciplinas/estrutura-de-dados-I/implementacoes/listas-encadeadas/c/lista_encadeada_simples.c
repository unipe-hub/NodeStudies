#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

No *no_na_posicao(const Lista *lista, int posicao) {
    No *atual;
    int i;

    atual = lista->inicio;

    for (i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    return atual;
}

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

int main(void) {
    Lista lista;
    int removido;
    int posicao;

    inicializar(&lista);

    inserir_posicao(&lista, 10, 0);
    inserir_posicao(&lista, 20, 1);
    inserir_posicao(&lista, 40, 2);
    imprimir_lista(&lista);

    inserir_posicao(&lista, 30, 2);
    imprimir_lista(&lista);

    remover_posicao(&lista, 1, &removido);
    printf("Valor removido da posicao 1: %d\n", removido);
    imprimir_lista(&lista);

    posicao = buscar_valor(&lista, 30);
    printf("Valor 30 encontrado na posicao: %d\n", posicao);

    liberar_lista(&lista);

    return 0;
}
