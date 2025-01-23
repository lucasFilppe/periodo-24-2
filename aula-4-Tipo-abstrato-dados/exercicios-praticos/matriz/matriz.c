#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>


// Função para criar a matriz
Matriz* Cria_Matriz(int lin, int col) {
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    if (mat == NULL) return NULL;

    mat->lin = lin;
    mat->col = col;

    mat->M = (float**)malloc(lin * sizeof(float*));
   

    for (int i = 0; i < lin; i++) {
        mat->M[i] = (float*)malloc(col * sizeof(float));
    }
    return mat;
}

// Função para liberar a matriz
void Libera_Matriz(Matriz* mat) {
    for (int i = 0; i < mat->lin; i++) {
        free(mat->M[i]);
    }
    free(mat->M);
    free(mat);
}

float Acessa_Matriz(Matriz* mat, int i, int j) {
    // Verifica se os índices estão fora dos limites da matriz
    if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
        printf("Elemento indisponível: índices fora dos limites\n");
        return -1.0; // Retorna um valor especial para indicar erro
    }

    // Retorna o valor diretamente do índice (i, j)
    return mat->M[i][j];
}