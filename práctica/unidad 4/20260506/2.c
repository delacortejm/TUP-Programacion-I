#include <stdio.h>

void ordenar(int lista[], int tam) {
    int i, j, aux;

    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

int busquedaBinaria(int lista[], int tam, int clave) {
    int primero, ultimo, medio;
    primero = 0;
    ultimo = tam - 1;
    medio = 0;

    while ((primero <= ultimo) && clave != lista[medio]) {
        medio = (primero + ultimo) / 2;
        if (clave > lista[medio])
            primero = medio + 1;
        else
            ultimo = medio - 1;
    }

    if (clave == lista[medio])
        return medio;
    else
        return -1;
}

void buscar(int lista[], int tam) {
    int num, resultado;

    printf("Ingresar el numero a buscar:\n");
    scanf("%d", &num);

    resultado = busquedaBinaria(lista, tam, num);

    if (resultado != -1)
        printf("%d encontrado en la posicion %d\n", num, resultado);
    else
        printf("%d no esta en el arreglo\n", num);
}

int main() {

    int lista[9] = {77, 4, 123, 7, 0, 40, 5, 100, 32};  /* desordenado */
    int i;

    printf("Arreglo desordenado:\n");
    for (i = 0; i < 9; i++)
        printf("Digito %d: %d\n", i, lista[i]);

    ordenar(lista, 9);

    printf("\nArreglo ordenado:\n");
    for (i = 0; i < 9; i++)
        printf("Digito %d: %d\n", i, lista[i]);

    buscar(lista, 9);

    return 0;
}