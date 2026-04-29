/*implementar el algoritmo de euclides que encuentra el max comun divisor de dos numeros enteros positivos*/

#include <stdio.h>
int main(void) {
    int m, n, temp;

    printf("Ingrese el primer numero entero positivo: ");
    scanf("%d", &m);

    printf("Ingrese el segundo numero entero positivo: ");
    scanf("%d", &n);

    while (n != 0) {
        temp = n;
        n = m % n; // El nuevo valor de n es el residuo de m dividido por n
        m = temp;  // El nuevo valor de m es el antiguo valor de n
    }

    printf("El maximo comun divisor es: %d\n", m);

    return 0;
}