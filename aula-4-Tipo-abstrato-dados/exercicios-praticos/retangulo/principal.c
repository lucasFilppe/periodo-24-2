#include <stdio.h>
#include "retangulo.h"

int main() {
    // Criar um retângulo
    Retangulo *ret = retangulo_Cria(10.0, 5.0);

    // Calcular e imprimir a área
    float area = retangulo_Area(ret);
    if (area != -1) {
        printf("Área do retângulo: %.2f\n", area);
    }

    // Liberar a memória
    retangulo_Libera(ret);

    return 0;
}
