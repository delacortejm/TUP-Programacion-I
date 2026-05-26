/* Ejercicio 4.2: Mostrar numeros del 32 al 0 */
#include <stdio.h>

int main(void) {
    int i;

    printf("Cuenta regresiva:\n");
    for (i = 32; i >= 0; i--) {
        printf("%d\n", i);
    }

    return 0;
}