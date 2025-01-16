#include <stdio.h>

int main(){
  float p1, p2, media = 0, mediaFinal = 0;//declarando variaveis

  //leitura das variaveis
  printf("Digite as notas da prova: ");
  scanf("%f %f",&p1, &p2);

  //calcula a media de p1 e p2
  media = (p1 + p2)/2;
  printf("Media %f\n", media);

  //compara se o aluno pode ser aprovado direto
  //se a media for maior ou igual a 5, e, p1 ou p2 >= 3.0
  if ((media >= 5) && (p1 >= 3 && p2 >= 3))
  {
    printf("Aluno passou direto\n\n");
  }
  else{
    float p3, maior = 0;
    printf("Aluno deve fazer terceira prova\n");
    printf("Digite o valor de p3: ");
    scanf("%f", &p3);

    //verifica qual nota é maior de p1 ou p2
    if(p1 > p2)
      maior = p1;
    else
      maior = p2;

    mediaFinal = (p3 + maior) / 2;//calcula media com p3 e maior nota entre as duas primeiras

    printf("Media final %f\n", mediaFinal);//mostra media fibnal

    //verifica se aluno é aprovado
    if (mediaFinal >= 5)
    {
      printf("Aluno aprovado\n\n");
    }
    else
       printf("Aluno reprovado\n\n");
  }
  


  return 0;
}