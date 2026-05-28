/*
CONSIGNA

se desea calcular el costo de enviar un telegrama.

el telegrama esta compuesto de palabras y oraciones,cada palabra esta separada por un 
"*" (asterisco) cada oracion esta separada por un "." (punto). el final del telegrama esta 
indicado por un - (guion medio).
Si el telegrama tiene una oracion y 5 palabras, el costo del caracter es de 100 pesos
si el telegrama tiene dos oraciones y a la cantidad de palabras no suepra el valor de 10. 
el valor del caracter es 500
Cualquier otra condicion el valor del caracter es 1000

Ingresar la cadena por teclado
USar un procedimineto para mostrar el contenido de la cadena.*/

#include <stdio.h>

void mostrarTelegrama(char telegrama[]);

int main() {
    char telegrama[200];
    int i = 0, palabras = 0, oraciones = 0, caracteres = 0, costo=0;

    printf("Ingrese el telgrama separando palabras con '*' (finalice con '-'): ");
    gets(telegrama);

    while (telegrama[i] != '-' && telegrama[i] != '\0') {
        oraciones++;
        while (telegrama[i] != '.' && telegrama[i] != '-' && telegrama[i] != '\0') {
            palabras++;
            while (telegrama[i] != '*' && telegrama[i] != '.' && telegrama[i] != '-' && telegrama[i] != '\0') {
                caracteres++;
                i++;
            }
            if (telegrama[i] == '*') {
                i++;
            }
        }
        if (telegrama[i] == '.') {
            i++;
        }
    }

    if (oraciones == 1 && palabras == 5) {
        costo = caracteres * 100;
    } else if (oraciones == 2 && palabras <= 10) {
        costo = caracteres * 500;
    } else {
        costo = caracteres * 1000;
    }

    mostrarTelegrama(telegrama);
    printf("Palabras: %d\n", palabras);
    printf("Oraciones: %d\n", oraciones);
    printf("Caracteres: %d\n", caracteres);
    printf("Costo del telegrama: %d pesos\n", costo);

    return 0;
}

void mostrarTelegrama(char telegrama[]) {
    printf("Contenido: %s\n", telegrama);
}