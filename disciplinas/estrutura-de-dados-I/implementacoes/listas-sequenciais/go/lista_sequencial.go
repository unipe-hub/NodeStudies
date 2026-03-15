package main

import (
	"errors"
	"fmt"
)

type Lista struct {
	dados []int
}

func NovaLista(capacidade int) *Lista {
	return &Lista{
		dados: make([]int, 0, capacidade),
	}
}

func (l *Lista) InserirPosicao(valor int, posicao int) error {
	if posicao < 0 || posicao > len(l.dados) {
		return errors.New("posicao invalida")
	}

	l.dados = append(l.dados, 0)
	copy(l.dados[posicao+1:], l.dados[posicao:])
	l.dados[posicao] = valor

	return nil
}

func (l *Lista) RemoverPosicao(posicao int) (int, error) {
	if posicao < 0 || posicao >= len(l.dados) {
		return 0, errors.New("posicao invalida")
	}

	valorRemovido := l.dados[posicao]
	copy(l.dados[posicao:], l.dados[posicao+1:])
	l.dados = l.dados[:len(l.dados)-1]

	return valorRemovido, nil
}

func (l *Lista) BuscarValor(valor int) int {
	for i, atual := range l.dados {
		if atual == valor {
			return i
		}
	}

	return -1
}

func (l *Lista) String() string {
	return fmt.Sprintf("%v", l.dados)
}

func main() {
	lista := NovaLista(5)

	if err := lista.InserirPosicao(10, 0); err != nil {
		fmt.Println("Erro ao inserir:", err)
		return
	}
	if err := lista.InserirPosicao(20, 1); err != nil {
		fmt.Println("Erro ao inserir:", err)
		return
	}
	if err := lista.InserirPosicao(40, 2); err != nil {
		fmt.Println("Erro ao inserir:", err)
		return
	}
	fmt.Println("Lista inicial:", lista)

	if err := lista.InserirPosicao(30, 2); err != nil {
		fmt.Println("Erro ao inserir:", err)
		return
	}
	fmt.Println("Apos inserir 30 na posicao 2:", lista)

	removido, err := lista.RemoverPosicao(1)
	if err != nil {
		fmt.Println("Erro ao remover:", err)
		return
	}
	fmt.Printf("Valor removido da posicao 1: %d\n", removido)
	fmt.Println("Lista apos remocao:", lista)

	posicao := lista.BuscarValor(30)
	fmt.Printf("Valor 30 encontrado na posicao: %d\n", posicao)
}
