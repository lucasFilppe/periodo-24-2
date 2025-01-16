#include <stdio.h>

int main() {
    int a, b, c, temp;

    // Captura os três números inteiros
    printf("Digite três números inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    // Ordenação usando comparações simples
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    // Exibe os números em ordem crescente
    printf("Números em ordem crescente: %d, %d, %d\n", a, b, c);

    return 0;
}
