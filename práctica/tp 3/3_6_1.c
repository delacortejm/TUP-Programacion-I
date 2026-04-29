/* Ejercicio 6.1: Ayuda para reparar objetos.
   Pregunta si se mueve y si deberia moverse. Termina con 0. */
#include <stdio.h>

int main(void) {
    int seMueve, deberiaMoverse;

    do {
        printf("\n--- Diagnostico ---\n");
        printf("El objeto se mueve? (1 = Si, 2 = No, 0 = Salir): ");
        scanf("%d", &seMueve);

        if (seMueve == 0) {
            break;
        }

        printf("El objeto deberia moverse? (1 = Si, 2 = No): ");
        scanf("%d", &deberiaMoverse);

        if (seMueve == 1 && deberiaMoverse == 1) {
            printf(">> No hace falta reparar.\n");
        } else {
            if (seMueve == 1 && deberiaMoverse == 2) {
                printf(">> Utilizar cinta americana.\n");
            } else {
                if (seMueve == 2 && deberiaMoverse == 2) {
                    printf(">> No hace falta reparar.\n");
                } else {
                    if (seMueve == 2 && deberiaMoverse == 1) {
                        printf(">> Utilizar aceite 3 en 1.\n");
                    } else {
                        printf("ERROR: opcion invalida.\n");
                    }
                }
            }
        }
    } while (seMueve != 0);

    printf("\nPrograma finalizado.\n");
    return 0;
}