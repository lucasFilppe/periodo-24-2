#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
    double **values;
    int n;
};

Matriz* alocar(int n) {
    // Preencher aqui
    //aloca memória para a estrutura Matriz
    Matriz *m = (Matriz*)malloc(n * sizeof(Matriz));

    m->n = n;

    //aloca matriz para as linhas
    m->values = (double**)malloc(n *sizeof(double *));

    //aloca matriz para colunas
    for( int i = 0; i < n; i++){
        m->values[i] = (double*)malloc(n * sizeof(double));
    }

     // Inicializa a matriz com zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m->values[i][j] = 0.0;
        }
    }
    
    return m;

}

Matriz* desalocar(Matriz *matriz) {
    // Preencher aqui
    //libera a memoria alocada para cada linha
    for(int i = 0; i < matriz->n; i++){
        free(matriz->values[i]);
    }

    //libera o ponteiro para linhas
    if(matriz->values != NULL){
        free(matriz->values);
    }

    //libera a propria estrutura
    free(matriz);

    // Retorna NULL para indicar que a matriz foi desalocada
    return NULL;
}

void le(Matriz *matriz) {
     //Preencher aqui
     //lendo matriz para linha
     for(int i = 0; i < matriz->n; i++){
        for(int j = 0; i < matriz->n; j++){
            scanf("%lf", &matriz->values[i][j]);
        }
     }

}

double somaParte(Matriz *matriz, int *cont) {

    // Preencher aqui
    double soma = 0.0;
    *cont = 0;

    for(int i = 7; i < matriz->n; i++){
        for(int j = matriz->n - i ; j < i; j++){
            soma += matriz->values[i][j];
            (*cont)++;
        }
    }
    return  soma;
}