# Disciplina: Estrutura de Dados I
# Assunto: Listas Encadeadas
# Descricao: Implementacao de lista encadeada simples em Python com operacoes basicas

class ListaEncadeada:
    class No:
        def __init__(self, valor):
            self.valor = valor
            self.proximo = None

    def __init__(self):
        self.inicio = None
        self.tamanho = 0

    def inserir_posicao(self, valor, posicao):
        if posicao < 0 or posicao > self.tamanho:
            raise IndexError("Posicao invalida")

        novo_no = self.No(valor)

        if posicao == 0:
            novo_no.proximo = self.inicio
            self.inicio = novo_no
            self.tamanho += 1
            return

        anterior = self.no_na_posicao(posicao - 1)
        novo_no.proximo = anterior.proximo
        anterior.proximo = novo_no
        self.tamanho += 1

    def remover_posicao(self, posicao):
        if posicao < 0 or posicao >= self.tamanho:
            raise IndexError("Posicao invalida")

        if posicao == 0:
            valor_removido = self.inicio.valor
            self.inicio = self.inicio.proximo
            self.tamanho -= 1
            return valor_removido

        anterior = self.no_na_posicao(posicao - 1)
        removido = anterior.proximo
        anterior.proximo = removido.proximo
        self.tamanho -= 1
        return removido.valor

    def buscar_valor(self, valor):
        atual = self.inicio
        posicao = 0

        while atual is not None:
            if atual.valor == valor:
                return posicao
            atual = atual.proximo
            posicao += 1

        return -1

    def no_na_posicao(self, posicao):
        atual = self.inicio
        for _ in range(posicao):
            atual = atual.proximo
        return atual

    def __str__(self):
        valores = []
        atual = self.inicio

        while atual is not None:
            valores.append(str(atual.valor))
            atual = atual.proximo

        return "[" + " -> ".join(valores) + "]"

    def liberar(self):
        self.inicio = None
        self.tamanho = 0

    def get_tamanho(self):
        return self.tamanho

    @staticmethod
    def main():
        lista = ListaEncadeada()

        try:
            lista.inserir_posicao(10, 0)
            lista.inserir_posicao(20, 1)
            lista.inserir_posicao(40, 2)
            print("Lista inicial:", lista)

            lista.inserir_posicao(30, 2)
            print("Apos inserir 30 na posicao 2:", lista)

            removido = lista.remover_posicao(1)
            print("Valor removido da posicao 1:", removido)
            print("Lista apos remocao:", lista)

            posicao = lista.buscar_valor(30)
            print("Valor 30 encontrado na posicao:", posicao)

        except IndexError as e:
            print("Erro:", e)

if __name__ == "__main__":
    ListaEncadeada.main()