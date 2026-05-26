# 10 · While

## ¿Qué es una iteración?
Cada **repetición** de un conjunto de instrucciones.

---

## `while` — repetir mientras una condición sea verdadera

```c
while (condicion) {
    instrucciones;
}
```

### Los tres elementos de un ciclo bien diseñado

| Elemento | Qué es |
|----------|--------|
| **Estado inicial** | Valor de partida de la/s variable/s del ciclo |
| **Condición** | Cuándo continuar iterando |
| **Actualización** | Cómo cambia el estado para acercarse al fin |

---

## Ejemplo básico

```c
#include <stdio.h>

int main() {
    int i = 1;               // estado inicial

    while (i <= 5) {         // condición
        printf("%d\n", i);
        i = i + 1;           // actualización
    }

    return 0;
}
```

### Evolución iteración a iteración

| Iteración | `i` al entrar | Imprime | `i` al salir |
|-----------|--------------|---------|--------------|
| 1 | 1 | 1 | 2 |
| 2 | 2 | 2 | 3 |
| 3 | 3 | 3 | 4 |
| 4 | 4 | 4 | 5 |
| 5 | 5 | 5 | 6 |
| — | 6 | (condición falsa, sale) | — |

---

## Ciclo infinito ⚠️
Ocurre cuando la condición **nunca se vuelve falsa**.

```c
// ❌ Error: i nunca cambia
while (i <= 5) {
    printf("%d\n", i);
    // falta i = i + 1
}
```

> Siempre preguntate: **¿qué acción dentro del ciclo acerca el programa al final?**

---

## `break` — salir del ciclo antes de tiempo

```c
while (i <= 10) {
    if (i == 5) {
        break;   // sale cuando i vale 5
    }
    printf("%d\n", i);
    i = i + 1;
}
```

---

## `continue` — saltar al siguiente paso

```c
while (i <= 5) {
    i = i + 1;

    if (i == 3) {
        continue;   // salta al while, no imprime el 3
    }

    printf("%d\n", i);
}
```

---

## ¿Cuándo usar `while`?
Cuando la repetición **depende de una condición** y no es necesario saber de antemano cuántas veces se repite.

---

## Resumen rápido
- `while` repite mientras la condición sea verdadera.
- Diseñar bien un `while`: estado inicial + condición + actualización.
- Sin actualización → ciclo infinito.
- `break` corta el ciclo; `continue` salta a la siguiente iteración.
