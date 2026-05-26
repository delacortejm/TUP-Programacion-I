/* Ejercicio 5.4: Rediseno del 4.4 usando while */
#include <stdio.h>

int main(void) {
    int num, i, suma;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("ERROR: el numero debe ser positivo.\n");
    } else {
        suma = 0;
        i = 1;
        while (i < num) {
            if (num % i == 0) {
                suma = suma + i;
            }
            i++;
        }

        if (suma == num) {
            printf("El numero %d ES perfecto\n", num);
        } else {
            printf("El numero %d NO es perfecto (suma de divisores = %d)\n", num, suma);
        }
    }

    return 0;
}