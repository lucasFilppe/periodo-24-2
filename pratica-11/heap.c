#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Cria e retorna um tipo chamada baseado nas informações separadas
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano) {
    Chamada chamada;
    strncpy(chamada.nome, nome, sizeof(chamada.nome) - 1);
    chamada.nome[sizeof(chamada.nome) - 1] = '\0'; // Garante terminação correta
    chamada.prioridade = prioridade;
    chamada.nascimento.dia = dia;
    chamada.nascimento.mes = mes;
    chamada.nascimento.ano = ano;
    return chamada;
}

// Aloca e retorna um heap vazio
Heap* criarHeap() {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    if (heap) {
        heap->tam = 0;
    }
    return heap;
}

// Libera a memória do heap
Heap* destroiHeap(Heap *heap) {
    if (heap) {
        free(heap);
    }
    return NULL;
}

// Verifica se ainda tem chamadas no heap
bool consultarSeTemProximaChamada(Heap *heap) {
    return heap->tam > 0;
}

// Verifica se c1 tem mais prioridade do que c2
bool temMaisPrioridade(Chamada* c1, Chamada* c2) {
    if (c1->prioridade > c2->prioridade) return true;
    if (c1->prioridade < c2->prioridade) return false;
    
    // Se prioridades forem iguais, considera a pessoa mais velha
    if (c1->nascimento.ano < c2->nascimento.ano) return true;
    if (c1->nascimento.ano > c2->nascimento.ano) return false;
    if (c1->nascimento.mes < c2->nascimento.mes) return true;
    if (c1->nascimento.mes > c2->nascimento.mes) return false;
    return c1->nascimento.dia < c2->nascimento.dia;
}

// Refaz o heap da raiz para as folhas
void refaz(Heap *heap) {
    int i = 0;
    while (2 * i + 1 < heap->tam) {
        int filho = 2 * i + 1;
        if (filho + 1 < heap->tam && temMaisPrioridade(&heap->chamadas[filho + 1], &heap->chamadas[filho])) {
            filho++;
        }
        if (temMaisPrioridade(&heap->chamadas[filho], &heap->chamadas[i])) {
            Chamada temp = heap->chamadas[i];
            heap->chamadas[i] = heap->chamadas[filho];
            heap->chamadas[filho] = temp;
            i = filho;
        } else {
            break;
        }
    }
}

// Insere uma chamada no heap
void heapInsere(Heap *heap, Chamada chamada, int index) {
    while (index > 0) {
        int pai = (index - 1) / 2;
        if (temMaisPrioridade(&chamada, &heap->chamadas[pai])) {
            heap->chamadas[index] = heap->chamadas[pai];
            index = pai;
        } else {
            break;
        }
    }
    heap->chamadas[index] = chamada;
}

// Insere uma chamada no heap
void inserirChamada(Heap *heap, Chamada chamada) {
    if (heap->tam < 100) {
        heapInsere(heap, chamada, heap->tam);
        heap->tam++;
    }
}

// Remove a chamada com maior prioridade do heap
Chamada atenderChamada(Heap *heap) {
    Chamada chamadaAtendida = heap->chamadas[0];
    heap->chamadas[0] = heap->chamadas[heap->tam - 1];
    heap->tam--;
    refaz(heap);
    return chamadaAtendida;
}


// Mantenha como especificado
void imprimeChamada(Chamada chamada) {
    printf("%02d | %02d/%02d/%04d | %s\n", chamada.prioridade, chamada.nascimento.dia,
            chamada.nascimento.mes, chamada.nascimento.ano, chamada.nome);
}
