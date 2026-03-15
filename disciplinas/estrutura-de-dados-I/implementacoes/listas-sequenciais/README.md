# Implementacoes de Listas Sequenciais

Esta pasta reune implementacoes praticas de listas sequenciais em diferentes linguagens.

## Ordem recomendada

1. Leia o resumo teorico em [../../resumos/listas-sequenciais.md](../../resumos/listas-sequenciais.md).
2. Estude primeiro a implementacao em `C`, que serve como referencia principal.
3. Depois adicione outras linguagens mantendo a mesma ideia de operacoes e nomenclatura.

## Arquivos

| Caminho | Descricao |
|---|---|
| [c/lista_sequencial_estatica.c](./c/lista_sequencial_estatica.c) | Versao enxuta em C com criacao da lista, insercao, remocao e busca. |
| [go/lista_sequencial.go](./go/lista_sequencial.go) | Versao enxuta em Go com `slice`, insercao, remocao e busca. |

## Operacoes presentes nas versoes atuais

- criacao da lista;
- insercao em posicao especifica;
- remocao por posicao;
- busca por valor;
- exemplo simples de uso no `main`.

## Observacao sobre Go

- Em Go, a modelagem mais natural de lista sequencial usa `slice`, nao um vetor fixo como em `C`.
- A estrutura continua sendo sequencial, porque os elementos sao tratados em ordem e acessados por indice.
- Insercoes e remocoes no meio ainda exigem deslocamento de elementos, mas a gestao de memoria e feita pela propria linguagem.

## Observacoes

- Esta primeira versao usa alocacao estatica com `#define MAX`.
- Uma evolucao natural depois dela e criar a versao com realocacao dinamica.
- As implementacoes em outras linguagens devem preservar a mesma ideia antes de introduzir recursos especificos da linguagem.
