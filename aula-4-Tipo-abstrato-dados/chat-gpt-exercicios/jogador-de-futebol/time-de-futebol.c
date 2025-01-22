#include <stdio.h>
#include "time-de-futebol.h"
#include "jogador.h"
#include <stdlib.h>
#include <string.h>

struct timeFutebol
{
  char *nome;
  char *treinador;
  int vitorias;
  int derrotas;
  int empates;
  Jogador **jogadores;
};

TimeFutebol *CriandoTime(char *nome, char *treinador, int vitorias, int derrotas, int empates)
{
  // aloca memoria para a estrutura time de futebol
  TimeFutebol *time = (TimeFutebol *)malloc(sizeof(TimeFutebol));
  if (time == NULL)
  {
    printf("Memoria insuficiente\n\n");
    exit(1);
  }

  // aloca memria para nome do time
  time->nome = (char *)malloc(strlen(nome) + 1);
  if (time->nome == NULL)
  {
    printf("Memoria insuficiente\n");
    exit(1);
  }
  strcpy(time->nome, nome);

  // aloca memoria para nome do treinador
  time->treinador = (char *)malloc(strlen(treinador) + 1);
  if (time->treinador == NULL)
  {
    printf("Memoria insuficiente\n");
    exit(1);
  }
  strcpy(time->treinador, treinador);

  time->vitorias = vitorias;
  time->empates = empates;
  time->derrotas = derrotas;

  // aloca memoria para ponteiro de array de jogadores
  time->jogadores = (Jogador **)malloc(3 * sizeof(Jogador *));

  for (int i = 0; i < 3; i++)
  {
    time->jogadores[i] = Cria_Jogador();
  }

  return time;
}

void ExibirTime(TimeFutebol *time)
{
  if (time == NULL)
  {
    printf("Time inválido.\n");
    return;
  }

  printf("Nome do time: %s\n", time->nome);
  printf("Treinador: %s\n", time->treinador);
  printf("Vitórias: %d\n", time->vitorias);
  printf("Derrotas: %d\n", time->derrotas);
  printf("Empates: %d\n", time->empates);
  for (int i = 0; i < 3; i++)
  {
    Imprime(time->jogadores[i]);
  }
}

void LiberarTime(TimeFutebol *time)
{
  if (time != NULL)
  {
    for (int i = 0; i < 3; i++)
    {
      if (time->jogadores[i] != NULL)
      {
        free(time->jogadores[i]);
      }
    }
    free(time->jogadores);
    free(time->nome);
    free(time->treinador);
    free(time);
  }
}