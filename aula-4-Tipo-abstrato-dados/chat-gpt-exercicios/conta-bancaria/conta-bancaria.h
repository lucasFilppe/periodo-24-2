#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct conta ContaBancaria;

ContaBancaria* Inicializa( int numero, double saldo);
void Deposito(ContaBancaria *conta, double valor);
double Saque(ContaBancaria conta, double valor);
void Imprime(ContaBancaria* conta);

#endif
