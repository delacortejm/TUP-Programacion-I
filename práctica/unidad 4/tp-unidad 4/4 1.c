#include <stdio.h>
 
#define N 3
 
void mostrarMatriz(int m[N][N]);
int estaRepetido(int m[N][N], int fila, int col, int val);
 
int main(void)
{
    int m[N][N];
    int i, j, val;
    int max, min, fmax, cmax, fmin, cmin;
    int diag[N * 2];
    int tamDiag = 0;
 
    /* Carga sin repetidos */
    printf("Ingrese los 9 elementos de la matriz 3x3 (sin repetidos):\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            do
            {
                printf("m[%d][%d]: ", i, j);
                scanf("%d", &val);
                if (estaRepetido(m, i, j, val))
                    printf("Numero repetido, ingrese otro.\n");
            } while (estaRepetido(m, i, j, val));
            m[i][j] = val;
        }
 
    /* Mostrar matriz */
    printf("\nMatriz A:\n");
    mostrarMatriz(m);
 
    /* Buscar maximo y minimo */
    max = m[0][0]; fmax = 0; cmax = 0;
    min = m[0][0]; fmin = 0; cmin = 0;
 
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (m[i][j] > max) { max = m[i][j]; fmax = i; cmax = j; }
            if (m[i][j] < min) { min = m[i][j]; fmin = i; cmin = j; }
        }
 
    printf("\nMaximo: %d en posicion [%d][%d]\n", max, fmax, cmax);
    printf("Minimo: %d en posicion [%d][%d]\n", min, fmin, cmin);
 
    /* Diagonal principal: m[i][i] */
    /* Diagonal secundaria: m[i][N-1-i] */
    /* Se agregan sin repetir el centro si N es impar */
    printf("\nDiagonal principal: ");
    for (i = 0; i < N; i++)
    {
        diag[tamDiag++] = m[i][i];
        printf("%d ", m[i][i]);
    }
 
    printf("\nDiagonal secundaria: ");
    for (i = 0; i < N; i++)
    {
        /* Evitar agregar el centro dos veces */
        if (i != N - 1 - i)
        {
            diag[tamDiag++] = m[i][N - 1 - i];
            printf("%d ", m[i][N - 1 - i]);
        }
        else
            printf("(%d-ya incluido) ", m[i][N - 1 - i]);
    }
 
    printf("\n\nArreglo con ambas diagonales: ");
    for (i = 0; i < tamDiag; i++)
        printf("%d ", diag[i]);
    printf("\n");
 
    return 0;
}
 
/* Muestra la matriz con formato */
void mostrarMatriz(int m[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("| ");
        for (j = 0; j < N; j++)
            printf("%4d ", m[i][j]);
        printf("|\n");
    }
}
 
/* Verifica si val ya existe en la matriz hasta la posicion actual */
int estaRepetido(int m[N][N], int fila, int col, int val)
{
    int i, j;
    for (i = 0; i <= fila; i++)
        for (j = 0; j < N; j++)
        {
            if (i == fila && j == col) return 0;
            if (m[i][j] == val) return 1;
        }
    return 0;
}