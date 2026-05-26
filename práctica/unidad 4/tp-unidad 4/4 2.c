
#include <stdio.h>

#define N 6

int mcd(int a, int b);

int main(void)
{
    int d50[N] = {1, 2, 5, 10, 25, 50};
    int tabla[N][N];
    int i, j;

    /* Generar tabla */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tabla[i][j] = mcd(d50[i], d50[j]);

    /* Mostrar encabezado */
    printf("m.c.d |");
    for (j = 0; j < N; j++)
        printf("%5d", d50[j]);
    printf("\n------+------------------------------\n");

    /* Mostrar filas */
    for (i = 0; i < N; i++)
    {
        printf("%5d |", d50[i]);
        for (j = 0; j < N; j++)
            printf("%5d", tabla[i][j]);
        printf("\n");
    }

    return 0;
}

/* Calcula el maximo comun divisor con algoritmo de Euclides */
int mcd(int a, int b)
{
    int resto;
    while (b != 0)
    {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}