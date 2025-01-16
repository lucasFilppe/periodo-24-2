#include <stdio.h>

int main() {
    int valor;
    int notas100, notas50, notas20, notas10, notas5, notas2, notas1;

    // Captura o valor inteiro em reais
    printf("Digite o valor em reais: ");
    scanf("%d", &valor);

    // Calcula a quantidade de cada nota
    notas100 = valor / 100;
    valor %= 100;

    notas50 = valor / 50;
    valor %= 50;

    notas20 = valor / 20;
    valor %= 20;

    notas10 = valor / 10;
    valor %= 10;

    notas5 = valor / 5;
    valor %= 5;

    notas2 = valor / 2;
    valor %= 2;

    notas1 = valor; // Resto final são as notas de R$ 1

    // Exibe o resultado
    printf("Notas necessárias:\n");
    printf("R$ 100: %d nota(s)\n", notas100);
    printf("R$ 50: %d nota(s)\n", notas50);
    printf("R$ 20: %d nota(s)\n", notas20);
    printf("R$ 10: %d nota(s)\n", notas10);
    printf("R$ 5: %d nota(s)\n", notas5);
    printf("R$ 2: %d nota(s)\n", notas2);
    printf("R$ 1: %d nota(s)\n", notas1);

    return 0;
}
