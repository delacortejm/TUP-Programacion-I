/* Ejercicio 6.2: Contar numeros < 15, > 50, y entre 25 y 45 */
#include <stdio.h>

int main(void) {
    int n, num, i;
    int c15, c50, c_rango;

    printf("Cuantos numeros va a ingresar? ");
    scanf("%d", &n);

    c15 = 0;
    c50 = 0;
    c_rango = 0;
    i = 1;

    do {
        printf("Ingrese el numero %d: ", i);
        scanf("%d", &num);

        if (num < 15) {
            c15++;
        }
        if (num > 50) {
            c50++;
        }
        if (num > 25 && num < 45) {
            c_rango++;
        }

        i++;
    } while (i <= n);

    printf("\n--- Resultados ---\n");
    printf("Numeros menores a 15: %d\n", c15);
    printf("Numeros mayores a 50: %d\n", c50);
    printf("Numeros entre 25 y 45: %d\n", c_rango);

    return 0;
}