#include <stdio.h>

int main() 
{
	int x,y,mult;
	char car;
	mult=0;
	car='Ejercicio 3';
	printf ("Ingrese el primer valor:\n");
	scanf ("%i",&x);
	
	printf ("Ingrese el segundo valor:\n");
	scanf ("%i",&y);
	
	mult=x*y;
	
	printf ("La multiplicación es %i \n\n", mult);
	printf ("Resultado de multiplicación:%i*%i=%i", x,y,mult);
	
	
	
	
	return 0;
}
