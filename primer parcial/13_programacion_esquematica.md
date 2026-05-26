# 13 · Programación Esquemática

## ¿Qué es?
Forma de **diseñar programas** usando esquemas de control bien conocidos en vez de improvisar.

---

## Los tres esquemas base

| Esquema | Idea |
|---------|------|
| **Secuencia** | Una acción después de otra |
| **Selección** | Elegir entre caminos posibles |
| **Iteración** | Repetir acciones mientras una condición lo indique |

> La enorme mayoría de los programas puede pensarse combinando estos tres esquemas.

---

## Pensamiento esquemático: ejemplo

**Problema:** leer números, sumar solo los positivos, terminar con 0, mostrar la suma.

```
¿Qué estructuras reconozco?
├─ Iteración: leer varias veces
├─ Selección: sumar solo si el número es positivo
└─ Secuencia: inicializar → leer → procesar → mostrar
```

---

## Refinamiento sucesivo aplicado

**Nivel 1 (esquema general)**
```
inicializar datos → repetir lectura y procesamiento → mostrar resultado
```

**Nivel 2 (más detalle)**
```
declarar numero y suma
inicializar suma en 0
leer un número
mientras el número no sea 0:
    si es positivo, acumularlo
    leer otro número
mostrar la suma
```

**Nivel 3 (código)**
```c
#include <stdio.h>

int main() {
    int numero;
    int suma = 0;

    printf("Ingrese un número (0 para terminar): ");
    scanf("%d", &numero);

    while (numero != 0) {
        if (numero > 0) {
            suma = suma + numero;
        }
        printf("Ingrese un número (0 para terminar): ");
        scanf("%d", &numero);
    }

    printf("La suma es %d\n", suma);
    return 0;
}
```

---

## Sentencias anidadas
Una estructura de control dentro de otra.

| Combinación | Cuándo usarla |
|-------------|--------------|
| `if` dentro de `while` | Decidir algo en cada iteración |
| `while` dentro de `while` | Repetición dentro de repetición |
| `if` dentro de `if` | Decisión que depende de otra |

> Anidar está bien cuando mejora la lógica.  
> Demasiados niveles → código difícil de leer.

---

## Buenas prácticas
- Indentá correctamente.
- Usá llaves siempre.
- Cada bloque debe tener una intención clara.
- Pensá primero el esquema **antes** del código.
- Refiná de lo general a lo particular.

---

## Resumen rápido
- Programación esquemática = diseñar con secuencia, selección e iteración.
- Refinamiento sucesivo = pasar del problema al código gradualmente.
- Sentencias anidadas = combinar estructuras de control.
- Anidar bien → lógica clara. Anidar de más → desorden.
