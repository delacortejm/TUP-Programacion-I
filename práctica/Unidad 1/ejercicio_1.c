#include <stdio.h>

int main() 
{
	int x,y,suma;
	char car;
	
	x=2;
	y=4;
	suma=0;
	car='a';
		
	suma=x+y;
	printf("La suma es %i \n\n", suma);
	printf("Resultado suma:%i+%i=%i", x,y,suma);
	printf("\n\nEl valor del caracter es: %c", car);
	
	printf("\n\nCaracter es: %c y suma: %i",car,suma);
	
	
	
	return 0;
}

