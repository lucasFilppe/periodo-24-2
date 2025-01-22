#include <stdio.h>
#include "jogador.h"
#include <stdlib.h>
#include "time-de-futebol.h"

int main()
{
    // Jogador *x = Cria_Jogador(); // Cria o jogador
    // Imprime(x); // Imprime as informações do jogador

    // Jogador *y = Cria_Jogador();
    // Imprime(y);

    // SomaJogadores(x, y);

    // Libera a memória
    // free(x);

    TimeFutebol *cruzeiro = CriandoTime("Cruzeiro", "Diniz", 14, 10, 14);

    ExibirTime(cruzeiro);
    LiberarTime(cruzeiro);

    return 0;
}
