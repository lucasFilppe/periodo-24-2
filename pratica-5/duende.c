#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duende {
    char nome[21];
    int idade;
    ESCALADO escalado;
};

struct time {
    char nomeLider[21], nomeConfeiteiro[21], nomeEntregador[21], nomeEmbrulhador[21];
    int idadeLider, idadeConfeiteiro, idadeEntregador, idadeEmbrulhador;
};

void lerQuantidade(int *qtd){
    scanf("%d", qtd); 
}

//complexidade O(n)
Duende *alocaDuendes(int qtd){
    Duende *duendes = (Duende *)malloc(qtd * sizeof(Duende));
    if (duendes == NULL)
    {
        printf("ERRO DE MEMORIA\n");
        return NULL;
    }

    return duendes;
}

//complexidade O(t)
Time *alocaTimes(int qtd){
    Time *times = (Time *)malloc(qtd * sizeof(Time));
    if (times == NULL)
    {
        printf("ERRO DE MEMORIA\n");
        return NULL;
    }

    return times;
}

Duende* desalocaDuendes(Duende *duendes) {
    if (duendes != NULL) {
        free(duendes); 
        duendes = NULL; 
    }
    return duendes;
}

Time* desalocaTimes(Time *times) {
    if (times != NULL) {
        free(times); 
        times = NULL; 
    }
    return times;
}


void lerDuendes(Duende *duendes, int qtd){
    for (int i = 0; i < qtd; i++)
    {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado = NAO;
    }
}

//complexidade O(n)
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes / 4;
    
    // Escalando os lideres
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeLider, duendes[index].nome);
        times[i].idadeLider = duendes[index].idade;
    }
    
    // Escalando os confeiteiros
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeConfeiteiro, duendes[index].nome);
        times[i].idadeConfeiteiro = duendes[index].idade;
    }
    
    // Escalando os entregadores
    for (i = 0; i < qtdTime; i++)
    {
        // Copiar o nome do duende encontrado como entregador de um time
        // Copiar a idade do duende encontrado como entregador de um time
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEntregador, duendes[index].nome);
        times[i].idadeEntregador = duendes[index].idade;
    }
    
    // Escalando os embrulhadores
    for (i = 0; i < qtdTime; i++)
    {
        // Copiar o nome do duende encontrado como embrulhador de um time
        // Copiar a idade do duende encontrado como embrulhador de um time
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEmbrulhador, duendes[index].nome);
        times[i].idadeEmbrulhador = duendes[index].idade;
    }
}

int proximoMaisVelho(Duende *D, int qtd){
    int i;
    int index = -1;          // Inicialmente, nenhum duende é selecionado
    int idadeMaisVelha = -1; // Inicialmente, nenhuma idade é a mais velha

    for (i = 0; i < qtd; i++)
    {
        if (D[i].escalado == NAO && D[i].idade > idadeMaisVelha)
        {
            idadeMaisVelha = D[i].idade;
            index = i;
        }
    }

    return index;
}

void printTimes(Time *times, int qtd){
    for (int i = 0; i < qtd; i++) {
        printf("Time %d\n", i + 1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}
