//ponteiros

#include <stdio.h>

int main(){

  int a = 5; // a recebi 5
  int *p; //declarando uma variavel do tipo ponteiro que aponta para um inteiro
  p = &a; // p recebi o endereço de a

  printf("a = %d\n", a);//mosta o valor de a
  printf("p = %p\n", p); //mosta o0 endereço de p
  printf("p = %d\n", *p);//mostra o valor de p

  *p = 8;// o conteudo de p recebi 8
  
   printf("a = %d\n", a);//mosta o valor de a
  printf("p = %p\n", p); //mosta o0 endereço de p
  printf("p = %d\n", *p);//mostra o valor de p

  
  return 0;
}