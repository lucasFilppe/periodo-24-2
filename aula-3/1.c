#include <stdio.h>
#include <stdlib.h>

// Função que retorna um vetor com os elementos do original em ordem inversa
float *reverso(int n, float *v) {
    // Aloca dinamicamente memória para o vetor reverso
    float *reversed = (float *)malloc(n * sizeof(float));
    if (reversed == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    // Copia os elementos em ordem inversa
    for (int i = 0; i < n; i++) {
        reversed[i] = v[n - 1 - i];
    }

    return reversed; // Retorna o ponteiro para o vetor invertido
}

int main() {
    int n = 4; // Tamanho do vetor
    float v[] = {1.0, 2.0, 3.0, 4.0}; // Vetor original

    // Chama a função reverso
    float *v_reverso = reverso(n, v);
    if (v_reverso == NULL) {
        return 1; // Sai do programa em caso de erro na alocação
    }

    // Imprime o vetor invertido
    printf("Vetor invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", v_reverso[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(v_reverso);

    return 0;
}
