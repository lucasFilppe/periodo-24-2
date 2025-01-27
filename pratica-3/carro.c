#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario {
    /* seu codigo aqui */
    char nome[20];
    int matricula;

};


struct carro {
    /* seu codigo aqui */
    Funcionario* func;
    int numChassi;
    char modelo[20];
    int lugares;
    int anoFabricacao;
};

Funcionario* FuncionarioAloca() {
    //alocando memoria para funcionario
    Funcionario x = (Funcionario*)malloc(sizeof(Funcionario));
    if(lucas == NULL){
        printf("Memoria insuficiente\n");
        exit(1);
    }

    // Não é necessário alocar memória para 'nome', pois ele já está definido como array fixo dentro da estrutura

    return x;

}

void FuncionarioDesaloca(Funcionario** func) {
    /* seu codigo aqui */
     // Libera a memória alocada para o funcionário
    free(*func);

}

Carro* CarroAloca(int n) {
    /* seu codigo aqui */
}

void CarroDesaloca(Carro** carros, int n) {
    /* seu codigo aqui */
}

void le(Carro* carros, int n) {
    /* seu codigo aqui */
}

int conta(Carro* carros, int n, const int ano, const int lugares) {
    /* seu codigo aqui */
}

void imprime(Carro* carros, int n, const char* nome) {
    /* seu codigo aqui */
}
