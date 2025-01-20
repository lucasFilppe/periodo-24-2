#include <stdio.h>
#include "time-de-futebol.h"
#include "jogador.h"
#include <stdlib.h>
#include <string.h>

struct timeFutebol{
  char *nome;
  char *treinador;
  int vitorias;
  int derrotas;
  int empates;
  Jogador *jogadores;
};

struct jogador {
  char *nome;
  int jogos;
  int gols;
  int assistencias;
};

TimeFutebol* CriandoTime(char *nome, char *treinador, int vitorias, int derrotas, int empates, Jogador *jogadores, int qntJogadores){
  //aloca memoria para a estrutura time de futebol
  TimeFutebol* time = (TimeFutebol*)malloc(sizeof(TimeFutebol));
  if (time == NULL)
  {
    printf("Memoria insuficiente\n\n");
    exit(1);
  }

  //aloca memria para nome do time
  time->nome = (char*)malloc(strlen(nome) + 1);
  if (time->nome == NULL)
  {
    printf("Memoria insuficiente\n");
    exit(1);
  }
  strcpy(time->nome, nome);

  //aloca memoria para nome do treinador
  time->treinador = (char*)malloc(strlen(treinador) + 1);
  if(time->treinador == NULL){
    printf("Memoria insuficiente\n");
    exit(1);
  }
  strcpy(time->treinador, treinador);

  time->vitorias = vitorias;
  time->empates = empates;
  time->derrotas = derrotas;

  // Aloca memória para os jogadores
    time->jogadores = (Jogador*)malloc(qntJogadores * sizeof(Jogador));
    if (time->jogadores == NULL) {
        printf("Memória insuficiente para jogadores\n");
        free(time);
        exit(1);
    }
    
    //copia os jogadores para a estrutura
    for(int i = 0; i < qntJogadores; i++){
      time->jogadores[i] = jogadores[i];
    }

  return time;
  
}