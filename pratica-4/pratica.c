#include <stdio.h>
#include "recursao.h"

int main() {
    int x, y, z;
    
    // Leitura dos valores de entrada
    scanf("%d %d %d", &x, &y, &z);
    
    // Cálculo do MDC
    int resultado_mdc = mdc(mdc(x, y), z);
    printf("MDC = %d\n", resultado_mdc);
    
    // Cálculo do MMC
    int resultado_mmc = mmc(x, y);
    resultado_mmc = mmc(resultado_mmc, z);
    printf("MMC = %d\n", resultado_mmc);
    
    return 0;
}
