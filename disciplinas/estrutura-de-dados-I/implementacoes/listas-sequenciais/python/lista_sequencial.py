class Lista:
    def __init__(self):
        self.dados = []

    def inserir_posicao(self, valor, posicao):
        if posicao < 0 or posicao > len(self.dados):
            raise IndexError("posicao invalida")

        self.dados.insert(posicao, valor)

    def remover_posicao(self, posicao):
        if posicao < 0 or posicao >= len(self.dados):
            raise IndexError("posicao invalida")

        return self.dados.pop(posicao)

    def buscar_valor(self, valor):
        for i, atual in enumerate(self.dados):
            if atual == valor:
                return i

        return -1

    def __repr__(self):
        return str(self.dados)


def main():
    lista = Lista()

    lista.inserir_posicao(10, 0)
    lista.inserir_posicao(20, 1)
    lista.inserir_posicao(40, 2)
    print("Lista inicial:", lista)

    lista.inserir_posicao(30, 2)
    print("Apos inserir 30 na posicao 2:", lista)

    removido = lista.remover_posicao(1)
    print(f"Valor removido da posicao 1: {removido}")
    print("Lista apos remocao:", lista)

    posicao = lista.buscar_valor(30)
    print(f"Valor 30 encontrado na posicao: {posicao}")


if __name__ == "__main__":
    main()
