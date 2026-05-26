# 16 · Operaciones con Arreglos

## Operaciones básicas

| Operación | Qué hace |
|-----------|---------|
| **Recorrido** | Visitar todos los elementos uno por uno |
| **Búsqueda** | Encontrar un valor dentro del arreglo |
| **Inserción** | Agregar un nuevo dato en una posición |

---

## Recorrido — mostrar todos los elementos

```c
#include <stdio.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int i;

    for (i = 0; i < 5; i = i + 1) {
        printf("Posicion %d -> %d\n", i, numeros[i]);
    }

    return 0;
}
```

---

## Recorrido — sumar elementos

```c
int numeros[5] = {3, 5, 2, 8, 4};
int suma = 0;
int i;

for (i = 0; i < 5; i = i + 1) {
    suma = suma + numeros[i];
}

printf("La suma es: %d\n", suma);   // 22
```

**Evolución de `suma`:** 0 → 3 → 8 → 10 → 18 → 22

---

## Recorrido — encontrar el mayor valor

```c
int numeros[5] = {12, 7, 25, 18, 9};
int mayor = numeros[0];   // empezar con un valor real del arreglo
int i;

for (i = 1; i < 5; i = i + 1) {
    if (numeros[i] > mayor) {
        mayor = numeros[i];
    }
}

printf("El mayor valor es: %d\n", mayor);   // 25
```

> **Buena práctica:** inicializar `mayor` con `numeros[0]`, no con un número inventado.

---

## Búsqueda secuencial — ¿existe el valor?

```c
int numeros[5] = {10, 25, 30, 45, 50};
int buscado = 30;
int encontrado = 0;   // 0 = no encontrado
int i;

for (i = 0; i < 5; i = i + 1) {
    if (numeros[i] == buscado) {
        encontrado = 1;
    }
}

if (encontrado == 1) {
    printf("El valor %d esta en el arreglo.\n", buscado);
} else {
    printf("El valor %d no esta en el arreglo.\n", buscado);
}
```

---

## Búsqueda — encontrar la posición

```c
int numeros[6] = {8, 14, 21, 14, 35, 42};
int buscado = 14;
int posicion = -1;   // -1 = no encontrado (nunca es un índice válido)
int i;

for (i = 0; i < 6; i = i + 1) {
    if (numeros[i] == buscado) {
        posicion = i;
        break;   // encontrado → no hace falta seguir
    }
}

if (posicion != -1) {
    printf("Encontrado en posicion %d.\n", posicion);
} else {
    printf("No se encontro.\n");
}
```

> **¿Por qué `-1`?** Porque ningún índice válido puede ser `-1`.

---

## Inserción en el medio del arreglo

Para insertar en una posición, hay que **desplazar** los elementos hacia la derecha primero.

```c
int numeros[6] = {10, 20, 40, 50};   // 4 elementos, capacidad para 6
int cantidad = 4;
int posicion = 2;   // insertar en posición 2
int nuevo = 30;
int i;

// Desplazar desde el final hacia la posición de inserción
for (i = cantidad; i > posicion; i = i - 1) {
    numeros[i] = numeros[i - 1];
}

numeros[posicion] = nuevo;
cantidad = cantidad + 1;
```

**Antes:** `10 20 40 50`  
**Después:** `10 20 30 40 50`

> ⚠️ El desplazamiento va **desde el final hacia la posición**, no al revés (si no, se pisan valores).

---

## Recorrido de matriz con ciclos anidados

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
int i, j;

for (i = 0; i < 2; i = i + 1) {
    for (j = 0; j < 3; j = j + 1) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
```

**Salida:**
```
1 2 3
4 5 6
```

---

## Errores comunes

| Error | Correcto |
|-------|---------|
| Acceder a `numeros[5]` en arreglo de 5 | Último índice = 4 |
| Confundir cantidad (5) con último índice (4) | Siempre cantidad - 1 |
| Inicializar `mayor` con 0 (puede no ser válido) | Usar `numeros[0]` |
| Desplazar de izquierda a derecha al insertar | Desplazar de **derecha a izquierda** |
| Olvidar inicializar `suma=0`, `encontrado=0`, `posicion=-1` | Siempre valor de arranque correcto |

---

## Resumen rápido
- **Recorrido:** ciclo `for` de `0` a `cantidad - 1`.
- **Sumar:** acumulador inicializado en `0`.
- **Mayor:** inicializar con `numeros[0]`, comparar el resto.
- **Búsqueda:** flag `encontrado=0` o `posicion=-1`; `break` al encontrar.
- **Inserción:** desplazar elementos de derecha a izquierda, luego guardar.
- **Matriz:** dos ciclos anidados (filas y columnas).
