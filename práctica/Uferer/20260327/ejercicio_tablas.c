#include <stdio.h>

int main()
{
  int i;
  printf("Ingrese un numero para mostrar su tabla de multiplicar: ");
  scanf_s("%d", &i);

  {
    printf("Tabla de multiplicar del %d:\n", i);
    for (int j = 1; j <= 10; j++)
    {
      int total = i * j;
      printf("%d x %d = %d\n", i, j, total);
    }
  }
  return 0;
}