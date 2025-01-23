#include"matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Matriz* matriz;
    int l, c;

    printf("Digite o tamanho da matriz m por n: ");
    scanf("%d %d", &l, &c);

    matriz = Cria_Matriz(l, c);
    
    //lendo matriz
    printf("Digite os valores da matriz: ");
    for(int i = 0; i < l; i++){
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &matriz->M[i][j]);
        }
        
    }

    // Imprimir a matriz
    imprime_Matriz(matriz, l, c);

    //testa aceesa matriz
     int x = 2, y = 2; // Posição a ser acessada
    printf("Elemento na posição (%d, %d): %.2f\n", x, y, Acessa_Matriz(matriz, x, y));

    //testa atribuição a matriz
    float valor;
    printf("Digite um valor para atribuir a matriz: ");
    scanf("%f", &valor);

    Atribui_Matriz(matriz, 1, 1, valor);
    // Imprimir a matriz
    imprime_Matriz(matriz, l, c);

    // Liberar memória alocada para a matriz
    Libera_Matriz(matriz);

    return 0;
}
