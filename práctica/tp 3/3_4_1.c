/* Ejercicio 4.1: Mostrar todos los anios cumplidos desde 1 hasta la edad */
#include <stdio.h>

int main(void) {
    int edad, i;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    if (edad <= 0) {
        printf("ERROR: la edad debe ser positiva.\n");
    } else {
        printf("Anios cumplidos:\n");
        for (i = 1; i <= edad; i++) {
            printf("%d\n", i);
        }
    }

    return 0;
}