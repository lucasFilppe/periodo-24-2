#include <stdio.h>
#include <stdlib.h>
#include "numero-inteiro.h"

struct vetor
{
  int *dados;
  int tamanho;
};

// Função para criar um vetor
Vetor* Vetor_Cria(int tamanho) {
    // Verifica se o tamanho é válido
    if (tamanho <= 0) {
        printf("Erro: tamanho do vetor é inválido\n");
        exit(1);
    }

    // Aloca memória para a estrutura Vetor
    Vetor* v = malloc(sizeof(Vetor));
    if (v == NULL) {
        printf("Erro: memória insuficiente\n");
        exit(1);
    }

    // Aloca memória para o array de inteiros
    v->dados = malloc(tamanho * sizeof(int));
    if (v->dados == NULL) {
        printf("Erro: memória insuficiente\n");
        free(v); // Libera a estrutura alocada antes de sair
        exit(1);
    }

    v->tamanho = tamanho;

    // Inicializa os elementos do vetor com zero
    for (int i = 0; i < tamanho; i++) {
        v->dados[i] = 0;
    }

    return v;
}

// Função para liberar a memória do vetor
void Vetor_Libera(Vetor* v) {
    if (v != NULL) {
        free(v->dados); // Libera o array de inteiros
        free(v);        // Libera a estrutura Vetor
    }
}

// Função para definir um valor em uma posição específica
void Vetor_Set(Vetor* v, int indice, int valor) {
    if (indice < 0 || indice >= v->tamanho) {
        printf("Erro: índice fora do intervalo\n");
        exit(1);
    }
    v->dados[indice] = valor;
}

// Função para obter o valor em uma posição específica
int Vetor_Get(Vetor* v, int indice) {
    if (indice < 0 || indice >= v->tamanho) {
        printf("Erro: índice fora do intervalo\n");
        exit(1);
    }
    return v->dados[indice];
}

// Função para imprimir os elementos do vetor
void Vetor_Imprime(Vetor* v) {
    if (v == NULL) {
        printf("Erro: vetor é NULL\n");
        return;
    }

    printf("Vetor: [");
    for (int i = 0; i < v->tamanho; i++) {
        printf("%d", v->dados[i]);
        if (i < v->tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}