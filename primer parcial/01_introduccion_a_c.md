# 01 · Introducción a C

## ¿Qué es un programa?
Un **programa** es un conjunto de instrucciones escritas de forma ordenada para que una computadora realice una tarea.  
La computadora no puede completar pasos faltantes: necesita instrucciones **claras, concretas y ordenadas**.

> **Regla clave:** primero pensás → después organizás → recién al final escribís código.

---

## ¿Qué es un lenguaje de programación?
Un lenguaje formal con reglas precisas de sintaxis y significado que nos permite comunicarnos con la computadora.  
En C, el código fuente se **compila** para generar un ejecutable.

---

## ¿Qué es C y por qué aprenderlo?
- Lenguaje eficiente y cercano al hardware.
- Obliga a ser preciso con datos e instrucciones.
- Da una base sólida para aprender otros lenguajes.
- No "esconde" lo que pasa internamente → ideal para aprender fundamentos.

---

## Paradigmas de programación
Un **paradigma** es una forma de pensar y organizar la solución de un problema.

| Paradigma | Idea central | ¿Lo usa C? |
|-----------|-------------|------------|
| **Imperativo** | Indicar paso a paso qué hacer | ✅ |
| **Procedural** | Organizar el programa en bloques/funciones | ✅ |
| Orientado a objetos | Organizar en objetos con datos y comportamiento | No |
| Funcional | Foco en transformación de datos con funciones | No |

---

## Buenas prácticas desde el día uno
1. **Código claro** — que se pueda leer, no solo que compile.
2. **Nombres descriptivos** — `int edad` en vez de `int x`.
3. **Código ordenado** — sangría consistente, espacios.
4. **Comentar con criterio** — aclarar intenciones, no repetir lo obvio.
5. **No escribir lo que no entendés** — primero entendé, después codificá.
6. **Respetar la sintaxis** — paréntesis, llaves, `;`, mayúsculas/minúsculas importan.

---

## Estructura de un programa en C

```c
#include <stdio.h>

int main() {
    printf("Hola, mundo\n");
    return 0;
}
```

| Parte | Qué es |
|-------|--------|
| `#include <stdio.h>` | Directiva de preprocesador — incluye herramientas de entrada/salida |
| `int main()` | Punto de entrada del programa |
| `{ }` | Bloque de instrucciones de `main` |
| `printf(...)` | Sentencia que muestra texto en pantalla |
| `return 0;` | Indica que el programa terminó correctamente |

---

## Comentarios en C

```c
// Comentario de una línea

/*
   Comentario
   de varias líneas
*/
```

---

## Resumen rápido
- Un programa = secuencia de instrucciones para resolver una tarea.
- Lenguaje de programación = herramienta para escribir esas instrucciones.
- Paradigma = forma de organizar y pensar la solución.
- C usa los paradigmas **imperativo** y **procedural**.
- Todo programa básico en C tiene: `#include`, `main`, llaves, sentencias y `return 0`.
