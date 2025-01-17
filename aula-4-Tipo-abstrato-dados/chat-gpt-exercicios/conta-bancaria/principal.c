#include"conta-bancaria.h"
#include<stdio.h>

int main() {
    ContaBancaria *conta1;

    conta1 = Inicializa(918556, 300.00);  // Inicializa a conta
    printf("\nAntes da movimentacao:\n");
    Imprime(conta1);  // Imprime o estado inicial

    Deposito(conta1, 1200);

    printf("\nDepois da movimentacao:\n");
    Imprime(conta1);  // Imprime o estado final

    return 0;
}
