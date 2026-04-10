#include <stdio.h>
#include <string.h>

int main()
{
    char palabra[] = "computadora";
    char *ptr = strchr(palabra, 'u');
    
    printf("La palabra es: %s\n", palabra);
    printf("PTR es: %p\n", (void*)ptr);

    if (ptr != NULL)
    {
        printf("Encontrado: %c en la posicion %ld\n", *ptr, ptr - palabra);
    }
    else
    {
        printf("No se encontró el carácter\n");
    }

    return 0;
}