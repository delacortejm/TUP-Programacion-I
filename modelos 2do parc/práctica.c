#include <stdio.h>
#include <conio.h>


int main(){
int legajos[5] = {1024, 1057, 1089, 1102, 1135};
int posicion;
int buscado;
int i;

posicion= -1;

printf("Ingrese num a buscar:");
scanf("%d", &buscado);

for(i=0;i<5; i++){
    if (legajos[i]==buscado)
    {posicion = i;}
    
}

if(posicion == -1)
       printf("Legajo no encontrado");
   else
       printf("Legajo encontrado en la posicion %d", posicion);
return 0;
}