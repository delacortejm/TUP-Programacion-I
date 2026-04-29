#include <stdio.h>
#define MAX 5

void mostrar(int a[]);
int pares (int a[]);

int main()
{
    int vec[MAX],p;
    int i;
    for(i=0; i<MAX; i++)
    {
            printf("Ingrese un numero entero \n");
            scanf("%d", &vec[i]);
    }
    mostrar(vec);
    p = pares(vec);
    printf("La cantidad de elementos pares es: %d\n", p);
    return 0;
}

void mostrar(int a[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("Elemento %d: %d\n", i+1, a[i]);
    }

}

int pares (int a[])
{
    int i, cant;
    cant=0;
    for(i=0;i<MAX;i++)
        if(a[i]% 2==0) cant++;
    return cant;
}