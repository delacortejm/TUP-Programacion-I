# 08 · Operador Ternario

## ¿Qué es?
Un operador que **elige entre dos valores** según una condición.  
Se llama ternario porque trabaja con **tres partes**.

---

## Sintaxis

```c
condicion ? valor_si_verdadero : valor_si_falso
```

Leelo así: *"si la condición es verdadera, usar este valor; si no, usar este otro"*.

---

## Ejemplo básico

```c
int edad = 20;
int esMayor = edad >= 18 ? 1 : 0;
// esMayor = 1
```

---

## Equivalencia con `if-else`

```c
// Con ternario
int numero = 8;
char* tipo = numero % 2 == 0 ? "par" : "impar";

// Con if-else (misma lógica)
char* tipo;
if (numero % 2 == 0) {
    tipo = "par";
} else {
    tipo = "impar";
}
```

---

## Diferencia clave con `if-else`

| | `if-else` | Operador ternario |
|-|-----------|------------------|
| Es... | Estructura de control | **Operador** (produce un valor) |
| Produce un valor | No directamente | ✅ Sí |
| Uso típico | Ejecutar bloques | Asignar un valor según condición |

```c
int menor = a < b ? a : b;   // ternario produce un valor → se asigna
```

---

## Ejemplo útil: elegir el menor de dos números

```c
#include <stdio.h>

int main() {
    int a = 12, b = 5;
    int menor = a < b ? a : b;
    printf("El menor es: %d\n", menor);
    return 0;
}
```

---

## ¿Cuándo usarlo?

✅ Cuando:
- La condición es clara y corta.
- Solo hay dos posibles resultados.
- Querés obtener un valor directamente.

❌ No usarlo cuando:
- La condición es larga o compleja.
- Hay varios pasos dentro de cada camino.
- Perdés claridad de lectura.

> Si el código se vuelve difícil de leer, volvé a `if-else`.

---

## Errores comunes
- Creer que reemplaza siempre a `if-else`.
- Confundir el orden: `condicion ? verdadero : falso`.
- Anidar ternarios dentro de ternarios (evitarlo).

---

## Resumen rápido
- Forma general: `condicion ? valor_si_verdadero : valor_si_falso`
- Es un operador, no una estructura de control → produce un valor.
- Útil para decisiones simples de una línea.
- Si complica la lectura, usar `if-else`.
