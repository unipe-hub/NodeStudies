# Implementacoes de Listas Encadeadas

Esta pasta reune implementacoes praticas de listas encadeadas em diferentes linguagens.

## Ordem recomendada

1. Leia primeiro a implementacao em `C`, que serve como referencia principal da disciplina.
2. Observe como cada no guarda o valor e o ponteiro para o proximo elemento.
3. Depois compare com outras linguagens mantendo a mesma ideia de operacoes e nomenclatura.

## Arquivos

| Caminho | Descricao |
|---|---|
| [c/lista_encadeada_simples.c](./c/lista_encadeada_simples.c) | Versao enxuta em C com criacao da lista, insercao, remocao, busca e liberacao de memoria. |
| [go/lista_encadeada.go](./go/lista_encadeada.go) | Versao complementar em Go com a mesma ideia de operacoes. |
| [java/ListaEncadeada.java](./java/ListaEncadeada.java) | Versao em Java com tratamento de excecoes e orientacao a objetos. |
| [python/lista_encadeada.py](./python/lista_encadeada.py) | Versao em Python com sintaxe simples e legibilidade. |

## Ideia central

- Diferente da lista sequencial, os elementos nao ficam armazenados lado a lado na memoria.
- Cada no guarda um valor e a referencia para o proximo no da lista.
- Insercoes e remocoes no inicio ou no meio nao exigem deslocamento de todos os elementos.

## Observacoes

- A implementacao principal desta pasta e a versao simplesmente encadeada em `C`.
- A busca por posicao continua linear, porque e preciso percorrer a lista no a no.
- Uma evolucao natural depois dela e implementar a versao duplamente encadeada.
- As versoes em Java e Python seguem a mesma logica, com adaptacoes para cada linguagem.
