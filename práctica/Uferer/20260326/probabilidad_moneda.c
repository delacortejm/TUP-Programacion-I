/*Desarrollen un programa que permita registrar un evento la cantidad de veces que pase y nos indique 
la probabilidad de que pase nuevamente. Por ejmplo si tiro 10 veces una moneda al aire debo poder 
registrar si es cara o seca indicando 1 para cara o 2 para seca o por ejemplo la cantidad de veces que
sale determinado número de un dado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int total_tiros, contador, resultado;
    int cara = 0, seca=0;
    float frecCara, frecSeca;

    srand(time(NULL));

    printf("Ingrese la cantidad de tiros: ");
    scanf_s("%d", &total_tiros);

    //bucle while
    contador = 1;
    while (contador <= total_tiros) {
        resultado = rand() % 2+1;

        if(resultado==1)
        {
            cara=cara+1;
        }
        else 
        {
            seca=seca+1;
        }
        contador++; // Importante: actualiza la variable para evitar bucles infinitos
    }
    //casteo de int a float para no perder decimales
    frecCara = (float)cara/total_tiros * 100;
    frecSeca = (float)seca/total_tiros * 100;

    printf("\nResultados de %d tiros: \n", total_tiros);
    printf("Caras: %d - frecuencia relativa: %.2f \n", cara,frecCara);
    printf("Secas: %d - frecuencia relativa: %.2f\n", seca, frecSeca);

    return 0;
} 

/*si yo tengo un int y lo quiero castear a float, pero al reves hay problemas...
yo puedo parsear hacia arriba
si yo parseo un float a un entero pierdo datos*/