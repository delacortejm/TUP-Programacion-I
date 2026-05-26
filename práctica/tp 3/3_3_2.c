/****************************************************************/
/* Objetivo: Leer dos numeros enteros y luego realizar           */
/*           una de las operaciones aritmeticas, las             */
/*           cuales se presentaran en un menu de                 */
/*           seleccion.                                          */
/* Entrada : Dos numeros enteros                                 */
/* Salida  : La correspondiente operacion aritmetica.            */
/****************************************************************/
#include <stdio.h>

int main(void) {
    int a, b, opcion;

    printf("Ingrese el primer numero entero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &b);

    printf("\n===== MENU DE OPERACIONES =====\n");
    printf("  1- Suma\n");
    printf("  2- Resta\n");
    printf("  3- Multiplicacion\n");
    printf("  4- Division\n");
    printf("===============================\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case 2:
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case 3:
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case 4:
            if (b == 0) {
                printf("ERROR: no se puede dividir por cero.\n");
            } else {
                printf("%d / %d = %.2f\n", a, b, (float)a / b);
            }
            break;
        default:
            printf("ERROR: opcion invalida.\n");
    }

    return 0;
}