#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int total_tiros, resultado, contador;
    int cont1=0, cont2=0, cont3=0, cont4=0, cont5=0, cont6=0;
    float frec1, frec2,frec3,frec4,frec5,frec6;

    srand(time(NULL));

    printf("Ingrese la cantidad de tiros: ");
    scanf_s("%d", &total_tiros);

    //bucle while
    contador = 1;
    while (contador <= total_tiros) {
        resultado = rand() % 6 + 1;

        if(resultado==1)
        {
            cont1=cont1+1;
        }
        else if(resultado==2)
        {
            cont2=cont2+1;
        }
        else if(resultado==3)
        {
            cont3=cont3+1;
        }
        else if(resultado==4)
        {
            cont4=cont4+1;
        }
        else if(resultado==5)
        {
            cont5=cont5+1;
        }
        else
        {
            cont6=cont6+1;
        }


        contador++; // Importante: actualiza la variable para evitar bucles infinitos
    }
    //casteo de int a float para no perder decimales
    frec1 = (float)cont1/total_tiros * 100;
    frec2 = (float)cont2/total_tiros * 100;
    frec3 = (float)cont3/total_tiros * 100;
    frec4 = (float)cont4/total_tiros * 100;
    frec5 = (float)cont5/total_tiros * 100;
    frec6 = (float)cont6/total_tiros * 100;

    printf("\nResultados de %d tiros: \n", total_tiros);
    printf("1: %d - frecuencia relativa: %.2f \n", cont1, frec1);
    printf("2: %d - frecuencia relativa: %.2f\n", cont2, frec2);
    printf("3: %d - frecuencia relativa: %.2f\n", cont3, frec3);
    printf("4: %d - frecuencia relativa: %.2f\n", cont4, frec4);
    printf("5: %d - frecuencia relativa: %.2f\n", cont5, frec5);
    printf("6: %d - frecuencia relativa: %.2f\n", cont6, frec6);

    return 0;
} 