// Disciplina: Estrutura de Dados I
// Assunto: Listas Encadeadas
// Descricao: Implementacao de lista encadeada simples em Java com operacoes basicas

public class ListaEncadeada {
    private No inicio;
    private int tamanho;

    public ListaEncadeada() {
        this.inicio = null;
        this.tamanho = 0;
    }

    private static class No {
        int valor;
        No proximo;

        No(int valor) {
            this.valor = valor;
            this.proximo = null;
        }
    }

    public void inserirPosicao(int valor, int posicao) throws IndexOutOfBoundsException {
        if (posicao < 0 || posicao > tamanho) {
            throw new IndexOutOfBoundsException("Posicao invalida");
        }

        No novoNo = new No(valor);

        if (posicao == 0) {
            novoNo.proximo = inicio;
            inicio = novoNo;
            tamanho++;
            return;
        }

        No anterior = noNaPosicao(posicao - 1);
        novoNo.proximo = anterior.proximo;
        anterior.proximo = novoNo;
        tamanho++;
    }

    public int removerPosicao(int posicao) throws IndexOutOfBoundsException {
        if (posicao < 0 || posicao >= tamanho) {
            throw new IndexOutOfBoundsException("Posicao invalida");
        }

        if (posicao == 0) {
            int valorRemovido = inicio.valor;
            inicio = inicio.proximo;
            tamanho--;
            return valorRemovido;
        }

        No anterior = noNaPosicao(posicao - 1);
        No removido = anterior.proximo;
        anterior.proximo = removido.proximo;
        tamanho--;
        return removido.valor;
    }

    public int buscarValor(int valor) {
        No atual = inicio;
        int posicao = 0;

        while (atual != null) {
            if (atual.valor == valor) {
                return posicao;
            }
            atual = atual.proximo;
            posicao++;
        }

        return -1;
    }

    private No noNaPosicao(int posicao) {
        No atual = inicio;
        for (int i = 0; i < posicao; i++) {
            atual = atual.proximo;
        }
        return atual;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");

        No atual = inicio;
        while (atual != null) {
            sb.append(atual.valor);
            if (atual.proximo != null) {
                sb.append(" -> ");
            }
            atual = atual.proximo;
        }

        sb.append("]");
        return sb.toString();
    }

    public void liberar() {
        inicio = null;
        tamanho = 0;
    }

    public int getTamanho() {
        return tamanho;
    }

    public static void main(String[] args) {
        ListaEncadeada lista = new ListaEncadeada();

        try {
            lista.inserirPosicao(10, 0);
            lista.inserirPosicao(20, 1);
            lista.inserirPosicao(40, 2);
            System.out.println("Lista inicial: " + lista);

            lista.inserirPosicao(30, 2);
            System.out.println("Apos inserir 30 na posicao 2: " + lista);

            int removido = lista.removerPosicao(1);
            System.out.println("Valor removido da posicao 1: " + removido);
            System.out.println("Lista apos remocao: " + lista);

            int posicao = lista.buscarValor(30);
            System.out.println("Valor 30 encontrado na posicao: " + posicao);

        } catch (IndexOutOfBoundsException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}