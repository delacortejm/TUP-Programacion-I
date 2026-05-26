# 04 · Entrada y Salida

## Conceptos

| Término | Qué es |
|---------|--------|
| **Salida** | El programa muestra información (ej: pantalla) |
| **Entrada** | El programa recibe información (ej: teclado) |

---

## `printf` — mostrar en pantalla

```c
printf("Hola, mundo\n");          // texto fijo
printf("La edad es %d\n", edad);  // texto + variable
```

### `\n` = salto de línea

### Especificadores de formato

| Tipo | Especificador |
|------|--------------|
| `int` | `%d` |
| `float` | `%f` |
| `char` | `%c` |

```c
int edad = 18;
float altura = 1.75;
char inicial = 'F';

printf("Edad: %d\n", edad);
printf("Altura: %f\n", altura);
printf("Inicial: %c\n", inicial);
```

---

## `scanf` — leer datos del usuario

```c
scanf("especificador", &variable);
```

```c
int edad;
printf("Ingrese su edad: ");
scanf("%d", &edad);
printf("Usted tiene %d años\n", edad);
```

### ¿Por qué `&`?
El `&` le dice a `scanf` **dónde guardar** el dato en memoria.  
Regla práctica: con `scanf`, para `int`, `float` y `char`, **siempre** `&` antes de la variable.

---

## Problema clásico con `%c` y el Enter

Cuando primero leés un número y después un `char`, el `\n` del Enter puede quedar en el buffer y `scanf` lo lee como el carácter.

**Solución:** poner un espacio antes de `%c`:

```c
scanf(" %c", &inicial);   // el espacio descarta whitespace previo
```

---

## Ejemplo completo

```c
#include <stdio.h>

int main() {
    int edad;
    float altura;
    char inicial;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese su altura: ");
    scanf("%f", &altura);

    printf("Ingrese la inicial de su nombre: ");
    scanf(" %c", &inicial);

    printf("Edad: %d\n", edad);
    printf("Altura: %f\n", altura);
    printf("Inicial: %c\n", inicial);

    return 0;
}
```

---

## Errores comunes

| Error | Correcto |
|-------|---------|
| Olvidar `#include <stdio.h>` | Siempre incluirlo si usás `printf`/`scanf` |
| Olvidar `;` al final | `printf("Hola");` |
| Especificador equivocado (`%f` para `int`) | Usar `%d` para `int`, `%f` para `float`, `%c` para `char` |
| Olvidar `&` en `scanf` | `scanf("%d", &edad);` |
| `scanf("%c", ...)` después de leer un número | Usar `scanf(" %c", &var);` |

---

## Resumen rápido
- `printf()` muestra datos; `scanf()` los lee.
- Especificadores: `%d` (int), `%f` (float), `%c` (char).
- `scanf` necesita `&` antes de la variable.
- Para leer `char` después de un número: `" %c"` con espacio.
