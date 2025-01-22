#ifndef RETANGULO_H
#define RETANGULO_H

typedef struct retangulo Retangulo;

//retorna uma ponteiro 
Retangulo* retangulo_Cria(float largura, float altura);

void retangulo_Libera(Retangulo *r);

float retangulo_Area(const Retangulo *r);

#endif
