# 12 · Do-While

## Diferencia fundamental con `while`

| | `while` | `do-while` |
|-|---------|-----------|
| Evalúa la condición | **Antes** de entrar al bloque | **Después** de ejecutar el bloque |
| Ejecuciones mínimas | 0 (puede no ejecutarse) | **1** (siempre ejecuta al menos una vez) |

---

## Sintaxis

```c
do {
    instrucciones;
} while (condicion);
//                 ^--- no olvidar el punto y coma
```

---

## Ejemplo básico

```c
#include <stdio.h>

int main() {
    int i = 1;

    do {
        printf("%d\n", i);
        i = i + 1;
    } while (i <= 5);

    return 0;
}
```

---

## Ejemplo donde la diferencia importa

```c
int numero = 10;

do {
    printf("El número es %d\n", numero);
} while (numero < 5);
```

Aunque `numero < 5` es **falso**, el bloque se ejecuta **una vez** porque la condición se evalúa al final.

Con `while` normal, el bloque no se ejecutaría nunca.

---

## ¿Cuándo usar `do-while`?
Cuando necesitás garantizar que el bloque se ejecute **al menos una vez** antes de verificar si debe repetirse.

Ejemplo típico: menú de opciones que siempre debe mostrarse al menos una vez.

```c
int opcion;

do {
    printf("1. Opción A\n");
    printf("2. Salir\n");
    printf("Elegí: ");
    scanf("%d", &opcion);
} while (opcion != 2);
```

---

## Errores comunes
- Creer que `while` y `do-while` son iguales (no lo son: difiere cuándo se evalúa la condición).
- **Olvidar el `;`** al final de `while (condicion);`.

---

## Resumen rápido
- `do-while` evalúa la condición **al final**.
- El bloque se ejecuta **siempre al menos una vez**.
- No olvidar el `;` después del `while (condicion)`.
- Útil cuando necesitás garantizar una primera ejecución.
