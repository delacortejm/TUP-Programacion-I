#include <stdio.h>
#define MAX 5

int buscar(int a[], int num);

int main()
{
    int vec[MAX], bus, b1;
    int i;

    for (i = 0; i < MAX; i++) {
        printf("Ingrese un numero entero: ");
        scanf("%d", &vec[i]);
    }

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &bus);

    b1 = buscar(vec, bus);

    if (b1 == 0) {
        printf("El numero no se encuentra en el arreglo\n");
    } else {
        printf("El numero se encuentra en el arreglo (%d vez/veces)\n", b1);
    }

    return 0;
}

int buscar(int a[], int num)
{
    int i, cant = 0;
    for (i = 0; i < MAX; i++)
        if (a[i] == num) cant++;
    return cant;
}
