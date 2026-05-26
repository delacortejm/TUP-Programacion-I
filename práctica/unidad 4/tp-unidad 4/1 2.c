#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

int main(void)
{
    int vector_numeros[N];
    int i;

    srand(time(NULL));

    /* Inicializar con valores aleatorios del 1 al 10 */
    for (i = 0; i < N; i++)
        vector_numeros[i] = rand() % 10 + 1;

    /* Mostrar tabla */
    printf("%-10s %-10s %-10s\n", "Numero", "Cuadrado", "Cubo");
    printf("------------------------------\n");
    for (i = 0; i < N; i++)
        printf("%-10d %-10.0f %-10.0f\n",
               vector_numeros[i],
               pow(vector_numeros[i], 2),
               pow(vector_numeros[i], 3));

    return 0;
}