#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "ponto.h"

//definição dos dados e seus tipos
struct ponto{
    float x;
    float y;
};

Ponto* PontoCria( float x, float y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    if(p == NULL){
        printf("Memoria insuficiente");
        exit(1);
    }
    p->x = x;
    p->y = y;

    return p;
}

void PontoLibera(Ponto** p){
    free(*p);
    free(p);
}

//devolve as coordenadas de um ponto
void PontoAcessa(Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

//atribui novos valores a um ponto
void PontoAtribui(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

//calculA a distancia entre dois pontos
float PontoDistancia(Ponto *p1, Ponto* p2){
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;

    return sqrt(dx * dx + dy *dy);
}