/*
realizar los siguientes programas:
-cargar un arreglo de tipo entero de 10 elementos en etapa de definición. Mostrar el contenido del arreglo usando 
la sentencia FOR. Los elementos se deben mostrar uno al lado del otro separados por dos guiones medios.

- al programa anterior agregar la suma de sus elementos. mostrar el resultado. calcular promedio.

- mostrar elementos que son mayores a la mitad del promedio

-ingresar una posicion por teclado e indicar que elemento se encuentra en dicha posicion

- ingresar un valor por teclado e indicar si es un elemento que pertenece al arreglo*/
/*
 * Ejercicio de Repaso - Arreglos
 * Programa: repaso_arreglo.c
 */

#include <stdio.h>

int main() {

    /* Definicion del array */
    int arr[10] = {5, 12, 3, 8, 20, 7, 15, 2, 9, 14};
    int i, suma, pos, val;
    float promedio, mitadPromedio;

    /* Mostrar elementos separados por "--" */
    printf("Contenido del arreglo:\n");
    for (i = 0; i < 10; i++) {
        printf("%d", arr[i]);
        if (i < 9)
            printf("--");
    }
    printf("\n");

    /* 2) Suma y promedio */
    suma = 0;
    for (i = 0; i < 10; i++) {
        suma = suma + arr[i];
    }
    promedio = (float)suma / 10;
    printf("Suma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);

    /* 3) Elementos mayores a la mitad del promedio */
    mitadPromedio = promedio / 2;
    printf("Elementos mayores a la mitad del promedio (%.2f):\n", mitadPromedio);
    for (i = 0; i < 10; i++) {
        if (arr[i] > mitadPromedio)
            printf("%d ", arr[i]);
    }
    printf("\n");

    /* 4) Consulta por posicion */
    printf("Ingrese una posicion (0 a 9): ");
    scanf("%d", &pos);
    if (pos >= 0 && pos <= 9)
        printf("El elemento en la posicion %d es: %d\n", pos, arr[pos]);
    else
        printf("Posicion invalida.\n");

    /* 5) Buscar si un valor pertenece al arreglo */
    printf("Ingrese un valor a buscar: ");
    scanf("%d", &val);
    for (i = 0; i < 10; i++) {
        if (arr[i] == val) {
            printf("El valor %d pertenece al arreglo (posicion %d).\n", val, i);
            i = 10; 
        }
    }
    if (i == 10 && arr[9] != val) {
        printf("El valor %d no pertenece al arreglo.\n", val);
    }

    return 0;
}