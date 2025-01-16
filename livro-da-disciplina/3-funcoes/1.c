#include <stdio.h>
#include <math.h>
#define M_PI 3.1415;

// Função para calcular o volume de uma esfera
double volume_esfera(double raio) {
    return (4.0 / 3.0) * M_PI * pow(raio, 3);
}

// Função para calcular o volume de uma calota esférica
double volume_calota(double raio, double altura) {
    return (1.0 / 3.0) * M_PI * pow(altura, 2) * (3 * raio - altura);
}

// Função para calcular o volume de um cilindro
double volume_cilindro(double raio, double altura) {
    return M_PI * pow(raio, 2) * altura;
}

// Função para calcular o volume da peça formada pela esfera com furo cilíndrico
double volume_peca(double raio_esfera, double raio_furo, double altura_furo) {
    double volume_total_esfera = volume_esfera(raio_esfera);
    double volume_cilindro_furo = volume_cilindro(raio_furo, altura_furo);
    double volume_calotas = 2 * volume_calota(raio_esfera, altura_furo / 2);

    return volume_total_esfera - (volume_cilindro_furo + volume_calotas);
}

int main() {
    double raio_esfera, raio_furo, altura_furo;

    printf("Cálculo do volume da peça\n");
    printf("Digite o raio da esfera: ");
    scanf("%lf", &raio_esfera);

    printf("Digite o raio do furo cilíndrico: ");
    scanf("%lf", &raio_furo);

    printf("Digite a altura do furo cilíndrico: ");
    scanf("%lf", &altura_furo);

    if (altura_furo > 2 * raio_esfera) {
        printf("Erro: a altura do furo não pode ser maior que o diâmetro da esfera.\n");
        return 1;
    }

    double volume = volume_peca(raio_esfera, raio_furo, altura_furo);
    printf("O volume da peça é: %.2f unidades cúbicas\n", volume);

    return 0;
}
