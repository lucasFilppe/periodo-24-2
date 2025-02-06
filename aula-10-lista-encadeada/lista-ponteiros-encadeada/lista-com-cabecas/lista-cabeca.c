#include "lista-cabeca.h"  // Inclui o arquivo de cabeçalho que contém definições necessárias para a lista.
#include <stdlib.h>        // Inclui a biblioteca padrão para funções como malloc e free.

typedef struct {
  // Componentes de um item: "informações"
  // Aqui você pode definir os campos que compõem um item da lista.
} TItem;

typedef struct celula {
  struct celula *pProx;  // Ponteiro para a próxima célula na lista.
  TItem item;            // O item armazenado nesta célula.
} TCelula;

typedef struct {
  TCelula *pPrimeiro;  // Ponteiro para a primeira célula da lista.
  TCelula *pUltimio;   // Ponteiro para a última célula da lista.
} TLista;

// Função para inicializar a lista.
void TLista_Inicia(TLista *pLista) {
  pLista->pPrimeiro = (TCelula*)malloc(sizeof(TCelula));  // Aloca memória para a célula cabeça.
  pLista->pUltimio = pLista->pPrimeiro;                   // Faz o ponteiro do último apontar para a célula cabeça.
  pLista->pPrimeiro->pProx = NULL;                        // Define o próximo da célula cabeça como NULL, indicando que a lista está vazia.
}

// Função para verificar se a lista está vazia.
int TLista_EhVazia(TLista *pLista) {
  return (pLista->pPrimeiro == pLista->pUltimio);  // Retorna 1 se a lista estiver vazia, 0 caso contrário.
}

// Função para inserir um item no final da lista.
int Tlista_Insere(TLista *pLista, TItem x) {
  pLista->pUltimio->pProx = (TCelula*)malloc(sizeof(TCelula));  // Aloca memória para uma nova célula.
  pLista->pUltimio = pLista->pUltimio->pProx;                   // Atualiza o ponteiro do último para a nova célula.
  pLista->pUltimio->item = x;                                   // Armazena o item na nova célula.
  pLista->pUltimio->pProx = NULL;                               // Define o próximo da nova célula como NULL.
  return 1;  // Retorna 1 indicando que a inserção foi bem-sucedida.
}

// Função para retirar o primeiro item da lista.
int TLista_RetiraPrimeiro(TLista *pLista, TItem *px) {
  if (TLista_EhVazia(pLista)) {
    return 0;  // Se a lista estiver vazia, retorna 0 indicando que não há itens para retirar.
  }
  TCelula *pAux;                          // Declara um ponteiro auxiliar para a célula a ser removida.
  pAux = pLista->pPrimeiro->pProx;        // Faz pAux apontar para a primeira célula com dados.
  *px = pAux->item;                       // Armazena o item da célula a ser removida no ponteiro px.
  pLista->pPrimeiro->pProx = pAux->pProx; // Atualiza o ponteiro do próximo da célula cabeça para pular a célula removida.
  free(pAux);                             // Libera a memória da célula removida.
  return 1;  // Retorna 1 indicando que a remoção foi bem-sucedida.
}