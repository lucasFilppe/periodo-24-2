#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
#define PI 3.1415

struct circulo
{
    float raio;
};

//retorna um ponteiro que aponta para estruta do tipo circulo 
Circulo* Circulo_Cria(float raio){
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    if(c == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    c->raio = raio;

    return c;
    
}

//FUNÇÃO QUE calcula a area de um circulo
float Circulo_Area(Circulo* c){
    if (c == NULL)
    {
        printf("Memoria insuficiente\n\n");
        exit(1);
    }
    
    float area = (PI * pow(c->raio, 2));
    return area;
}

//calcula o perimetro de um circulo
float Circulo_Perimetro(Circulo* c){
    if(c == NULL){
        printf("Memoria insuficiente\n\n");
        exit(1);
    }
    float perimetro = 2.0 * PI * c->raio;
    return perimetro; 

}

void Circulo_Libera(Circulo* c){
    free(c);
}