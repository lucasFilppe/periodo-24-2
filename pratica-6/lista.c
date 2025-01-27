#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TAM 10

struct lista {
    int dados[MAX_TAM];
    int inicio;
    int tamanho;       
};

// Função para criar e inicializar uma nova lista
Lista* cria() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->inicio = 0;
        lista->tamanho = 0;
    }
    return lista;
}

// Função para liberar a memória da lista
Lista* libera(Lista *lista) {
    if (lista != NULL) {
        free(lista);
    }
    return NULL;
}

// Função para imprimir todos os elementos da lista
void imprime(Lista *lista) {
    if (lista == NULL || lista->tamanho == 0) {
        printf("\n");
        return;
    }
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[(lista->inicio + i) % MAX_TAM]);
    }
    printf("\n");
}

// Função para verificar se um elemento pertence à lista
bool pertence(Lista *lista, int chave) {
    if (lista == NULL || lista->tamanho == 0) return false;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[(lista->inicio + i) % MAX_TAM] == chave) {
            return true;
        }
    }
    return false;
}

bool insereOrdenado(Lista *lista, int chave) {
    if (lista == NULL || lista->tamanho == MAX_TAM) return false;

    int i;

    // Encontrar a posição para inserir o elemento
    for (i = lista->tamanho; i > 0 && lista->dados[(lista->inicio + i - 1) % MAX_TAM] > chave; i--) {
        lista->dados[(lista->inicio + i) % MAX_TAM] = lista->dados[(lista->inicio + i - 1) % MAX_TAM];
    }

    // Inserir o elemento na posição correta
    lista->dados[(lista->inicio + i) % MAX_TAM] = chave;
    lista->tamanho++;
    return true;
}


// Função para retirar um elemento específico da lista
bool retiraEspecifico(Lista *lista, int chave) {
    if (lista == NULL || lista->tamanho == 0) return false;

    int i, pos = -1;

    // Encontrar o índice do elemento a ser removido
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->dados[(lista->inicio + i) % MAX_TAM] == chave) {
            pos = (lista->inicio + i) % MAX_TAM;
            break;
        }
    }

    if (pos == -1) return false; // Elemento não encontrado

    // Remover o elemento e ajustar o vetor
    for (i = pos; i != (lista->inicio + lista->tamanho - 1) % MAX_TAM; i = (i + 1) % MAX_TAM) {
        lista->dados[i] = lista->dados[(i + 1) % MAX_TAM];
    }

    lista->tamanho--;
    return true;
}

// Função para retirar o primeiro elemento da lista
bool retiraInicio(Lista *lista) {
    if (lista == NULL || lista->tamanho == 0) return false;

    lista->inicio = (lista->inicio + 1) % MAX_TAM;
    lista->tamanho--;
    return true;
}

// Função para retornar a posição inicial da lista
int posicaoInicialLista(Lista *lista) {
    if (lista == NULL) return -1;
    return lista->inicio;
}
