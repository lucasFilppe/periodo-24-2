/*Crie uma função recursiva que receba um número 
inteiro positivo N e calcule o
somatório dos números de 1 a N.*/
#include <stdio.h>

int soamtorio(int n){
  //condição de parada
  if(n == 1){
    return 1;
  }
  else{
    return n + soamtorio(n - 1);
  }
}

int main(){

  int n;
  printf("Digite um numero: ");
  scanf("%d", &n);

  int resultado = soamtorio(n);
  printf("a SOMA DE 1 ate %d = %d\n", n, resultado );
  return 0;
}