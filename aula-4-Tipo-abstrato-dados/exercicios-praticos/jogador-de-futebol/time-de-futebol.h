#include "jogador.h"

typedef struct timeFutebol TimeFutebol;

TimeFutebol* CriandoTime(char *nome, char *treinador, int vitorias, int derrotas, int empates);
void LiberarTime(TimeFutebol *time);
void ExibirTime(TimeFutebol *time);