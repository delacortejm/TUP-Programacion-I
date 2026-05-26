#include <stdio.h>
#include <string.h>

int main() 
{
	char nombre[256], apellido[256];
    int edad;

	printf ("Ingrese su nombre:\n");
	fgets(nombre, 256, stdin);
	nombre[strcspn(nombre, "\n")] = 0;
	
	printf ("Ingrese su apellido:\n");
	fgets(apellido, 256, stdin);
	apellido[strcspn(apellido, "\n")] = 0;

    printf ("Ingrese su edad:\n");
	scanf ("%i",&edad);
	
	printf ("Su nombre completo es: %s %s\n\n", nombre, apellido);
	printf ("Y tiene actualmente: %i anios de edad\n", edad);

	
	
	
	return 0;
}