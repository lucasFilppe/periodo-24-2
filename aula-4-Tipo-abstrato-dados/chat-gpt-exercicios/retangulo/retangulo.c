#include "retangulo.h"
#include <stdlib.h>
#include <stdio.h>

struct retangulo
{
    float largura;
    float altura;    
};

Retangulo* retangulo_Cria(float largura, float altura){
    Retangulo *r = malloc(sizeof(Retangulo));

    if (r == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    r->largura = largura;
    r->altura = altura;

    return r;    
}

void retangulo_Libera(Retangulo *r) {
    free(r);
}

// Função para calcular a área do retângulo
float retangulo_Area(const Retangulo *r) {
    if (r == NULL) {
        printf("Erro: ponteiro para Retangulo é NULL\n");
        return -1; // Retorna um valor inválido para indicar erro
    }
    return r->largura * r->altura;
}


