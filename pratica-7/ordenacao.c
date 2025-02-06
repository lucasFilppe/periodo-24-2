#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
int* alocaVetor(int n){
  int * v = (int*)malloc(n * sizeof(int));
  if (v == NULL)
  {
    printf("MEMORIA INSUFIECIENTE!!!\n");
  }
  
  return v;
}

// Manter como especificado
int* desalocaVetor(int* v){
  free(v);
  return NULL;
}

void ordenacao(int* v, int n, int* movimentos) {
    int i, j;
    *movimentos = 0;
    int trocou;
    int max_iteracoes = 100000; // Limite arbitrário

    for (i = 0; i < n - 1 && max_iteracoes > 0; i++) {
        trocou = 0;
        for (j = 0; j < n - i - 1 && max_iteracoes > 0; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*movimentos)++;
                trocou = 1;
                max_iteracoes--;
            }
        }
        if (!trocou) {
            break;
        }
    }
}