/*I Crie uma função recursiva que calcula a média de um vetor.

     //Qual a condição de parada?
A função somaVetor para quando n == 1, pois nesse caso a 
soma é apenas o primeiro elemento do vetor.*/

//Qual a complexidade de sua função? Apresente a 
/*A complexidade da função é O(n), pois percorre todos 
os elementos do vetor recursivamente.*/

//equação de recorrência e resolva-a.*/
  /*A função somaVetor(n) chama somaVetor(n-1), 
  somando um elemento por vez:
  T(n)=T(n−1)+O(1)
  T(n−1)=T(n−2)+O(1)
  T(n−2)=T(n−3)+O(1)
  Continuando até T(1) = O(1), obtemos:
  T(n)=O(n)+O(n−1)+O(n−2)+⋯+O(1)=O(n)

*/

#include <stdio.h>

double somaVetor(double *vetor, int tamanho){
  //caso base: se tamanho for igua a zero, retorne 1
  if(tamanho == 0){
    return 1;
  }
    return vetor[tamanho] + somaVetor(vetor, tamanho - 1);
}

double mediaVetor(double *v, int n){
  return somaVetor(v, n) / n;
}

int main(){

  
  int n;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  double v[n];

  printf("Digite os elementos do vetor: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &v[i]);
  }
  
  double resultado = somaVetor(v, n);

  printf("Soam do vetor = %.2lf", resultado);
  printf("media do vetor = %.2lf", mediaVetor(v, n));
  
  return 0;
}