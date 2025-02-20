#ifndef DOMINO_H
#define DOMINO_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma peça do dominó
typedef struct Peca {
    int lado1, lado2;
} Peca;

// Nó da lista encadeada que armazena uma peça do dominó
typedef struct No {
    Peca peca;
    struct No *prox;
} No;

// Estrutura principal do dominó, representada como uma lista encadeada
typedef struct Domino {
    No *inicio;
    int tamanho;
} Domino;

// Cria um novo conjunto de peças de dominó
Domino* DominoCria(void);

// Libera a memória alocada para o conjunto de peças de dominó
void DominoDestroi(Domino *d);

// Adiciona uma peça ao conjunto de dominó
int DominoAdicionaPeca(Domino *d, int l1, int l2);

// Imprime as peças do conjunto de dominó no formato esperado
void DominoImprime(const Domino *d);

// Verifica se as peças podem ser organizadas em uma sequência válida
int DominoEhPossivelOrganizar(Domino *d, Peca *sequencia);

#endif // DOMINO_H
