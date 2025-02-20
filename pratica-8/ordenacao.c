#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

// Manter como especificado
Pessoa *alocaVetor(int n) {
    return (Pessoa *)malloc(n * sizeof(Pessoa));
}

// Manter como especificado
void desalocaVetor(Pessoa **vetor) {
    if (*vetor != NULL) {
        free(*vetor);
        *vetor = NULL;
    }
}

// Função merge para combinar os subarrays ordenados
void merge(Pessoa *vetor, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Aloca vetores auxiliares
    Pessoa *L = (Pessoa *)malloc(n1 * sizeof(Pessoa));
    Pessoa *R = (Pessoa *)malloc(n2 * sizeof(Pessoa));

    // Copia os dados para os vetores auxiliares
    for (int i = 0; i < n1; i++)
        L[i] = vetor[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    // Mescla os dois subarrays ordenados
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        // Comparação direta dentro do merge
        if (strcmp(L[i].nome, R[j].nome) < 0 || 
           (strcmp(L[i].nome, R[j].nome) == 0 && L[i].idade <= R[j].idade)) {
            vetor[k++] = L[i++];
        } else {
            vetor[k++] = R[j++];
        }
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) vetor[k++] = L[i++];

    // Copia os elementos restantes de R[], se houver
    while (j < n2) vetor[k++] = R[j++];

    // Libera memória dos vetores auxiliares
    free(L);
    free(R);
}

// Implementação recursiva do Merge Sort
void MergeSort(Pessoa *vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        MergeSort(vetor, esquerda, meio);
        MergeSort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}
