#include <stdio.h>
#define MAX 5

void mostrarInverso(int a[]);

int main()
{
    int vec[MAX];
    int i;
    for (i = 0; i < MAX; i++){
        printf("Ingrese un numero entero \n");
        scanf("%d", &vec[i]);
    }
    mostrarInverso(vec);
    return 0;
}

//  void mostrar(int a[])
//  {
//      int i;
//      for (i = 0; i < MAX; i++){
//          printf("%d ", a[i]);
//      }
//  }

 // ahora hacer un procedimiento que permita mostrar en forma inversa el arreglo

void mostrarInverso(int a[])
{
    int i;
    for (i = MAX - 1; i >= 0; i--){
        printf("%d ", a[i]);
    }
}