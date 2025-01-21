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

void ExibirTime(TimeFutebol *time, int qntJogadores) {
    if (time == NULL) {
        printf("Time inválido.\n");
        return;
    }

    printf("Nome do time: %s\n", time->nome);
    printf("Treinador: %s\n", time->treinador);
    printf("Vitórias: %d\n", time->vitorias);
    printf("Derrotas: %d\n", time->derrotas);
    printf("Empates: %d\n", time->empates);

    printf("\nJogadores:\n");
    for (int i = 0; i < qntJogadores; i++) {
        printf("  Nome: %s\n", time->jogadores[i].nome);
        printf("  Jogos: %d\n", time->jogadores[i].jogos);
        printf("  Gols: %d\n", time->jogadores[i].gols);
        printf("  Assistências: %d\n\n", time->jogadores[i].assistencias);
    }
}

void LiberarTime(TimeFutebol *time, int qntJogadores) {
    if (time != NULL) {
        free(time->nome);
        free(time->treinador);

        // Libera a memória de cada jogador (se necessário)
        for (int i = 0; i < qntJogadores; i++) {
            free(time->jogadores[i].nome);
        }

        free(time->jogadores);
        free(time);
    }
}