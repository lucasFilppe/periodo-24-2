#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario {
    int matricula;
    char nome[21];
};


struct carro {
    int chassi;
    char marca[21];
    int lugares;
    int ano;
    Funcionario* func;
};

Funcionario* FuncionarioAloca( ) {
    Funcionario *func = (Funcionario*)malloc(sizeof(Funcionario));
    if (func == NULL) {
        return NULL;
    }
    return func;
}

void FuncionarioDesaloca(Funcionario** func) {
        free(*func);
}

Carro* CarroAloca(int n) {
    Carro *carros = (Carro*)malloc(n * sizeof(Carro));
    if (carros == NULL) {
        exit(1);
    }
    for (int i = 0; i < n; i++){
        carros[i].func = malloc(sizeof(Funcionario));
        if (carros[i].func == NULL) {
            for (int j = 0; j < i; j++) {
                FuncionarioDesaloca(&carros[j].func);
            }
            free(carros);
            exit(1);
        }
    }
    return carros;
}

void CarroDesaloca(Carro** carros, int n) {
    for (int i = 0; i < n; i++) {
        FuncionarioDesaloca(&(*carros)[i].func);
    }
    free(*carros);
}

void le(Carro* carros, int n) {
    for(int i = 0; i < n; i++){
        scanf("%d %s %d %d %s %d", 
            &carros[i].chassi, carros[i].marca, &carros[i].lugares, 
            &carros[i].ano, carros[i].func->nome, &carros[i].func->matricula) ;
    }
}

int conta(Carro* carros, int n, const int ano, const int lugares) {
    int contar = 1;
    if(n==0){
        return 0;
    }
    if(carros[n - 1].ano > ano && carros[n - 1].lugares > lugares)
        return contar + conta(carros, n - 1, ano, lugares);
    else
        return conta(carros, n - 1, ano, lugares);
}

void imprime(Carro* carros, int n, const char* nome) {
    if(n==0){
        return ;
    }
    if(strcmp (carros[n - 1].func->nome, nome) == 0){
        printf("%s [%d|%d|%d]\n", carros[n - 1].marca, carros[n - 1].ano, carros[n - 1].lugares, carros[n - 1].chassi );

    }
    imprime (carros, n-1, nome);
}