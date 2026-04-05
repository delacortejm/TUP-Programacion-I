#include <stdio.h>

int main() {
    float lluvia;
    float total = 0;
    float maximo = 0;
    float minimo = 1000;
    int d_min=0;
    int d_max=0;
    
    printf("Ingrese la cantidad de agua llovida (en mm) para cada dia:\n");
    
    for (int i = 0; i < 7; i++) {
        printf("dia %d: ", i + 1);
        printf("Ingrese la cantidad de agua llovida (en mm) para cada dia:\n");
        scanf("%f", &lluvia);
        total += lluvia;
        if (lluvia>maximo) {
            maximo = lluvia;
            d_max = i+1;
        } else if (lluvia<minimo) {
            minimo = lluvia;
            d_min = i+1;
        }
        else printf("Error: valor repetido");
        }
    
    
    printf("\n--- Resumen semanal ---\n");
    printf("dia con mas lluvia: %d\n", d_max);
    printf("dia con menos lluvia: %d\n", d_min);
    printf("Total de agua llovida: %.2f mm\n", total);
    printf("Promedio diario: %.2f mm\n", total / 7);
    
    return 0;
}