#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
    double **values;
    int n;
};

Matriz* alocar(int n) {
    // Alocando estrutura da matriz
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));

    // Definindo o tamanho da matriz
    matriz->n = n;

    // Alocando matriz do tipo double
    matriz->values = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matriz->values[i] = (double*)malloc(n * sizeof(double));
    }

    return matriz;
}

Matriz* desalocar(Matriz *matriz) {
    // Liberar a memória alocada
    for (int i = 0; i < matriz->n; i++) {
        free(matriz->values[i]);
    }
    free(matriz->values);
    free(matriz);
    return NULL;
}

void le(Matriz *matriz) {
    // Lendo os valores da matriz
    for (int i = 0; i < matriz->n; i++) {
        for (int j = 0; j < matriz->n; j++) { // Corrigido o loop interno
            scanf("%lf", &matriz->values[i][j]);
        }
    }
}

double somaParte(Matriz *matriz, int *cont) {
     double resultado = 0.0;
    // Supondo que a matriz é quadrada e está corretamente inicializada
    int tamanho = matriz->n;
   
    // Ajusta os limites do loop com base no tamanho da matriz
    for (int i = 7; i < tamanho; i++) { // Linhas da área inferior (7 até tamanho-1)
        for (int j = tamanho - i; j < i && j < tamanho; j++) { // Colunas dentro da área
            if (j >= 0) { // Verifica se o índice da coluna é válido
                resultado += matriz->values[i][j];
                (*cont)++; // Incrementa o contador de elementos
            }
        }
    }

    return resultado;
}
