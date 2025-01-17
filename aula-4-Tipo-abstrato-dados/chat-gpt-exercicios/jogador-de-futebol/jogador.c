#include<stdio.h>
#include<stdlib.h>
#include"jogador.h"
#include <string.h>

struct jogador {
  char nome[50];
  int jogos;
  int gols;
  int assistencias;
};

Jogador* Cria_Jogador(char *nome, int jogos, int gols, int assistencias){
  //cria jogador na memoria
  Jogador* x = (Jogador*)malloc(sizeof(Jogador));

  jogador->nome = 
}