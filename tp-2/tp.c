#include <stdio.h>
#include <stdlib.h>
#include "domino.h"

int main() {
    int num_testes = 0; // Contador de testes

    while (1) {
        int num_pecas;
        scanf("%d", &num_pecas);

        // Verifica se o número de peças é 0
        if (num_pecas == 0) {
            return -1;
            break; // Encerra o loop
        }

        num_testes++; // Incrementa o contador de testes
        Domino *d = DominoCria();
        if (d == NULL) {
            printf("Erro ao criar o dominó.\n");
            return 1;
        }

        // Lê as peças
        for (int i = 0; i < num_pecas; i++) {
            int l1, l2;
            scanf("%d %d", &l1, &l2);
            DominoAdicionaPeca(d, l1, l2);
        }

        printf("Test %d:\n", num_testes);

        // Verifica se é possível organizar as peças
        Peca sequencia[num_pecas];
        if (DominoEhPossivelOrganizar(d, sequencia
        )) {
            printf("YES\n");
            // Imprime a sequência válida
            for (int i = 0; i < num_pecas; i++) {
                printf("%d%d", sequencia[i].lado1, sequencia[i].lado2);
                if (i < num_pecas - 1) printf("|");
            }
            printf("\n\n");
        } else {
            printf("NO\n\n");
        }

        DominoDestroi(d); // Libera a memória do dominó
    }

    return 0;
}