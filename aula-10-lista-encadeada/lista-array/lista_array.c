#include "lista_array.h"
#include <stdio.h>

void ListaInicia(Lista *pLista)
{
  pLista->primeiro = INICIO;
  pLista->ultimo = pLista->primeiro;
}

int ListaEhVazia(Lista *pLista)
{
  if (pLista == NULL)
  {
    printf("Erro: Ponteiro para lista inválido.\n");
    return -1; // Retorno inválido para indicar erro
  }
  return (pLista->ultimo == pLista->primeiro);
}

int ListaInsere(Lista *pLista, Item x){
  if(pLista->ultimo == MAXTAM){
    return 0; //lista cheia
  }
  pLista->item[pLista->ultimo++] = x;
  return 1;
}

void ListaImprime(Lista *pLista){
  int i;

  for ( i = pLista->primeiro; i < pLista->ultimo; i++)
  {
    printf("%d\n", pLista->item[i].matricula);
    printf("%s\n", pLista->item[i].nome);
    printf("\n");
  }
  
}

/*Objetivo: Desloca os elementos após a posição p para a esquerda, 
preenchendo o espaço deixado pelo elemento removido.
Funcionamento:O loop percorre os elementos da posição p + 1 até ultimo.
Cada elemento é copiado para a posição anterior (cont - 1), sobrescrevendo o 
elemento removido.Isso garante que não haja "buracos" no array.*/

int ListaRetira(Lista *pLista, int p, Item *px){
  //VERIFICA se remoção é possivel
  if(ListaEhVazia(pLista) || p>= pLista->ultimo){
    return 0;
  }

  *px = pLista->item[p];//salva elemento que serA REMOVIDO
  pLista->ultimo--;//atualiza o indice ultimo para refletir a remoção, aggora tem um elementoo a menos

  //desaloca os elementos apos a posição p, para a esquerda
  //preenchendo o espaço do item removido
  int cont;
  for (cont = p + 1;cont <= pLista->ultimo; cont++){
    pLista->item[cont-1] = pLista->item[cont];
  }

  return 1;
}

int ListaConcatena(Lista *pLista1, Lista *pLista2) {
    // Verifica se há espaço suficiente em pLista1 para acomodar os elementos de pLista2
    int espacoLivre = MAXTAM - pLista1->ultimo;
    int elementosParaAdicionar = pLista2->ultimo - pLista2->primeiro;

    if (elementosParaAdicionar > espacoLivre) {
        printf("Erro: Não há espaço suficiente para concatenar as listas.\n");
        return 0; // Falha
    }

    // Copia os elementos de pLista2 para pLista1
    for (int i = pLista2->primeiro; i < pLista2->ultimo; i++) {
        pLista1->item[pLista1->ultimo] = pLista2->item[i];
        pLista1->ultimo++;
    }

    return 1; // Sucesso
}