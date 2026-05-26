/* Ejercicio 6.3: Acumula pagos hasta que se ingrese 0 */
#include <stdio.h>

int main(void) {
    float pago, total;

    total = 0;

    printf("Ingrese el primer pago: ");
    scanf("%f", &pago);

    while (pago != 0) {
        total = total + pago;
        printf("Ingrese el siguiente pago, 0 para terminar: ");
        scanf("%f", &pago);
    }

    printf("\nEl total de pagos del mes es: %.2f\n", total);

    return 0;
}