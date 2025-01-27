#include <stdio.h>

//função que retorna maior numero
int Maior(int *v, int n){
  int temp;
  temp = v[0];

  for (int i = 1; i < n; i++)
  {
      if(v[i] >= temp)//comparaçao envolvendo os elementos
        temp = v[i];
  }
  return temp;
}

/* Se v contiver n elementos a função de complecidade será; f(n) = n - 1 comparações*/
int main(){
  int vetor[5] = {1, 32, 346, 342, 341};

  printf("Maior elemento do vetor = %d\n", Maior(vetor, 5));
}
