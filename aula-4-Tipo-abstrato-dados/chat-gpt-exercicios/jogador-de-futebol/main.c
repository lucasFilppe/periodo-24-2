#include <stdio.h>
#include "jogador.h"
#include <stdlib.h>

int main() {
    Jogador *x = Cria_Jogador(); // Cria o jogador
    Imprime(x); // Imprime as informações do jogador

    Jogador *y = Cria_Jogador();
    Imprime(y);

    SomaJogadores(x, y);

    // Libera a memória
    free(x);

     int qntJogadores = 2;

    // Criação de jogadores
    Jogador jogadores[qntJogadores];

    jogadores[0].nome = strdup("Jogador1");
    jogadores[0].jogos = 10;
    jogadores[0].gols = 5;
    jogadores[0].assistencias = 3;

    jogadores[1].nome = strdup("Jogador2");
    jogadores[1].jogos = 12;
    jogadores[1].gols = 7;
    jogadores[1].assistencias = 4;

    // Criação do time
    TimeFutebol *time = CriandoTime("Time Exemplo", "Treinador Exemplo", 8, 2, 3, jogadores, qntJogadores);

    // Exibição do time
    printf("Detalhes do Time:\n");
    ExibirTime(time, qntJogadores);

    // Liberação de memória
    LiberarTime(time, qntJogadores);
    
    return 0;
}
