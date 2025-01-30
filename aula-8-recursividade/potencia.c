/*I Crie uma função recursiva que calcula a potência de um número*/
#include <stdio.h>

int potencia(int base, int expoente){
  //caso base = qualquer numero elabado a zero é 1
  if (expoente == 0)
  {
    return 1;
  }
  return base * potencia(base, expoente - 1);
  
}
int main(){

  int b, e;
  scanf("%d %d", &b, &e);

  int resultado = potencia(b, e);
  printf("%d elevado a %d = %d\n", b, e, resultado);
  return 0;
}