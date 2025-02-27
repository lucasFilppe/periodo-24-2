#ifndef BUSCA_H
#define BUSCA_H

int* aloca(int);
void desaloca(int**);
void le(int*, int);
int buscaSequencial(int*, int, int);
int buscaBinaria(int*, int, int);
// Implementação da ordenação (quicksort)
void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

#endif // BUSCA_H