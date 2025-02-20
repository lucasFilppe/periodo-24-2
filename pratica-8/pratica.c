#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; 
    int i = 0;

    // Leia o número de casos de teste
    scanf("%d", &n);

    // Enquanto houver casos de teste
    while (i < n) {
        int p;
        int j;
        Pessoa *pessoas;

        // Leia o número de pessoas
        scanf("%d", &p);

        // Aloque o vetor
        pessoas = alocaVetor(p);
        if (pessoas == NULL) {
            fprintf(stderr, "Erro ao alocar memória.\n");
            return 1;
        }

        // Para cada pessoa, leia nome e idade
        for (j = 0; j < p; j++) {
            scanf("%s %d", pessoas[j].nome, &pessoas[j].idade);
        }

        // Ordena o vetor usando MergeSort
        MergeSort(pessoas, 0, p - 1);

        // Imprime o cabeçalho do teste
        printf("Teste %d:\n", i + 1);

        // Imprime o resultado ordenado no formato desejado
        for (j = 0; j < p; j++) {
            printf("%s - %d\n", pessoas[j].nome, pessoas[j].idade);
        }

        // Linha em branco entre os casos de teste, exceto no último
        if (i < n - 1) {
            printf("\n");
        }

        // Libera a memória do vetor
        desalocaVetor(&pessoas);

        i++;
    }

    return 0;
}

