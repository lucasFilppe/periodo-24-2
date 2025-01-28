#include <stdio.h>

//função que retorna fatorial de um numero
int fatorial(int n){
  //condição de parada
  if(n <= 1 ){
    return 1; 
  }

  return (n * fatorial(n-1));
}

int main(){

  int f;
  int n = 5;
  f = fatorial(n);

  printf("%d! = %d\n", n, f);
  return 0;
}
