/* Tabla de multiplicar de doble entrada de 1 a n */
#include <stdio.h>

int main(void) {
    int n, i, j;

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    printf("    ");
    for (j = 1; j <= 10; j = j + 1) {
        printf("%4d", j);
    }
    printf("\n");

    printf("    ");
    for (j = 1; j <= 10; j = j + 1) {
        printf("----");
    }
    printf("\n");

    for (i = 1; i <= n; i = i + 1) {
        printf("%3d|", i);              
        for (j = 1; j <= 10; j = j + 1) {
            printf("%4d", i * j);       
        }
        printf("\n");                   
    }

    return 0;
}