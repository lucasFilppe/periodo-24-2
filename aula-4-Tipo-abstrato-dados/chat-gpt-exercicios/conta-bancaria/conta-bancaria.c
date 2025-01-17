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

void Imprime(ContaBancaria* conta) {
    printf("Conta: %d\nSaldo: %.2f\n", conta->numero, conta->saldo);
}


