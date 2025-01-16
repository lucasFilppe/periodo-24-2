//passagem por referencia

#include <stdio.h>

 /* funcao troca */
 void troca ( int *px , int *py ) {
 int temp ; // declara uma variavel do tipo inteiro;
 temp = *px ;// temp recebi o conteudo de px = 5
 *px = *py ; // conteudo de px agora é o valor de py, px = 7, py = 7;
 *py = temp ; // o conteudo de py recebi temp, py = 5
 //final da execução da função px = 7, py 5
 }

 int main ( void ) {
 int a = 5, b = 7;
 troca (&a , &b) ;
 printf ("%d %d \n", a , b);
 return 0;
}