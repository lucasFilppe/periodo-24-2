#include <stdio.h>
#include <string.h> // Para usar strcmp e strcpy
#include "hash.h"   // Incluir o arquivo de cabeçalho da Tabela Hash

int main() {
    Hash hash;
    Chave chave;
    int n; // Quantidade de casos de teste

    // Ler a quantidade de casos de teste
    scanf("%d", &n);

    while (n-- > 0) {
        int m; // Tamanho da Tabela Hash
        int p; // Tamanho do vetor de pesos
        int s; // Quantidade de chaves

        // Lendo tamanho da tabela e quantidade de pesos
        scanf("%d %d", &m, &p);

        // Iniciar Hash
        inicia(&hash, m, p);

        // Lendo pesos
        for (int i = 0; i < p; i++) {
            scanf("%d", &hash.pesos[i]);
        }

        // Lendo quantidade de chaves
        scanf("%d", &s);

        int ultima_posicao = -1; // Armazenar a posição do último item inserido

        // Lendo chaves
        for (int i = 0; i < s; i++) {
            scanf("%s", chave);

            // Verificar se a chave já existe na Tabela Hash
            int posicao = H(&hash, chave); // Usar a função H
            int tentativas = 0;

            while (strcmp(hash.chaves[posicao], "") != 0 && strcmp(hash.chaves[posicao], chave) != 0) {
                // Colisão: aplicar sondagem linear (próximo índice)
                tentativas++;
                posicao = (posicao + tentativas) % m;

                // Se todas as posições foram verificadas, sair do loop
                if (tentativas >= m) {
                    break;
                }
            }

            if (strcmp(hash.chaves[posicao], chave) == 0) {
                // Chave repetida encontrada
                ultima_posicao = -1;
                break;
            } else {
                // Inserir a chave na posição encontrada
                strcpy(hash.chaves[posicao], chave);
                ultima_posicao = posicao;
            }
        }

        // Imprimir a posição do último item inserido ou -1 se houve chave repetida
        printf("%d\n", ultima_posicao);

        // Liberar Hash
        libera(&hash);
    }

    return 0;
}