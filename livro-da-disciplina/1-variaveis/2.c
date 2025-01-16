#include <stdio.h>

int main(){

  float galaoGasolinaDolares, taxaDeConversao, gasolinaLitroBrasil;

  //lendo preçod a gasolina nos estados unidos e o valor da taxa de conversão
  printf("Digite o valor do galao de gasolina nos EUA, em dolares: ");
  scanf("%f", &galaoGasolinaDolares);
  printf("Digite o valor da taxa de conversao do dolar para o real: ");
  scanf("%f", &taxaDeConversao);

  //calcula preço de gasolina por litro no Brasil

  gasolinaLitroBrasil = galaoGasolinaDolares * taxaDeConversao;

  printf("Valor do preco da gasolina no brasil em reais: %f\n\n", gasolinaLitroBrasil);

  return 0;
}