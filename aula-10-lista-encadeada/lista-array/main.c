#include <stdlib.h>
#include <stdio.h>
#include "lista_array.h"

int main()
{
  Lista list;
  ListaInicia(&list); // Inicializa a lista

  //verificando se lista esta vazia
  int status = ListaEhVazia(&list);
  if (status == 1)
  {
    printf("A lista está vazia.\n");
  }
  else if (status == 0)
  {
    printf("A lista não está vazia.\n");
  }
  else
  {
    printf("Erro: Lista inválida.\n");
  }

  Item aluno1 = {182, "Alessandro"};
  Item aluno2 = {201, "Lucas"};
  Item aluno3 = {221, "Guilherme"};


  Lista list2;
  ListaInicia(&list2);
  Item aluno4 = {241, "Willian"};
  Item aluno5 = {241, "Joao"};

  
  

  //verifica se alunos foi adicionado a lista de itens
  if(ListaInsere(&list, aluno1)==1 && ListaInsere(&list, aluno2)==1 && ListaInsere(&list, aluno3)==1) {
    printf("Alunos adicionado com sucesso\n");
  }

  if (ListaInsere(&list2, aluno4) == 1 && ListaInsere(&list2, aluno5) == 1)
  {
    printf("Alunos adicionado com sucesso\n");
  }
  

  printf("Lista 1: \n");
  ListaImprime(&list);

  ListaRetira(&list, 1, &aluno2);
  printf("Removendo elemento da lista 1\n");
  ListaImprime(&list);

  printf("Linta 2: \n");
  ListaImprime(&list2);

  printf("Concatenando lista 1 com lista 2\n");
  ListaConcatena(&list, &list2);
  ListaImprime(&list);  

  return 0;
}
