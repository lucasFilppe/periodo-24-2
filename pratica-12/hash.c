#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"

// Função para inicializar a Tabela Hash
void inicia(Hash* hash, int m, int p) {
    hash->m = m;
    hash->p = p;

    // Alocar memória para o vetor de chaves
    hash->chaves = (Chave*)malloc(m * sizeof(Chave));
    if (hash->chaves == NULL) {
        printf("Erro ao alocar memória para chaves.\n");
        exit(1);
    }

    // Alocar memória para o vetor de pesos
    hash->pesos = (int*)malloc(p * sizeof(int));
    if (hash->pesos == NULL) {
        printf("Erro ao alocar memória para pesos.\n");
        exit(1);
    }

    // Inicializar todas as chaves como vazias
    for (int i = 0; i < m; i++) {
        strcpy(hash.chaves[i], "");
    }
}

// Função para liberar a memória alocada
void libera(Hash* hash) {
    free(hash->chaves);
    free(hash->pesos);
}

// Função de transformação H(s)
int H(Hash* hash, Chave chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        int peso = hash->pesos[i % hash->p];
        soma += chave[i] * peso;
    }
    return soma % hash->m;
}
