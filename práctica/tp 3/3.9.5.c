/*Enunciado del problema: Registro básico de una bicicleta Escribí un programa en C que declare e inicialice las variables 
necesarias para guardar la información de una bicicleta. 
El programa debe almacenar: la cantidad de ruedas (dato fijo que no cambia), el precio de la bicicleta, la letra inicial de 
la marca, el año de fabricación.
Requisitos La cantidad de ruedas debe guardarse como constante. 
El precio debe guardarse en una variable de tipo float. La inicial de la marca debe guardarse en una variable de tipo char. 
El año de fabricación debe guardarse en una variable de tipo int. Asigná valores válidos a cada dato al momento de declarar 
las variables.*/

#include <stdio.h>

int main() {
    const int ruedas = 2;
    float precio = 0.0;
    char marca = 'T';
    int año = 2020;

    printf("Ingrese precio de la bicicleta : \n");    
    scanf("%f", &precio);    
    printf("Ingrese letra inicial de la marca de su bicicleta : \n");
    scanf(" %c", &marca);
    printf("Ingrese anio de fabricacion : \n");
    scanf("%d", &año);

    printf("Ruedas: %d\n", ruedas);
    printf("Precio: %.2f\n", precio);
    printf("Marca: %c\n", marca);
    printf("Anio: %d\n", año);

    return 0;
}