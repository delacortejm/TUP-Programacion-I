#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, u;

    srand(time(0));
    n = (rand() % 10) + 1;

    do {
        printf("Ingresa un numero entre 1 y 10: ");
        scanf("%d", &u);

        if (u < n) {
            printf("El numero es mas grande\n");
        } else if (u > n) {
            printf("El numero es mas chico\n");
        }

    } while (u != n);

    printf("Adivinaste! El numero era %d\n", n);

    return 0;
}