/*Estructuras de datos

Clasificación:

a. Estructuras Estáticas

b. Estructuras Dinámicas

Arreglos: coleccion de variables del mismo tipo que se referencian utilizando un nombre común.
    ejemplo: 
    a= {5, 67, 98, 34, 22}
    a[0], a[1], a[2], a[3], a[4] 

    características:
    - finito: tienen un tamaño fijo definido
    - ordenado: los elementos se almacenan en posiciones consecutivas
    - homogeneo: todos los elementos son del mismo tipo

    Operaciones con arreglos:
    - cargar un arreglo (generalmente se usa for, a veces while)
    - recorrer un arreglo
    - buscar un elemento en particular


*/

#include <stdio.h>
#include <conio.h>

// Hacer un programa que compare la suma entre los elementos de lista y de lista_2 y diga cual es mayor o si son iguales
int main()
{
    int lista[9] = {0, 4, 78, 5, 32, 9, 77, 1, 23};
    int lista_2[9];
    int i, suma_lista = 0, suma_lista_2 = 0;

    // Cargar lista_2 y sumar ambas listas en un solo recorrido
    for (i = 0; i < 9; i++)
    {
        printf("Ingresar el elemento %d de lista_2: ", i + 1);
        scanf("%d", &lista_2[i]);
        suma_lista   += lista[i];
        suma_lista_2 += lista_2[i];
    }

    printf("\nSuma de lista:   %d\n", suma_lista);
    printf("Suma de lista_2: %d\n", suma_lista_2);

    if (suma_lista > suma_lista_2)
        printf("lista tiene la suma mayor.\n");
    else if (suma_lista_2 > suma_lista)
        printf("lista_2 tiene la suma mayor.\n");
    else
        printf("Ambas listas tienen la misma suma.\n");

    getch();
    return 0;
}
