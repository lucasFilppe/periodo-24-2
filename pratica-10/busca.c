#include "busca.h"

#include <stdio.h>
#include <stdlib.h>

int* aloca(int n) {
    return (int*)malloc(n * sizeof(int));
}

void desaloca(int** arr) {
    free(*arr);
    *arr = NULL;
}

void le(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int buscaSequencial(int* arr, int n, int x) {
    int comparacoes = 0;
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (arr[i] == x) {
            break;
        }
    }
    return comparacoes;
}

int buscaBinaria(int* arr, int n, int x) {
    int comparacoes = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        comparacoes++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return comparacoes;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return comparacoes;
}


void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

