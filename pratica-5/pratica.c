#include <stdio.h>
#include "duende.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);                // Lê a quantidade de duendes
    qtdTimes = qtdDuendes / 4;                  // Calcula a quantidade de times
    duendes = alocaDuendes(qtdDuendes);         // Aloca memória para os duendes
    times = alocaTimes(qtdTimes);               // Aloca memória para os times
    lerDuendes(duendes, qtdDuendes);            // le os dados dos duendes
    escalarTimes(duendes, times, qtdDuendes);   // Escala os times
    printTimes(times, qtdTimes);                // Imprime os times
    desalocaDuendes(duendes);                   // Desaloca memória dos duendes
    desalocaTimes(times);                       // Desaloca memória dos times

    return 0; //não remova
}
