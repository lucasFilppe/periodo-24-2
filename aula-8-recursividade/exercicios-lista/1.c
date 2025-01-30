/*3) Faça uma função recursiva que permita inverter um 
número inteiro N. Ex: 123 - 321*/
#include <stdio.h>

//função recursiva para inverter numero
int inverteNumero(int n, int invertido){
  if(n == 0)
    return invertido;
  else{
    return inverteNumero(n / 10, invertido * 10 + n % 10);
  }
}

int main(){

  int numero;

  scanf("%d", &numero);

  int numeroInvertido = inverteNumero(numero, 0);
  printf("Numero invertido = %d\n", numeroInvertido);
  return 0;
}
