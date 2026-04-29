/* CALCULADORA FUNCIONES TRIGONOMETRICAS BASICAS */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

int main(void) {
    int opcion;
    float angulo, radianes, resultado;

    printf("**************************************************\n");
    printf("* CALCULADORA FUNCIONES TRIGONOMETRICAS BASICAS  *\n");
    printf("**************************************************\n");
    printf("* Lista de funciones trigonometricas             *\n");
    printf("*   1- Seno                                      *\n");
    printf("*   2- Coseno                                    *\n");
    printf("*   3- Tangente                                  *\n");
    printf("**************************************************\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    printf("Ingrese el angulo en grados: ");
    scanf("%f", &angulo);

    radianes = angulo * PI / 180.0;

    switch (opcion) {
        case 1:
            resultado = sin(radianes);
            printf("sen(%.2f) = %.4f\n", angulo, resultado);
            break;
        case 2:
            resultado = cos(radianes);
            printf("cos(%.2f) = %.4f\n", angulo, resultado);
            break;
        case 3:
            if (((int)angulo - 90) % 180 == 0) {
                printf("ERROR: la tangente no esta definida en %.2f grados.\n", angulo);
            } else {
                resultado = tan(radianes);
                printf("tan(%.2f) = %.4f\n", angulo, resultado);
            }
            break;
        default:
            printf("ERROR: opcion invalida.\n");
    }

    return 0;
}