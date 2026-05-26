
#include <stdio.h>

#define N 10

void ordenar(int lista[], int tam);
int buscarBinario(int lista[], int tam, int num);
void mostrarArreglo(int lista[], int tam, char nombre[]);

int main(void)
{
    
    int A[N] = {15, 3, 22, 8, 41, 17, 6, 30, 11, 25};
    int B[N];
    int C[N];
    int D[N * 2];
    int tamD = 0;
    int i, j, num, encontrado, repetido;

    /* Cargar B por teclado */
    printf("Ingrese los 10 elementos del arreglo B:\n");
    for (i = 0; i < N; i++)
    {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    /* Generar C = A + B */
    for (i = 0; i < N; i++)
        C[i] = A[i] + B[i];

    /* Ordenar A y B de mayor a menor */
    ordenar(A, N);
    ordenar(B, N);

    /* Generar D: combinar A y B sin repetidos */
    for (i = 0; i < N; i++)
    {
        repetido = 0;
        for (j = 0; j < tamD; j++)
            if (D[j] == A[i])
                repetido = 1;
        if (!repetido)
        {
            D[tamD] = A[i];
            tamD++;
        }
    }
    for (i = 0; i < N; i++)
    {
        repetido = 0;
        for (j = 0; j < tamD; j++)
            if (D[j] == B[i])
                repetido = 1;
        if (!repetido)
        {
            D[tamD] = B[i];
            tamD++;
        }
    }
    /* Ordenar D de mayor a menor */
    ordenar(D, tamD);

    /* Mostrar arreglos */
    mostrarArreglo(A, N, "A (ordenado mayor a menor)");
    mostrarArreglo(B, N, "B (ordenado mayor a menor)");
    mostrarArreglo(C, N, "C (suma A+B)");
    mostrarArreglo(D, tamD, "D (A+B sin repetidos, mayor a menor)");

    /* Busqueda binaria en D */
    printf("\nIngrese un numero a buscar en D: ");
    scanf("%d", &num);

    encontrado = buscarBinario(D, tamD, num);

    if (encontrado)
        printf("El numero %d fue encontrado en D.\n", num);
    else
        printf("El numero %d NO esta en D.\n", num);

    return 0;
}

/* Ordena de mayor a menor con burbuja */
void ordenar(int lista[], int tam)
{
    int i, j, t;
    for (i = 0; i < tam; i++)
        for (j = tam - 1; j >= i; j--)
            if (lista[j] > lista[j + 1])
            {
                t = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = t;
            }
}

/* Busqueda binaria en arreglo ordenado de mayor a menor. Retorna 1 o 0 */
int buscarBinario(int lista[], int tam, int num)
{
    int inicio = 0, final = tam - 1, medio = 0;

    while (inicio <= final && num != lista[medio])
    {
        medio = (inicio + final) / 2;
        if (num < lista[medio])   /* D esta de mayor a menor */
            inicio = medio + 1;
        else
            final = medio - 1;
    }

    if (num == lista[medio])
        return 1;
    else
        return 0;
}

/* Muestra un arreglo con su nombre */
void mostrarArreglo(int lista[], int tam, char nombre[])
{
    int i;
    printf("\nArreglo %s:\n", nombre);
    for (i = 0; i < tam; i++)
        printf("[%d]=%d  ", i, lista[i]);
    printf("\n");
}