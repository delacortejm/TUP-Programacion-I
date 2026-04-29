/*encontrar el entero positivo más pequeño (NUM) para el cual la suma 1+2+3+....+NUM <= que el valor de un límite que se ingresa por teclado*//* Encuentra el NUM mas grande tal que 1+2+3+...+NUM <= limite */
#include <stdio.h>

int main(void) {
    int limite, num, suma;

    printf("Ingrese el limite: ");
    scanf("%d", &limite);

    num = 0;
    suma = 0;

    while (suma + (num + 1) <= limite) {
        num = num + 1;
        suma = suma + num;
    }

    printf("El NUM mas grande es: %d\n", num);
    printf("La suma es: %d\n", suma);

    return 0;
}