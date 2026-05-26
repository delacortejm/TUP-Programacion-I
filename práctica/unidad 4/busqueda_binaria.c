#include <stdio.h>

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
        return medio;   /* devuelve la posicion */
    else
        return -1;      /* no encontrado */
}

int main() {

    int lista[9] = {0, 4, 5, 7, 32, 40, 77, 100, 123};
    int i, num, resultado;

    for (i = 0; i < 9; i++)
        printf("Digito %d: %d\n", i, lista[i]);

    printf("Ingresar el numero a buscar:\n");
    scanf("%d", &num);

    resultado = busquedaBinaria(lista, 9, num);

    if (resultado != -1)
        printf("%d encontrado en la posicion %d\n", num, resultado);
    else
        printf("%d no esta en el arreglo\n", num);

    return 0;
}
