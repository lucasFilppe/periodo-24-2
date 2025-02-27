#include <stdio.h>
#include <stdlib.h>

#include "busca.h"

int main() {
    int M;
    scanf("%d", &M);
    
    while (M--) {
        int X, N;
        scanf("%d %d", &X, &N);
        
        int *arr = aloca(N);
        if (!arr) {
            printf("Erro de alocação de memória\n");
            return 1;
        }
        
        le(arr, N);
        
        int seq_comp = buscaSequencial(arr, N, X);
        
        quicksort(arr, 0, N - 1);
        int bin_comp = buscaBinaria(arr, N, X);
        
        printf("%d %d\n", seq_comp, bin_comp);
        
        desaloca(&arr);
    }
    
    return 0;
}