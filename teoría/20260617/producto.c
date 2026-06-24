#include <stdio.h>

// funcion que calcula el producto de a y b pero sin usar el *
// la idea es sumar a, b veces (eso es multiplicar en el fondo)
int producto_recursivo(int a, int b) {
	
	// caso base, si b llega a 0 ya no hay mas nada que sumar
	if (b == 0) {
		return 0;
	}
	
	// si b es positivo voy sumando a y bajando b de 1 en 1
	// hasta que b llegue a 0 (caso base de arriba)
	if (b > 0) {
		return a + producto_recursivo(a, b - 1);
	}
	
	// si b es negativo paso por aca, en este caso voy restando a
	// (sumar -a) y subiendo b de 1 en 1 hasta que llegue a 0 tmb
	return -a + producto_recursivo(a, b + 1);
}

int main() {
	int num1, num2;
	
	// pido los dos numeros por teclado
	printf("Ingrese el primer numero (a): ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero (b): ");
	scanf("%d", &num2);
	
	// llamo a la funcion recursiva con los datos que ingreso el usuario
	int resultado = producto_recursivo(num1, num2);
	
	// muestro el resultado final
	printf("El producto de %d x %d sin usar el operador '*' es: %d\n", num1, num2, resultado);
	
	return 0;
}