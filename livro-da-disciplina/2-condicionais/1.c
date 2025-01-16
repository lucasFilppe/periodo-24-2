#include <stdio.h>

int main(){

  int num1, num2, num3;
  int maior = 0;

  //leia os numeros
  printf("Digite os numeros: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  if(num1 > num2 && num1 > num3)
    maior = num1;
  else if(num2 > num1 && num2 > num3)
    maior = num2;
  else
    maior = num3;

  printf("O maior e: %d\n\n", maior);
  return 0;
}