#include <stdio.h>
#include <math.h>

int main() {
    double radianos;
    double graus_decimal;
    int graus, minutos;
    double segundos;

    // Captura o valor do ângulo em radianos
    printf("Digite o valor do ângulo em radianos: ");
    scanf("%lf", &radianos);

    // Converte radianos para graus em formato decimal
    graus_decimal = radianos * 57.29578;

    // Extrai graus inteiros
    graus = (int)graus_decimal;

    // Calcula os minutos
    minutos = (int)((graus_decimal - graus) * 60);

    // Calcula os segundos
    segundos = ((graus_decimal - graus) * 60 - minutos) * 60;

    // Exibe o resultado
    printf("O ângulo equivale a: %d graus, %d minutos e %.2f segundos\n", graus, minutos, segundos);

    return 0;
}
