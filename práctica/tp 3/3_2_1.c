/* Ejercicio 2.1: Clasifica al alumno en grupo A o B.
   Grupo A: mujeres con nombre anterior a M, hombres con nombre posterior a N.
   Grupo B: el resto. */
#include <stdio.h>

int main(void) {
    char inicial, sexo;

    printf("Ingrese la inicial de su nombre (en MAYUSCULA): ");
    scanf(" %c", &inicial);

    printf("Ingrese su sexo (F = femenino, M = masculino): ");
    scanf(" %c", &sexo);

    if (sexo == 'F' || sexo == 'f') {
        if (inicial < 'M') {
            printf("Pertenece al GRUPO A\n");
        } else {
            printf("Pertenece al GRUPO B\n");
        }
    } else {
        if (sexo == 'M' || sexo == 'm') {
            if (inicial > 'N') {
                printf("Pertenece al GRUPO A\n");
            } else {
                printf("Pertenece al GRUPO B\n");
            }
        } else {
            printf("ERROR: sexo invalido. Use F o M.\n");
        }
    }

    return 0;
}