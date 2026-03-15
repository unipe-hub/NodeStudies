# Implementacoes de Listas Sequenciais

Esta pasta reune implementacoes praticas de listas sequenciais em diferentes linguagens.

## Ordem recomendada

1. Leia o resumo teorico em [../../resumos/listas-sequenciais.md](../../resumos/listas-sequenciais.md).
2. Estude primeiro a implementacao em `C`, que serve como referencia principal.
3. Depois adicione outras linguagens mantendo a mesma ideia de operacoes e nomenclatura.

## Arquivos

| Caminho | Descricao |
|---|---|
| [c/lista_sequencial_estatica.c](./c/lista_sequencial_estatica.c) | Implementacao base em C usando vetor de tamanho fixo e operacoes fundamentais. |

## Operacoes presentes na versao em C

- inicializacao da lista;
- insercao no final;
- insercao em posicao especifica;
- remocao por posicao;
- busca por valor;
- obtencao de elemento por indice;
- impressao da lista.

## Observacoes

- Esta primeira versao usa alocacao estatica com `#define MAX`.
- Uma evolucao natural depois dela e criar a versao com realocacao dinamica.
- As implementacoes em outras linguagens devem preservar a mesma ideia antes de introduzir recursos especificos da linguagem.
