#include <stdio.h>
#include "numero-inteiro.h"

int main() {
    // Criar um vetor de tamanho 5
    Vetor* v = Vetor_Cria(5);

    // Definir valores no vetor
    Vetor_Set(v, 0, 10);
    Vetor_Set(v, 1, 20);
    Vetor_Set(v, 2, 30);

    // Imprimir o vetor
    Vetor_Imprime(v);

    // Obter e imprimir um valor específico
    int valor = Vetor_Get(v, 1);
    printf("Valor na posição 1: %d\n", valor);

    // Liberar a memória
    Vetor_Libera(v);

    return 0;
}