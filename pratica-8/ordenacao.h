#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct {
    char nome[100]; // String para armazenar o nome da pessoa
    int idade;      // Inteiro para armazenar a idade
} Pessoa;

// Manter como especificado
void MergeSort(Pessoa *vetor, int esquerda, int direita);

// Manter como especificado
void merge(Pessoa *vetor, int esquerda, int meio, int direita);

// Manter como especificado
Pessoa *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Pessoa **vetor);

#endif

