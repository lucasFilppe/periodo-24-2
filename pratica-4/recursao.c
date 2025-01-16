#include "recursao.h"

// Função para calcular o resto da divisão (mod) recursivamente
int mod(int x, int y) {
    if (x == y) {
        return 0;
    }
    if (x < y) {
        return x;
    }
    return mod(x - y, y);
}

// Função para calcular o MDC (Máximo Divisor Comum) recursivamente
int mdc(int x, int y) {
    if (y == 0) {
        return x;
    }
    return mdc(y, mod(x, y));
}

// Função recursiva para calcular o MMC (Mínimo Múltiplo Comum) de 3 números
int mmcRec(int x, int y, int z) {
    if (mod(z, x) == 0 && mod(z, y) == 0) {
        return z;
    }
    return mmcRec(x, y, z + (x > y ? x : y));
}

// Função para calcular o MMC entre dois números x e y, e usa o mmcRec para calcular o MMC entre os 3 números
int mmc(int x, int y) {
    return mmcRec(x, y, (x > y ? x : y));
}

