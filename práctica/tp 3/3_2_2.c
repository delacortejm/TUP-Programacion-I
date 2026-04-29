/* Ejercicio 2.2: Indicar si un caracter es vocal */
#include <stdio.h>

int main(void) {
    char c;

    printf("Ingrese un caracter: ");
    scanf(" %c", &c);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        printf("El caracter '%c' ES una vocal\n", c);
    } else {
        printf("El caracter '%c' NO es una vocal\n", c);
    }

    return 0;
}