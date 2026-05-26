#include <stdio.h>

int main() {
    int numeros[5];
    int i;

    for (i = 0; i < 5; i = i + 1) {
        printf("Ingresa un numero: ");
        scanf("%d", &numeros[i]);
    }

    printf("\nValores guardados:\n");

    for (i = 0; i < 5; i = i + 1) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }

    return 0;
}