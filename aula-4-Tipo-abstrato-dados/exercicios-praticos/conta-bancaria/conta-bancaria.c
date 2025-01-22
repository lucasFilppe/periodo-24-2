#include"conta-bancaria.h"
#include<stdio.h>
#include<stdlib.h>

struct conta{
  int numero;
  double saldo;
};

ContaBancaria* Inicializa(int numero, double saldo) {
       ContaBancaria* conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));

    // Verifica memória
    if (conta == NULL) {
        printf("Memória insuficiente\n");
        return NULL;
    }

    // Inicializa os membros da estrutura
    conta->numero = numero;
    conta->saldo = saldo;

    return conta;
}

void Deposito(ContaBancaria *conta, double valor){
  conta->saldo = conta->saldo + valor;
  printf("Depósito de %.2f realizado com sucesso.\n", valor);

}

void Saque(ContaBancaria *conta, double valor){
  conta->saldo -= valor;
  printf("Saque de %.2f realizado com sucesso.\n", valor);

}

void Imprime(ContaBancaria* conta) {
    printf("Conta: %d\nSaldo: %.2f\n", conta->numero, conta->saldo);
}


void Libera(ContaBancaria* conta) {
    // Verifica se o ponteiro não é NULL antes de tentar liberar a memória
    if (conta != NULL) {
        free(conta);  // Libera a memória alocada para a estrutura
        printf("Memória liberada com sucesso.\n");
    } else {
        printf("Ponteiro NULL. Nenhuma memória para liberar.\n");
    }
}