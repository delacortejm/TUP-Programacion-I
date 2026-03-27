/*Desarrollen un programa que permita registrar un evento la cantidad de veces que pase y nos indique 
la probabilidad de que pase nuevamente. Por ejmplo si tiro 10 veces una moneda al aire debo poder 
registrar si es cara o seca indicando 1 para cara o 2 para seca o por ejemplo la cantidad de veces que
sale determinado número de un dado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int seca, cara, total_tiradas0;
    float frecRelCara;
    int contador = 1;

    printf("Ingrese la cantidad de cantidad de tiros: ");
    scanf_s("%d", &contador);
    //bucle while
    while (contador <= count_tiros) {
        printf("Número %d\n", return rand() % caras + 1;);
        contador++; // Importante: actualiza la variable para evitar bucles infinitos
    }
} 

/*si yo tengo un int y lo quiero castear a float, pero al reves hay problemas...
yo puedo parsear hacia arriba
si yo parseo un float a un entero pierdo datos*/