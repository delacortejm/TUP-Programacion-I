/* Ejercicio 1.3: Indicar si un numero es divisible por 3 */
#include <stdio.h>

int main(void) {
    int num;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    if (num % 3 == 0) {
        printf("El numero %d ES divisible por 3\n", num);
    } else {
        printf("El numero %d NO es divisible por 3\n", num);
    }

    return 0;
}