/* Ejercicio 3.1: Menu de viajes desde Resistencia.
   Tacopozo $40000, Villa Angela $35000, Castelli $40500, San Martin $25000 */
#include <stdio.h>

int main(void) {
    int opcion;
    float dinero;

    printf("=============================================\n");
    printf("        DESTINOS DE VIAJE DESDE RCIA.        \n");
    printf("=============================================\n");
    printf("  1- Rcia - Tacopozo ......... $40000\n");
    printf("  2- Rcia - Villa Angela ..... $35000\n");
    printf("  3- Rcia - Castelli ......... $40500\n");
    printf("  4- Rcia - San Martin ....... $25000\n");
    printf("=============================================\n");
    printf("Seleccione un destino (1-4): ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("El viaje a Tacopozo cuesta $40000\n");
            break;
        case 2:
            printf("El viaje a Villa Angela cuesta $35000\n");
            break;
        case 3:
            printf("El viaje a Castelli cuesta $40500\n");
            break;
        case 4:
            printf("El viaje a San Martin cuesta $25000\n");
            break;
        default:
            printf("ERROR: opcion invalida.\n");
            return 0;
    }

    printf("\nIngrese el dinero disponible: $");
    scanf("%f", &dinero);

    if (dinero >= 40500) {
        printf("Con $%.2f puede viajar al destino mas lejano: CASTELLI\n", dinero);
    } else {
        if (dinero >= 40000) {
            printf("Con $%.2f puede viajar al destino mas lejano: TACOPOZO\n", dinero);
        } else {
            if (dinero >= 35000) {
                printf("Con $%.2f puede viajar al destino mas lejano: VILLA ANGELA\n", dinero);
            } else {
                if (dinero >= 25000) {
                    printf("Con $%.2f puede viajar al destino mas lejano: SAN MARTIN\n", dinero);
                } else {
                    printf("Con $%.2f no alcanza para ningun destino.\n", dinero);
                }
            }
        }
    }

    return 0;
}