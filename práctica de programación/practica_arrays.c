// #include <stdio.h>

//declaración de un array de 5 elementos
//int array[5];

//inicializar el arreglo mediante declaración del arreglo//
//int array[5] = {0,1,2,3,4}

//utilización de arreglos
#include <stdio.h>
#include <conio.h>

int main() {
    int lista[5];    
    int i;
    for(i=0;i<5;i++)
        {
            printf("Ingresar digito %d: para el array lista\n",i);
            scanf("%d", &lista[i]);
        }
    for(i=0;i<5; i++)
        printf("Elemento %d: %d\n", i+1, lista[i]);

return 0;
getch();
}