/* Ejercicio 4.4: Numero perfecto = suma de sus divisores propios.
   Ejemplo: 6 = 1 + 2 + 3 */
#include <stdio.h>

int main(void) {
    int num, i, suma;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("ERROR: el numero debe ser positivo.\n");
    } else {
        suma = 0;
        for (i = 1; i < num; i++) {
            if (num % i == 0) {
                suma = suma + i;
            }
        }

        if (suma == num) {
            printf("El numero %d ES perfecto\n", num);
        } else {
            printf("El numero %d NO es perfecto (suma de divisores = %d)\n", num, suma);
        }
    }

    return 0;
}