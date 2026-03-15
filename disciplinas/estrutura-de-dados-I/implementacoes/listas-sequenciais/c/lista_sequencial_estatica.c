#include <stdio.h>

#define MAX 10

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

void inicializar(Lista *lista) {
    lista->tamanho = 0;
}

int inserir_posicao(Lista *lista, int valor, int posicao) {
    int i;

    if (lista->tamanho == MAX) {
        return 0;
    }

    if (posicao < 0 || posicao > lista->tamanho) {
        return 0;
    }

    /* Desloca para a direita para abrir espaco para o novo elemento. */
    for (i = lista->tamanho; i > posicao; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return 1;
}

int remover_posicao(Lista *lista, int posicao) {
    int i;

    if (posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }

    /* Fecha o espaco vazio deslocando os elementos para a esquerda. */
    for (i = posicao; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->tamanho--;
    return 1;
}

int buscar_valor(const Lista *lista, int valor) {
    int i;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            return i;
        }
    }

    return -1;
}

void imprimir_lista(const Lista *lista) {
    int i;

    printf("[");

    for (i = 0; i < lista->tamanho; i++) {
        printf("%d", lista->dados[i]);

        if (i < lista->tamanho - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(void) {
    Lista lista;
    int posicao;

    inicializar(&lista);

    inserir_posicao(&lista, 10, 0);
    inserir_posicao(&lista, 20, 1);
    inserir_posicao(&lista, 40, 2);
    imprimir_lista(&lista);

    inserir_posicao(&lista, 30, 2);
    imprimir_lista(&lista);

    remover_posicao(&lista, 1);
    imprimir_lista(&lista);

    posicao = buscar_valor(&lista, 30);
    printf("Valor 30 encontrado na posicao: %d\n", posicao);

    return 0;
}
