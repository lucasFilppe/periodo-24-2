/*) Faça uma função recursiva que permita somar os elementos de um vetor de
inteiros.*/

#include <stdio.h>

int somaVetor(int vetor[], int tamanho){
  //caso base: quando do vetor é 0, a soma é 0
  if(tamanho == 0){
    return 0;
  }
  
  //caso recursivo: soma o ultimo elemento e chama a função para o 
  //restante do valor
  return vetor[tamanho - 1] + somaVetor(vetor, tamanho - 1);
}

int main(){
  int v[] = {1,2,3,4,5};
  
  int resultado = somaVetor(v, 5);
  printf("A soma dos elementos e %d\n", resultado);

}