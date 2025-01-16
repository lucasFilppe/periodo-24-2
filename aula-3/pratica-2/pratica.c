#include <stdio.h>

#include "matriz.h"

int main()
{
    char opcao;
    int n, cont;
    double s;          // Variável para armazenar a soma da área inferior

    // Leitura do Char
    // Leitura do Char
    scanf(" %c", &opcao);
    
    // Leitura do tamanho da matriz
    scanf("%d", &n);
    
    // Declarar e alocar matriz
    Matriz *m = alocar(n);
    
    // Leitura da Matriz e Cálculos
     le(m);
    
    // Soma parte dos valores da matriz e conta a quantidade
    s = somaParte(m, &cont);
    
    // Impressão dos resultados
    if (opcao == 'S') {
        printf("%.1lf\n", s); // Soma
    } else if (opcao == 'M') {
        printf("%.1lf\n", s / cont); // Média
    }

    // Liberar memória
    m = desalocar(m);
    return 0;
}
