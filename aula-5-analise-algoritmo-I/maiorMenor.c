#include <stdio.h>

void MaxMin(int *v, int n, int *pMax, int *pMin){
  *pMax = v[0];
  *pMin = v[0];

  for(int i = 1; i < n; i++){
    if(v[i] > *pMax){
      *pMax = v[i];
    }

    //a diferença esta aqui7
    else if(v[i] < *pMin){
      *pMin = v[i]; 
    }
  }
}

int main(){
  int vetor[5] = {1, 32, 346, 342, 341};
  int maior, menor;

  MaxMin(vetor, 5, &maior, &menor);

  printf("Maior elemento do vetor = %d\n", maior);
  printf("Menor elemento do vetor = %d\n", menor);
}
