#include <stdio.h>
#define N 5

int main(void)
{
    int notas[N];
    int i, max, min;
    float promedio, acum;

    /* Carga con validacion */
    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Ingrese nota %d (0-10): ", i + 1);
            scanf("%d", &notas[i]);
            if (notas[i] < 0 || notas[i] > 10)
                printf("Nota fuera de rango. Intente de nuevo.\n");
        } while (notas[i] < 0 || notas[i] > 10);
    }

    /* Calcular promedio, max y min */
    acum = 0;
    max = notas[0];
    min = notas[0];

    for (i = 0; i < N; i++)
    {
        acum += notas[i];
        if (notas[i] > max) max = notas[i];
        if (notas[i] < min) min = notas[i];
    }

    promedio = acum / N;

    /* Mostrar resultados */
    printf("\nNotas ingresadas:\n");
    for (i = 0; i < N; i++)
        printf("  Nota %d: %d\n", i + 1, notas[i]);

    printf("\nPromedio : %.2f\n", promedio);
    printf("Mas alta : %d\n", max);
    printf("Mas baja : %d\n", min);

    return 0;
}