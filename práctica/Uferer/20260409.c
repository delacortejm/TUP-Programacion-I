#include <stdio.h>
#include <string.h>

// int main()
// {
//     char palabra[] = "computadora";
//     char *ptr = strchr(palabra, 'u');
    
//     printf("La palabra es: %s\n", palabra);
//     printf("PTR es: %p\n", (void*)ptr);

//     if (ptr != NULL)
//     {
//         printf("Encontrado: %c en la posicion %ld\n", *ptr, ptr - palabra);
//     }
//     else
//     {
//         printf("No se encontró el carácter\n");
//     }

//     return 0;
// }

//Quiero que me muestren un nuevo array de números que sea el cuadrado de cada elemento de este array {3, 2, 1,5,2,9,2}

int main() {
    int numeros[] = {3, 2, 1, 5, 2, 9, 2};
    int cuadrados[7];

    for (int i = 0; i < 7; i++) {
        cuadrados[i] = numeros[i] * numeros[i];
    }

    for (int i = 0; i < 7; i++) {
        printf("%d ", cuadrados[i]);
    }
    printf("\n");

    return 0;
}