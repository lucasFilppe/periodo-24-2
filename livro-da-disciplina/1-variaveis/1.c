#include <stdio.h>
#include <math.h>

int main(){
  //DECLARAÇÃO DE VARiaveis
  double raio, volumeEsfera, pi = 3.14159;
  
  //leia o valor de raio
  printf("digite o valor do raio: ");
  scanf("%lf", &raio);

  //calcule valor de volume da esfera
  volumeEsfera = ((4.0/3.0) * pi * pow(raio, 3));

  //mostre a saida
  printf("Valor d0o volume da esfera %.2lf\n\n", volumeEsfera);
  return 0;
}