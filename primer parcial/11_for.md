# 11 · For

## ¿Qué hace `for`?
Repite un bloque y concentra en **una sola línea** los tres elementos del ciclo.

```c
for (inicializacion; condicion; actualizacion) {
    instrucciones;
}
```

---

## Ejemplo básico

```c
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 5; i = i + 1) {
        printf("%d\n", i);
    }

    return 0;
}
```

### Las tres partes del `for`

| Parte | En el ejemplo | Cuándo se ejecuta |
|-------|--------------|-------------------|
| Inicialización | `i = 1` | Una sola vez al comienzo |
| Condición | `i <= 5` | Antes de cada iteración |
| Actualización | `i = i + 1` | Al final de cada vuelta |

---

## Equivalencia con `while`

```c
// for
for (i = 1; i <= 5; i = i + 1) {
    printf("%d\n", i);
}

// while equivalente
i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i = i + 1;
}
```

La lógica es la **misma**. `for` es más compacto cuando la estructura del ciclo está bien definida.

---

## ¿Cuándo usar `for`?
Cuando la repetición está asociada a un **contador** o una cantidad de pasos clara:
- Mostrar los números del 1 al 10.
- Repetir una acción 5 veces.
- Recorrer posiciones de un arreglo.

---

## `break` en `for`

```c
for (i = 1; i <= 10; i = i + 1) {
    if (i == 6) {
        break;   // corta el ciclo
    }
    printf("%d\n", i);
}
```

---

## `continue` en `for`

```c
for (i = 1; i <= 5; i = i + 1) {
    if (i == 3) {
        continue;   // salta la impresión cuando i=3
    }
    printf("%d\n", i);
}
```

---

## Error conceptual frecuente
`for` no es "otro tipo de magia". La idea profunda es la misma que `while`: **repetir mientras una condición lo permita**. Solo cambia la organización visual.

---

## Resumen rápido
- `for` organiza en una línea: inicialización, condición y actualización.
- Ideal para ciclos con contador o cantidad de repeticiones definida.
- `break` corta; `continue` salta.
- Conceptualmente igual a `while`, diferente forma.
