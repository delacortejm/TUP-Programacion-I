/* Ejercicio 2.3: Leer tres enteros positivos distintos e imprimir el mayor */
#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("ERROR: los tres numeros deben ser positivos.\n");
    } else {
        if (a == b || a == c || b == c) {
            printf("ERROR: los tres numeros deben ser distintos.\n");
        } else {
            if (a > b && a > c) {
                printf("El mayor es: %d\n", a);
            } else {
                if (b > c) {
                    printf("El mayor es: %d\n", b);
                } else {
                    printf("El mayor es: %d\n", c);
                }
            }
        }
    }

    return 0;
}