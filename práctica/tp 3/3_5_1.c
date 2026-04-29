/* Ejercicio 5.1: Control de limite diario de pesca */
#include <stdio.h>

int main(void) {
    float limite, kg, total;

    printf("Ingrese el limite diario de pesca (kg): ");
    scanf("%f", &limite);

    total = 0;
    while (total <= limite) {
        printf("Ingrese los kg pescados: ");
        scanf("%f", &kg);
        total = total + kg;
        printf("Total acumulado: %.2f kg\n", total);
    }

    printf("\n** LIMITE SUPERADO **\n");
    printf("Excedio el limite en %.2f kg\n", total - limite);

    return 0;
}