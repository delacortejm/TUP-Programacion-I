/*
Reto: Contador de Notas de Examen
El objetivo es procesar las notas de un grupo de alumnos para obtener estadísticas básicas.

1. Validación de Inicio
El programa debe pedir un PIN de seguridad (ejemplo: 99) para comenzar. Si el usuario se equivoca, debe insistir hasta que el PIN sea el correcto.

2. Carga de Notas
Una vez dentro, el programa preguntará: "¿Desea ingresar una nota? (1=Sí / 0=No)".
Mientras el usuario elija 1, se pedirá una nota (del 1 al 10).
Si la nota es menor a 4, el programa debe mostrar el mensaje "Reprobado". De lo contrario, mostrará "Aprobado".
El programa debe contar cuántas notas se ingresaron en total y sumarlas.

3. Cierre y Promedio
Cuando el usuario decida no ingresar más notas (presionando 0):
El programa debe mostrar el Promedio Final (Suma de notas / Cantidad de notas).
Para finalizar, el programa debe imprimir una fila de 10 puntos (.) seguidos como un separador decorativo.*/ 

#include <stdio.h>

int main()
{
int pin, ingresar_nota;
float nota, suma_notas=0, contador_notas=0;

do {
    printf("Ingrese PIN: ");
    scanf("%d", &pin);
} while (pin != 99);

printf("¿Desea ingresar una nota? (1=Sí / 0=No): ");
scanf("%d", &ingresar_nota);
 while (ingresar_nota == 1)
{
printf("Ingrese nota: ");
scanf("%f", &nota);
    if (nota < 4)
    {
        printf("Reprobado\n");
    }
    else
    {
          printf("Aprobado\n");
    } 
    contador_notas++;
    suma_notas += nota;
    printf("¿Desea ingresar una nota? (1=Sí / 0=No): ");
    scanf("%d", &ingresar_nota);
}
if (contador_notas > 0)
{
    float promedio = suma_notas / contador_notas;
    printf("Promedio Final: %.2f\n", promedio);
}
for (int i = 0; i < 10; i++)
{
    printf(".");
}
printf("\n");
return 0;
}