# 09 · Switch y Bloques

## ¿Cuándo usar `switch`?
Cuando querés comparar **una misma variable contra varios valores posibles**.

```c
switch (variable) {
    case valor1:
        instrucciones;
        break;

    case valor2:
        instrucciones;
        break;

    default:
        instrucciones;
}
```

---

## Ejemplo básico

```c
#include <stdio.h>

int main() {
    int dia = 3;

    switch (dia) {
        case 1:
            printf("Lunes\n");
            break;
        case 2:
            printf("Martes\n");
            break;
        case 3:
            printf("Miércoles\n");
            break;
        default:
            printf("Valor no válido\n");
    }

    return 0;
}
```

---

## `break` — salir del switch

Cuando se ejecuta el `case` que corresponde, `break` **sale del switch**.

> ⚠️ Si olvidás `break`, el programa **continúa ejecutando el siguiente `case`** aunque no corresponda.

```c
// Sin break — problema:
switch (opcion) {
    case 1:
        printf("Opción 1\n");   // se ejecuta
    case 2:
        printf("Opción 2\n");   // ¡también se ejecuta si opcion=1!
        break;
}
```

**Regla práctica:** si no querés que siga al siguiente caso, usá `break`.

---

## `default` — caso por defecto

Se ejecuta cuando **ningún `case` coincide**.

```c
default:
    printf("Opción no válida\n");
```

No es obligatorio, pero casi siempre conviene tenerlo.

---

## Bloques de código `{}`
Conjunto de sentencias encerradas entre llaves.

```c
{
    printf("Hola\n");
    printf("Mundo\n");
}
```

Aparecen en: `if`, `else`, `switch`, `while`, `for`, `do-while`.

---

## Instrucciones que alteran el flujo de un bloque

| Instrucción | Dónde | Efecto |
|-------------|-------|--------|
| `break` | `switch`, ciclos | Sale del bloque/ciclo |
| `continue` | Ciclos | Salta a la siguiente iteración |
| `return` | Funciones | Termina la función actual |

---

## Errores comunes
- **Olvidar `break`** → el caso "cae" al siguiente.
- Usar `switch` para cualquier decisión (conviene cuando comparás una variable contra valores concretos).
- Mala indentación → el código queda imposible de leer.

---

## Resumen rápido
- `switch` → elegir entre varias opciones según el valor de una variable.
- `case` → cada alternativa posible.
- `break` → corta la ejecución del `switch`.
- `default` → caso si no hubo coincidencias.
- Los bloques `{}` agrupan instrucciones relacionadas.
