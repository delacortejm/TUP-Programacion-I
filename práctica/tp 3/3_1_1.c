/* Ejercicio 1.1: Indicar si un numero es par o impar */
#include <stdio.h>

int main(void) {
    int num;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("El numero %d es PAR\n", num);
    } else {
        printf("El numero %d es IMPAR\n", num);
    }

    return 0;
}