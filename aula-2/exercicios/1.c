/*Implemente o jogo conhecido pedra, papel, tesoura. Neste jogo, o usuário e o
computador escolhem entre pedra, papel ou tesoura. Sabendo que pedra ganha de
tesoura, papel ganha de pedra e tesoura ganha de papel, exiba na tela o ganhador de
cinco rodadas (melhor de cinco): usuário ou computador. Para essa implementação,
assuma que o número 0 representa a pedra, 1 representa papel e 2 representa tesoura.
Observação: seu algoritmo deve ser honesto: a escolha feita pelo computador não
pode ser realizada baseada na escolha do usuário e vice-versa. Dica: reutilizar funções
para gerar números aleatórios num intervalo pré-definido.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um número aleatório entre dois valores (inclusive)
int gerarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Função para determinar o vencedor de uma rodada
int determinarVencedor(int escolhaUsuario, int escolhaComputador) {
    if (escolhaUsuario == escolhaComputador) {
        return 0; // Empate
    } else if ((escolhaUsuario == 0 && escolhaComputador == 2) || 
               (escolhaUsuario == 1 && escolhaComputador == 0) || 
               (escolhaUsuario == 2 && escolhaComputador == 1)) {
        return 1; // Usuário vence
    } else {
        return -1; // Computador vence
    }
}

// Função para exibir a escolha como string
void exibirEscolha(int escolha) {
    if (escolha == 0) {
        printf("Pedra");
    } else if (escolha == 1) {
        printf("Papel");
    } else if (escolha == 2) {
        printf("Tesoura");
    }
}

int main() {
    int pontosUsuario = 0, pontosComputador = 0;
    int rodadas = 0;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("Bem-vindo ao jogo Pedra, Papel, Tesoura!\n");
    printf("Primeiro a vencer 3 rodadas ganha o jogo.\n\n");

    while (pontosUsuario < 3 && pontosComputador < 3) {
        int escolhaUsuario, escolhaComputador;

        // Escolha do usuário
        printf("Escolha sua jogada (0 - Pedra, 1 - Papel, 2 - Tesoura): ");
        scanf("%d", &escolhaUsuario);

        if (escolhaUsuario < 0 || escolhaUsuario > 2) {
            printf("Escolha inválida! Tente novamente.\n");
            continue;
        }

        // Escolha do computador
        escolhaComputador = gerarNumeroAleatorio(0, 2);

        // Exibe escolhas
        printf("Você escolheu: ");
        exibirEscolha(escolhaUsuario);
        printf("\nComputador escolheu: ");
        exibirEscolha(escolhaComputador);
        printf("\n");

        // Determina vencedor da rodada
        int resultado = determinarVencedor(escolhaUsuario, escolhaComputador);

        if (resultado == 1) {
            printf("Você venceu esta rodada!\n");
            pontosUsuario++;
        } else if (resultado == -1) {
            printf("Computador venceu esta rodada!\n");
            pontosComputador++;
        } else {
            printf("Empate nesta rodada!\n");
        }

        printf("Placar: Você %d x %d Computador\n\n", pontosUsuario, pontosComputador);
        rodadas++;
    }

    // Exibe o vencedor final
    if (pontosUsuario > pontosComputador) {
        printf("Parabéns! Você venceu o jogo em %d rodadas!\n", rodadas);
    } else {
        printf("Computador venceu o jogo em %d rodadas. Boa sorte na próxima vez!\n", rodadas);
    }

    return 0;
}
