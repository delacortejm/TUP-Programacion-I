/* Ejercicio 1.2: Calcular la edad de una persona segun el algoritmo del TP1 */
#include <stdio.h>

int main(void) {
    int diaNac, mesNac, anioNac;
    int diaAct, mesAct, anioAct;
    int edad;

    printf("--- Fecha actual ---\n");
    printf("Ingrese el dia: ");
    scanf("%d", &diaAct);
    printf("Ingrese el mes: ");
    scanf("%d", &mesAct);
    printf("Ingrese el anio: ");
    scanf("%d", &anioAct);

    printf("\n--- Fecha de nacimiento ---\n");
    printf("Ingrese el dia: ");
    scanf("%d", &diaNac);
    printf("Ingrese el mes: ");
    scanf("%d", &mesNac);
    printf("Ingrese el anio: ");
    scanf("%d", &anioNac);

    if (anioNac > anioAct) {
        printf("ERROR: el anio de nacimiento no puede ser mayor al actual.\n");
    } else {
        edad = anioAct - anioNac;

        if (mesAct < mesNac || (mesAct == mesNac && diaAct < diaNac)) {
            edad = edad - 1;
        }

        if (edad < 0) {
            printf("ERROR: la fecha de nacimiento es posterior a la fecha actual.\n");
        } else {
            printf("\nSu edad es: %d anios\n", edad);
        }
    }

    return 0;
}