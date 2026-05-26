/*un capital C a una tasa r, a los cuantos anios se duplicará?

usar: 
- cálculo de interes simple
- cálculo de interes compuesto */

#include <stdio.h>
#include <math.h>   

int main(void) {
    double C, r, t_simple, t_compuesto;

    printf("Ingrese el capital inicial: ");
    scanf("%lf", &C);

    printf("Ingrese la tasa de interes (en porcentaje): ");
    scanf("%lf", &r);

    r = r / 100; // Convertir la tasa a decimal

    // Cálculo de tiempo para interes simple
    t_simple = (C * 2 - C) / (C * r); // Tiempo = (Monto final - Capital inicial) / (Capital inicial * tasa)

    // Cálculo de tiempo para interes compuesto
    t_compuesto = log(2) / log(1 + r); // Tiempo = log(2) / log(1 + tasa)

    printf("Tiempo para duplicar el capital con interes simple: %.2f anios\n", t_simple);
    printf("Tiempo para duplicar el capital con interes compuesto: %.2f anios\n", t_compuesto);

    return 0;
}