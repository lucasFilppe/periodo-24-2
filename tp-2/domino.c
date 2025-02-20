#include <stdio.h>
#include <stdlib.h>
#include "domino.h"

Domino* DominoCria(void) {
    Domino *d = (Domino*)malloc(sizeof(Domino));
    if (d == NULL) return NULL;
    d->inicio = NULL;
    d->tamanho = 0;
    return d;
}

void DominoDestroi(Domino *d) {
    if (d == NULL) return;
    No *atual = d->inicio, *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(d);
}

int DominoAdicionaPeca(Domino *d, int l1, int l2) {
    if (d == NULL) return 0;
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->peca.lado1 = l1;
    novo->peca.lado2 = l2;
    novo->prox = d->inicio;
    d->inicio = novo;
    d->tamanho++;
    return 1;
}

void DominoImprime(const Domino *d) {
    if (d == NULL || d->inicio == NULL) {
        printf("Nenhuma peça para imprimir.\n");
        return;
    }

    No *atual = d->inicio;
    while (atual != NULL) {
        printf("%d%d", atual->peca.lado1, atual->peca.lado2);
        if (atual->prox != NULL) {
            printf("|");
        }
        atual = atual->prox;
    }
    printf("\n");
}

// Função para encontrar a peça inicial correta
int encontrarPecaInicial(Peca *pecas, int tamanho) {
    int indiceMenor = 0;
    for (int i = 1; i < tamanho; i++) {
        if (pecas[i].lado1 < pecas[indiceMenor].lado1 || 
           (pecas[i].lado1 == pecas[indiceMenor].lado1 && pecas[i].lado2 < pecas[indiceMenor].lado2)) {
            indiceMenor = i;
        }
    }
    return indiceMenor;
}

int backtrack(Domino *d, int index, int ultimo, int *usadas, Peca *sequencia, No *pecas[]) {
    if (index == d->tamanho) return 1; // Sequência completa encontrada

    for (int i = 0; i < d->tamanho; i++) {
        if (!usadas[i]) {
            Peca p = pecas[i]->peca; // Pegamos a peça correta
            
            if (ultimo == p.lado1) {
                usadas[i] = 1;
                sequencia[index] = p; // Usa a peça original
                if (backtrack(d, index + 1, p.lado2, usadas, sequencia, pecas)) {
                    return 1;
                }
                usadas[i] = 0; // Backtracking - desfaz a escolha
            } 
            else if (ultimo == p.lado2) {
                usadas[i] = 1;
                // Inverte a peça para encaixar na sequência
                sequencia[index] = (Peca){p.lado2, p.lado1};
                if (backtrack(d, index + 1, p.lado1, usadas, sequencia, pecas)) {
                    return 1;
                }
                usadas[i] = 0;
            }
        }
    }
    return 0;
}

int DominoEhPossivelOrganizar(Domino *d, Peca *sequencia) {
    if (d == NULL || d->tamanho == 0) return 0;

    int usadas[d->tamanho];
    for (int i = 0; i < d->tamanho; i++) usadas[i] = 0;

    // Criar um array de ponteiros para acessar as peças mais facilmente
    No *pecas[d->tamanho];
    No *atual = d->inicio;
    for (int i = 0; i < d->tamanho; i++) {
        pecas[i] = atual;
        atual = atual->prox;
    }

    // Tentar iniciar com cada peça
    for (int i = 0; i < d->tamanho; i++) {
        usadas[i] = 1;
        sequencia[0] = pecas[i]->peca;
        if (backtrack(d, 1, sequencia[0].lado2, usadas, sequencia, pecas)) {
            return 1; // Sequência válida encontrada
        }
        usadas[i] = 0;
    }

    return 0; // Nenhuma sequência válida encontrada
}

