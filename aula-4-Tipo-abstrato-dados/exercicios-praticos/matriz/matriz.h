/*Tad matriz m por n*/
#ifndef MATRIZ_H
#define MATRIZ_H

// Definição da estrutura Matriz
typedef struct matriz {
    int lin;      // Número de linhas
    int col;      // Número de colunas
    float** M;    // Ponteiro para a matriz (array de ponteiros para linhas)
} Matriz;


//operação que cria matriz de dimensao m por n
Matriz* Cria_Matriz(int m, int n);

//operação que libera memoria alocada para matriz
void Libera_Matriz(Matriz* mat);

//operação que acessa elemento da linha i e da coluna j da matriz
float Acessa_Matriz(Matriz* mat, int i, int j);

//atribui elemento da matriz
void Atribui_Matriz(Matriz* mat, int i, int j, float valor);

//retorna numero de linhas da matriz
int Linhas_Matriz(Matriz* mat);

//retorna numero de colunas da matriz
int Colunas_Matriz(Matriz* mat);

#endif