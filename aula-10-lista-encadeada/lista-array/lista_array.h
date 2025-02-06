#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H

#define INICIO 0
#define MAXTAM 1000

// Definição do Item
typedef struct item
{
    int matricula;
    char nome[50];
} Item;

// Definição da Lista
typedef struct lista
{
    Item item[MAXTAM];
    int primeiro, ultimo;
} Lista;

/* Declaração das funções do TAD */
void ListaInicia(Lista *pLista);
int ListaEhVazia(Lista *pLista);
int ListaInsere(Lista *pLista, Item x);
int ListaRetira(Lista *pLista, int p, Item *px);
void ListaImprime(Lista *pLista);
int ListaConcatena(Lista *pLista1, Lista *pLista2);
int ListaGet(Lista *pLista, int p, Item *pX);
int ListaTamanho(Lista *pLista);

#endif
