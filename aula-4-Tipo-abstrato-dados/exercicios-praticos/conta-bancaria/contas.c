#include <stdio.h>
#include <stdlib.h>
#include "conta-bancaria.h"
#include "contas.h"

struct contas{
  ContaBancaria** contas; // Ponteiro para um array de ponteiros para ContaBancaria
  int numContas;          // Número de contas armazenadas
};


void InicializaContas(Contas *cnt){
  //aloca memoria para o array de ponteiros para conta bancaria
  cnt->contas = (ContaBancaria**)malloc(10 *sizeof(ContaBancaria*));

  if (cnt->contas == NULL) {
        printf("Memória insuficiente para inicializar o array de contas bancárias.\n");
        return;
    }
  
  //inicializa o número de contas como zero
  cnt->numContas = 0;
   printf("Estrutura Contas inicializada com sucesso.\n");
  
}