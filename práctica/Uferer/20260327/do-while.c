// Estructura de control do-while en C

do {
    instrucciones;
} while (condicion);

// Ejemplo

#include <stdio.h>

int main() {

    int i = 1;

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);

    return 0;
}