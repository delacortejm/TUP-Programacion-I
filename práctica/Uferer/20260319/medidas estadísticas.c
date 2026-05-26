#include <stdio.h>
#include<math.h>

int main()
{
  int num1, num2, num3, num4, num5, suma;
  float promedio;
  printf("Ingrese primer numero:\n");
  scanf("%d", &num1);
  if (num1 < 1 || num1 > 10) {
    printf("Error: numero fuera de rango.\n");
    return 1;}
  printf("Ingrese segundo numero:\n");
  scanf("%d", &num2);
  if (num2 < 1 || num2 > 10) {
    printf("Error: numero fuera de rango.\n");
    return 1;}
  printf("Ingrese tercer numero:\n");
  scanf("%d", &num3);
  if (num3 < 1 || num3 > 10) {
    printf("Error: numero fuera de rango.\n");
    return 1;}
  printf("Ingrese cuarto numero:\n");
  scanf("%d", &num4);
  if (num4 < 1 || num4 > 10) {
    printf("Error: numero fuera de rango.\n");
    return 1;}
  printf("Ingrese quinto numero:\n");
  scanf("%d", &num5);
  if (num5 < 1 || num5 > 10) {
    printf("Error: numero fuera de rango.\n");
    return 1;}

  suma = num1+num2+num3+num4+num5;
  promedio = suma / 5;

  printf("Este es el promedio de los numeros ingresados: %.2f\n", promedio);
  
  return 0;
}