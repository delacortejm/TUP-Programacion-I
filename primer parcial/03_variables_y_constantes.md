# 03 · Variables y Constantes

## ¿Qué es una variable?
Espacio de memoria con **tipo**, **nombre** y **valor que puede cambiar**.

```c
int edad = 18;
//  ^tipo  ^nombre  ^valor
```

---

## Declarar, inicializar y asignar

| Operación | Cuándo ocurre | Ejemplo |
|-----------|--------------|---------|
| **Declarar** | Al crear la variable | `int edad;` |
| **Inicializar** | Al declarar + dar valor | `int edad = 18;` |
| **Asignar** | Después de declarar | `edad = 18;` |

> Siempre que sea posible, **inicializá** las variables para que el programa sepa con qué valor empieza.

---

## Tipos básicos

| Tipo | Para qué | Ejemplo |
|------|----------|---------|
| `int` | Números enteros | `int cantidad = 25;` |
| `float` | Números con decimales | `float altura = 1.75;` |
| `char` | Un solo carácter | `char inicial = 'F';` |

> Los valores `char` van entre **comillas simples**: `'A'`, `'#'`.

---

## El valor de una variable puede cambiar

```c
int edad = 18;
edad = 19;   // ahora vale 19
```

---

## Reglas para nombrar variables

**Válido:** letras, números, guion bajo `_`. Debe empezar con letra o `_`.  
**Inválido:** empezar con número, tener espacios, usar palabras reservadas (`float`, `int`, etc.), usar guion medio `-`.

```c
// ✅ Válidos
int cantidadAlumnos;
float precioFinal;
char _inicial;

// ❌ Inválidos
int 1edad;       // empieza con número
int mi edad;     // tiene espacio
int float;       // palabra reservada
```

---

## Buenas prácticas de nombres
- Usá nombres que **describan el dato**: `precioProducto` > `p`.
- Mantené un estilo consistente (ej: camelCase).

---

## Constantes con `const`
Dato cuyo valor **no debe cambiar** durante la ejecución.

```c
const int diasSemana = 7;
const int mesesAnio  = 12;
const float PI       = 3.14159;
```

| | Variable | Constante |
|--|---------|-----------|
| Puede cambiar | ✅ | ❌ |
| Declaración | `int edad = 18;` | `const int diasSemana = 7;` |

> Usá `const` cuando el valor representa una **regla fija** del programa.

---

## Errores comunes
- Confundir el **nombre** con el **valor** (`edad` ≠ `18`).
- Creer que declarar = inicializar (no es lo mismo).
- Nombres poco claros: `int a;` no dice nada.
- Usar una variable sin haberle dado un valor confiable.
- Declarar como variable algo que debería ser constante.

---

## Resumen rápido
- Variable = espacio de memoria con tipo, nombre y valor cambiable.
- Constante = dato fijo declarado con `const`.
- Tipos básicos al empezar: `int`, `float`, `char`.
- Declarar ≠ inicializar ≠ asignar.
- Buenos nombres hacen el código legible.
