/*hacer un struct de equipos de futbol de sudamérica, 
tiene que tener nombre, ciudad, copas libertadores */

#include <stdio.h>
#include <string.h>
#define max_texto 20
#define cant_equipos 5
struct Equipo {
    char nombre[max_texto];
    char ciudad[max_texto];
    int copas_libertadores;
};

int main() {
    struct Equipo equipos[cant_equipos] = {
        {"Boca Juniors", "Buenos Aires", 6},
        {"River Plate", "Buenos Aires", 4},
        {"Olimpia", "Paraguay", 3},
        {"Nacional", "Montevideo", 3},
        {"Flamengo", "Rio de Janeiro", 2}
    };

    printf("Equipos de futbol de Sudamérica:\n");
    for (int i = 0; i < cant_equipos; i++) {
        printf("Nombre: %s, Ciudad: %s, Copas Libertadores: %d\n",
               equipos[i].nombre, equipos[i].ciudad, equipos[i].copas_libertadores);
    }

    return 0;
}