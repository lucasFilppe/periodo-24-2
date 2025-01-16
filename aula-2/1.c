//incremento e decremento

#include <stdio.h>

int main(){

  int n = 5;
  int x = n++;

  printf("Valor de n = %d\n", n);
  printf("Valor de x = %d\n", x);

  x = ++n;
  printf("Valor de x = %d\n", x);
  return 0;
}