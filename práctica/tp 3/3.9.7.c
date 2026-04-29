/** Escribe un programa en C que:

Lea dos números enteros ingresados por el usuario (llámalos a y b).

Utilizando operadores matemáticos, calcule y muestre:

La suma (a + b)

La resta (a - b)

La multiplicación (a * b)

La división entera (a / b, considerando que b no es cero)

El resto de la división entera (a % b)

Utilizando operadores relacionales, compare a y b y muestre el resultado (1 si es verdadero, 0 si es falso) de:

a == b

a != b

a > b

a < b

a >= b

a <= b

Utilizando operadores lógicos, calcule y muestre el resultado (1 o 0) de:

(a > b) && (b != 0)

(a > b) || (b != 0)

Demuestre el uso de operadores de asignación combinados:

A la variable a asígnele el valor original de a más b usando += y luego muestre el nuevo valor de a.

A la variable b asígnele el valor original de b multiplicado por 2 usando *= y luego muestre el nuevo valor de b.

Restricción: No uses estructuras de decisión (como if). Solo utiliza expresiones con operadores y muestra los resultados con printf. Recuerda incluir #include <stdio.h> y usar scanf para la entrada.
 */

#include <stdio.h>
#include <math.h>

int main() {
    int a, b;

    printf("Ingrese el valor de a: ");
    scanf("%d", &a);

    printf("Ingrese el valor de b: ");
    scanf("%d", &b);

    // Operadores matemáticos
    printf("Suma (a + b): %d\n", a + b);
    printf("Resta (a - b): %d\n", a - b);
    printf("Multiplicacion (a * b): %d\n", a * b);
    printf("Division (a / b): %d\n", a / b);
    printf("Resto (a %% b): %d\n", a % b);

    // Operadores relacionales
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    // Operadores lógicos
    printf("(a > b) && (b != 0): %d\n", (a > b) && (b != 0));
    printf("(a > b) || (b != 0): %d\n", (a > b) || (b != 0));

    // Operadores de asignación combinados
    a += b;
    printf("Nuevo valor de a despues de a += b: %d\n", a);
    b *= 2;
    printf("Nuevo valor de b despues de b *= 2: %d\n", b);

    return 0;
}