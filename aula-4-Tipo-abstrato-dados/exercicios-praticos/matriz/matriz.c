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

void imprime_Matriz(Matriz* mat, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", mat->M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para acessar o elemento na posição x, y
float Acessa_Matriz(Matriz* mat, int x, int y) {
    if (x < 0 || x >= mat->lin || y < 0 || y >= mat->col) {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(EXIT_FAILURE);
    }
    return mat->M[x][y];
}

void Atribui_Matriz(Matriz* mat, int i, int j, float valor) {
    // Verifica se os índices estão dentro dos limites da matriz
    if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(EXIT_FAILURE); // Encerra o programa em caso de erro
    }
    // Atribui o valor à posição (i, j)
    mat->M[i][j] = valor;
}