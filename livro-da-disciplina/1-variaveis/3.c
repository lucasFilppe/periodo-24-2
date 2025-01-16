#include <stdio.h>

int main() {
    double segundos;
    int horas, minutos;
    double segundos_restantes;

    // Captura o número de segundos do teclado
    printf("Digite o número de segundos transcorridos: ");
    scanf("%lf", &segundos);

    // Calcula horas, minutos e segundos
    horas = (int)(segundos / 3600);
    minutos = (int)((segundos - (horas * 3600)) / 60);
    segundos_restantes = segundos - (horas * 3600) - (minutos * 60);

    // Exibe o tempo no formato h:m:s
    printf("%02d:%02d:%05.2f\n", horas, minutos, segundos_restantes);

    return 0;
}
