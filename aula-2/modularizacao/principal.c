#include <stdio.h>
#include "converte.h" // inclus ão do mó dulo de convers ão de temperaturas

int main(void)
{
  float t1; /* espa ço para armazenar temperatura em Celsius */
  float t2; /* espa ço para armazenar temperatura em Fahrenheit */
  printf(" Entre com temperatura em Celsius : ");
  /* captura valor entrado via teclado */
  scanf("%f", &t1);
  /* faz a convers ão */
  t2 = converte_celsius_fahrenheit(t1);
  /* exibe resultado */
  printf(" Fahrenheit : %f\n", t2);
  return 0;
}