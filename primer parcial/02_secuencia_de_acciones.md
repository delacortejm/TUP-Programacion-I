# 02 · Secuencia de Acciones

## Conceptos clave

| Concepto | Definición |
|----------|-----------|
| **Proceso** | Secuencia ordenada de acciones orientadas a lograr un objetivo |
| **Acción** | Operación concreta que realiza el programa (leer, calcular, mostrar, asignar) |
| **Estado** | Situación del programa en un momento dado (= valores actuales de las variables) |

---

## Composición secuencial de acciones
Las instrucciones se ejecutan **una después de otra**, en el orden en que aparecen.

```c
int numero;
int cuadrado;

numero = 4;
cuadrado = numero * numero;   // cuadrado = 16
```

> Incluso dentro de un `if`, `while` o `for`, el interior sigue siendo secuencial.

---

## Estados: inicial, intermedio y final

```c
int numero;    // estado inicial: número sin valor
int doble;

numero = 6;    // estado intermedio: numero=6, doble=?
doble = numero * 2;  // estado final: numero=6, doble=12
```

---

## Refinamiento sucesivo
Técnica para pensar soluciones de forma **gradual**, de lo general a lo particular.

### Ejemplo: promedio de dos números

**Nivel 1 (idea general)**
```
leer dos números → calcular promedio → mostrar resultado
```

**Nivel 2 (más detalle)**
```
declarar variables → leer nro1 → leer nro2 → sumar → dividir por 2 → mostrar
```

**Nivel 3 (código)**
```c
#include <stdio.h>

int main() {
    float numero1, numero2, promedio;

    printf("Ingrese el primer número: ");
    scanf("%f", &numero1);

    printf("Ingrese el segundo número: ");
    scanf("%f", &numero2);

    promedio = (numero1 + numero2) / 2;

    printf("El promedio es %f\n", promedio);

    return 0;
}
```

---

## Secuencia y cambio de estado

```c
int x;
x = 2;       // x = 2
x = x + 5;  // x = 7
x = x * 3;  // x = 21
```

Cada acción **transforma** el estado anterior.

---

## Errores comunes
- Querer saltar a `if`/`while` sin entender secuencia y estado.
- Pensar el programa como "texto" y no como "proceso".
- No distinguir estado inicial, intermedio y final.
- Escribir código sin refinar primero la solución.

---

## Resumen rápido
- Programa = proceso = secuencia de acciones que transforma estados.
- Estado = valores de las variables en un instante.
- Composición secuencial = forma más básica de organizar un programa.
- Refinamiento sucesivo = pasar de idea general → detalle → código.
