/* Modificar el programa para que se carguen la cantidad de jugadores total del 
equipo y la lista de jugadores titulares.

/* Modificar el programa para definir un semifinal de 4 equipos. */

#include <stdio.h>

#define MAX_TEXTO 50
#define CANT_EQUIPOS 4

struct Equipo
{
  char nombre[MAX_TEXTO];
};

struct Partido
{
  struct Equipo equipo1;
  struct Equipo equipo2;
};

int main()
{
  struct Equipo equipos[CANT_EQUIPOS];

  for (int i = 0; i < CANT_EQUIPOS; i++)
  {
    printf("Ingrese el nombre del equipo %d: ", i + 1);
    fgets(equipos[i].nombre, MAX_TEXTO, stdin);
  }

  struct Partido semifinales[2];
  semifinales[0].equipo1 = equipos[0];
  semifinales[0].equipo2 = equipos[1];
  semifinales[1].equipo1 = equipos[2];
  semifinales[1].equipo2 = equipos[3];

  printf("\nSemifinales:\n");
  for (int i = 0; i < 2; i++)
  {
    printf("Semifinal %d: %s vs %s\n", i + 1,
           semifinales[i].equipo1.nombre,
           semifinales[i].equipo2.nombre);
  }

  return 0;
}