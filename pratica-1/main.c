#include <stdio.h>

void readMatrix(double matrix[12][12]);
double sumMatrix(double matrix[12][12]);

int main()
{
    double s = 0.0, M[12][12];
    char T;

    // Leitura do Char
    scanf(" %c", &T);

    // Leitura da Matriz
    readMatrix(M);

    // Cálculo da soma da área inferior
    s = sumMatrix(M);

    // Impressão dos resultados
    if (T == 'S') {
        printf("%.1lf\n", s); // Soma
    } else if (T == 'M') {
        printf("%.1lf\n", s / 30.0); // Média (30 elementos na área inferior)
    }

    return 0;
}

void readMatrix(double matrix[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matrix[i][j]); // Leitura de cada elemento da matriz
        }
    }
}

double sumMatrix(double matrix[12][12]) {
    double resultado = 0.0;

    // Percorre a área inferior da matriz
    for (int i = 7; i < 12; i++) { // Linhas da área inferior (7 a 11)
        for (int j = 12 - i; j < i; j++) { // Colunas dentro da área verde
            resultado += matrix[i][j];
        }
    }

    return resultado;
}

