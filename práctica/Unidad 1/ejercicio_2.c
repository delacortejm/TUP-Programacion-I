#include <stdio.h>

int main() 
{
	int x,y,suma;

	suma=0;

	printf ("Ingrese el primer valor:\n");
	scanf ("%i",&x);
	
	printf ("Ingrese el segundo valor:\n");
	scanf ("%i",&y);
	
	suma=x+y;
	
	printf ("La suma es %i \n\n", suma);
	printf ("Resultado suma:%i+%i=%i", x,y,suma);

	
	
	
	return 0;
}

