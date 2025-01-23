#include"matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Matriz* matriz;
    int l, c;
    int i, j;

    printf("Digite o tamanho da matriz m por n: ");
    scanf("%d %d", &l, &c);

    matriz = Cria_Matriz(l, c);
    int cont = 0;
    

    // Imprimir a matriz
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%f ", matriz->M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    float valor = Acessa_Matriz(matriz, 0, 3);
    printf("Valor acessado %f\n", valor);

    // Liberar memória alocada para a matriz
    Libera_Matriz(matriz);

    return 0;
}
