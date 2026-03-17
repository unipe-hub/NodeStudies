package main

import (
	"errors"
	"fmt"
	"strings"
)

type no struct {
	valor   int
	proximo *no
}

type ListaEncadeada struct {
	inicio  *no
	tamanho int
}

func NovaLista() *ListaEncadeada {
	return &ListaEncadeada{}
}

func (l *ListaEncadeada) InserirPosicao(valor int, posicao int) error {
	if posicao < 0 || posicao > l.tamanho {
		return errors.New("posicao invalida")
	}

	novoNo := &no{valor: valor}

	if posicao == 0 {
		novoNo.proximo = l.inicio
		l.inicio = novoNo
		l.tamanho++
		return nil
	}

	anterior := l.noNaPosicao(posicao - 1)
	novoNo.proximo = anterior.proximo
	anterior.proximo = novoNo
	l.tamanho++

	return nil
}

func (l *ListaEncadeada) RemoverPosicao(posicao int) (int, error) {
	if posicao < 0 || posicao >= l.tamanho {
		return 0, errors.New("posicao invalida")
	}

	if posicao == 0 {
		valorRemovido := l.inicio.valor
		l.inicio = l.inicio.proximo
		l.tamanho--
		return valorRemovido, nil
	}

	anterior := l.noNaPosicao(posicao - 1)
	removido := anterior.proximo
	anterior.proximo = removido.proximo
	l.tamanho--

	return removido.valor, nil
}

func (l *ListaEncadeada) BuscarValor(valor int) int {
	posicao := 0

	for atual := l.inicio; atual != nil; atual = atual.proximo {
		if atual.valor == valor {
			return posicao
		}
		posicao++
	}

	return -1
}

func (l *ListaEncadeada) noNaPosicao(posicao int) *no {
	atual := l.inicio

	for i := 0; i < posicao; i++ {
		atual = atual.proximo
	}

	return atual
}

func (l *ListaEncadeada) String() string {
	if l.inicio == nil {
		return "[]"
	}

	var valores []string

	for atual := l.inicio; atual != nil; atual = atual.proximo {
		valores = append(valores, fmt.Sprintf("%d", atual.valor))
	}

	return "[" + strings.Join(valores, " -> ") + "]"
}

func main() {
	lista := NovaLista()

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
