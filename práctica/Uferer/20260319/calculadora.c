#include <stdio.h>
#include<math.h>

int main()
{
  int num1, num2;
  int opcion;
  double raiz;

  printf("Selecciones una operacion:\n");
  printf("1. Suma\n");
  printf("2. Resta\n");
  printf("3. Multiplicacion\n");
  printf("4. Division\n");
  printf("5. Potencia\n");
  printf("6. Raiz\n");
  printf("Opcion: ");
  scanf("%d", &opcion);

  printf("Ingrese el primer numero: ");
  scanf("%d", &num1);
  if (opcion != 6)
    {
      printf("Ingrese el segundo numero: ");
      scanf("%d", &num2);
    }
  ;

  switch (opcion)
  {
  case 1:
    int suma = num1 + num2;
    printf(" %d + %d = %d\n", num1, num2, suma);
    break;
  case 2:
    int resta = num1 - num2;
    printf(" %d - %d = %d\n", num1, num2, resta);
    break;
  case 3:
    int multiplicacion = num1 * num2;
    printf(" %d * %d = %d\n", num1, num2, multiplicacion);
    break;
  case 4:
    if (num2 != 0)
    {
      float division = (float)num1 / num2;
      printf(" %d / %d = %.2f\n", num1, num2, division);
    }
    else
    {
      printf("Error: No se puede dividir por cero.\n");
    }
    case 5:
        int potencia = pow(num1, num2);
        printf(" %d ^ %d = %d\n", num1, num2, potencia);
        break;
    case 6:
        double raiz = sqrt(num1);
        printf(" Raiz cuadrada de %d = %.2f\n", num1, raiz);
        break;

  default:
    printf("Opcion no valida.\n");
  }

  return 0;
}