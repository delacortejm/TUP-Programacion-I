/* Ejercicio 7: calcula depreciaciones segun método */
#include <stdio.h>

int main(void) {
    float val, aux, deprec, factor;
    int n, anual, eleccion;
    eleccion = 0;
    factor = 2.0;

    while(eleccion !=4){
    printf("Ingrese el metodo que se ha de usar: \n 1. Metodo linea recta \n 2. Metodo de balance doblemente declinante \n 3. Metodo de la suma de los digitos de los anios\n");
    scanf("%d", &eleccion);

    if (eleccion == 1 || eleccion == 2 || eleccion == 3) {
        printf("Ingrese valor inicial del objeto\n");
        scanf("%f", &val); 
        printf("Ingrese los anios de vida util del objeto\n");
        scanf("%d", &n);

        aux = val;

        switch(eleccion)
        {
            case 1:
                deprec = aux/n;
                printf("Anio    Depreciacion    Valor Remanente\n");
                for (anual=1; anual<=n; anual = anual+1)
                {
                    val = val- deprec;
                    printf("%d          %.1f          %.1f\n", anual, deprec, val);
                }
                break;
            
            case 2:
                factor = 2.0/n;
                printf("Anio    Depreciacion    Valor Remanente\n");
                for (anual=1; anual<=n; anual = anual+1)
                {
                    deprec = factor * val;
                    val = val - deprec;
                    printf("%d           %.2f            %.2f\n", anual, deprec, val);
                }             
                break;
            
            case 3:
                int suma = 0;
                int k;
                for (k=1; k<=n; k++)
                suma = suma + k;

                printf("Anio    Depreciacion    Valor Remanente\n");
                for (anual=1; anual<=n; anual = anual+1)
                {
                    deprec = ((float)(n - anual + 1) / suma) * aux;
                    val = val - deprec;
                    printf("%3d      %.2f       %.2f\n", anual, deprec, val);
                }
                break;
        }
        }
            else if (eleccion !=4)
        {
        printf("Error: eleccion invalida. Debe ser 1, 2, 3 o 4.\n");
        }
    printf("\nPrograma finalizado.\n");
    return 0;
}}