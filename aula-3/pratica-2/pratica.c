#include <stdio.h>
#include "matriz.h"

int main() {
    int n, cont;
    char opcao;

    // Leitura da operação desejada
    scanf(" %c", &opcao);

    // Leitura do tamanho da matriz
    scanf("%d", &n);

    // Declarar e alocar matriz
    Matriz* matriz = alocar(n);

    // Leitura da matriz
    le(matriz);

    /*  Impressão da matriz
    printf("Matriz lida:\n");
     for (int i = 0; i < matriz->n; i++) {
        for (int j = 0; j < matriz->n; j++) {
            printf("%.2lf ", matriz->values[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    // Soma parte da matriz
    
    double soma = somaParte(matriz, &cont);
    // Impressão dos resultados
    if (opcao == 'S') {
        printf("%.1lf\n", soma); // Soma
    } else if (opcao == 'M') {
        printf("%.1lf\n", soma / 30.0); // Média (30 elementos na área inferior)
    }

    // Liberar memória
    matriz = desalocar(matriz);

    return 0;
}


