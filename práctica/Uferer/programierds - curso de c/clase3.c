#include <stdio.h>

int main() {

    const float PI = 3.1416;

    float radio = 5.0;
    float area;

    area = PI * radio * radio;

    printf("El area del circulo es: %.2f\n", area);

    return 0;
}