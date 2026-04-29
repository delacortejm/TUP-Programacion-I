/* Ejercicio 4.3: Imprimir el triangulo:
   1 2 3 4 5 6 7 8 9 10
   1 2 3 4 5 6 7 8 9
   ...
   1 2
   1                                                           */
#include <stdio.h>

int main(void) {
    int fila, col;

    for (fila = 10; fila >= 1; fila--) {
        for (col = 1; col <= fila; col++) {
            printf("%d ", col);
        }
        printf("\n");
    }

    return 0;
}