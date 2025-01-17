#include "circulo.h"
#include <stdio.h>

int main(){

  float r;
  printf("Digite o raio:");
  scanf("%f", &r);

  Circulo *c = Circulo_Cria(r);

  float area = Circulo_Area(c);
  float perimetro = Circulo_Perimetro(c);

  printf("Area do circulo: %.2f\n", area);
  printf("Perimetro do circulo: %.2f\n", perimetro);

  Circulo_Libera(c);

  return 0;
}