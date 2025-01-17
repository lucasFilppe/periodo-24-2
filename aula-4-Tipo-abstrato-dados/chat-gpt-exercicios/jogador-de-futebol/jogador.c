#include<stdio.h>
#include<stdlib.h>
#include"jogador.h"
#include <string.h>
#include <stdio.h>

struct jogador {
  char *nome;
  int jogos;
  int gols;
  int assistencias;
};

// Função para criar um jogador
Jogador* Cria_Jogador() {
    char nome[100]; // Tamanho fixo para armazenar o nome temporariamente
    int jogos, gols, assistencias;

    // Aloca memória para a estrutura Jogador
    Jogador *x = (Jogador*)malloc(sizeof(Jogador));
    if (x == NULL) {
        printf("Memória insuficiente.\n");
        exit(1);
    }

    // Lê os valores do usuário
    printf("\n\nDigite o Nome: ");
    scanf("%99s", nome); // Limita a leitura para evitar estouro de buffer
    printf("Digite numero de Jogos: ");
    scanf("%d", &jogos);
    printf("Digite q quantidade de Gols: ");
    scanf("%d", &gols);
    printf("Digite a quantidade de Assistências: ");
    scanf("%d", &assistencias);
    printf("\n");

    // Aloca memória para o nome e copia a string
    x->nome = (char*)malloc(strlen(nome) + 1); // +1 para o caractere nulo
    if (x->nome == NULL) {
        printf("Memória insuficiente para o nome.\n");
        free(x); // Libera a estrutura antes de sair
        exit(1);
    }
    strcpy(x->nome, nome);

    // Inicializa os campos restantes
    x->jogos = jogos;
    x->gols = gols;
    x->assistencias = assistencias;

    return x;
}


void Imprime(Jogador* x){
  printf("ESTATISTICAS DO JOGADOR\n\n");
  printf("Nome: %s\n", x->nome);
  printf("Jogos: %d\n", x->jogos);
  printf("Gols: %d\n", x->gols);
  printf("Assitencias %d\n", x->assistencias);
}

void SomaJogadores(Jogador *x, Jogador *y){
  printf("Gols somados: %d\n", x->gols + y->gols);
  printf("Asiistencias somadas %d\n", x->assistencias + y->assistencias);

}