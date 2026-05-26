/* Ejercicio 5.3: El fragmento recorre los digitos de N en base b
   y reconstruye un numero en base 10 con esos digitos.
   Especificacion: dado un numero N y una base b, separar los digitos
   de N en esa base y mostrarlos como un numero decimal. */
#include <stdio.h>
#include <math.h>

int main(void) {
    int N, b, x, s, i;

    printf("Ingrese el numero N: ");
    scanf("%d", &N);
    printf("Ingrese la base b: ");
    scanf("%d", &b);

    s = 0;
    i = 0;

    while (N > 0) {
        x = N % b;
        N = N / b;
        s = s + x * pow(10, i);
        i++;
    }

    printf("Resultado: %d\n", s);

    return 0;
}