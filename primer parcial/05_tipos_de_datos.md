# 05 · Tipos de Datos

## ¿Qué es un tipo de dato?
Clasificación que le indica al lenguaje:
- qué clase de valor se almacena
- qué operaciones tienen sentido
- cuánto espacio de memoria puede necesitar

---

## Tipos primitivos básicos

| Tipo | Para qué | Ejemplo |
|------|----------|---------|
| `int` | Enteros (sin decimales) | `int edad = 18;` |
| `float` | Decimales | `float altura = 1.75;` |
| `double` | Decimales con mayor precisión | `double distancia = 12345.67;` |
| `char` | Un solo carácter | `char letra = 'A';` |

---

## Dominio de cada tipo

| Tipo | Valores posibles |
|------|-----------------|
| `int` | Enteros: negativos, cero, positivos |
| `float` / `double` | Números reales con parte decimal |
| `char` | Un único carácter (letra, dígito, símbolo) |

> ⚠️ `'7'` (char) ≠ `7` (int). Son tipos distintos.

---

## Operaciones válidas según el tipo

```c
// int y float/double: operaciones matemáticas
int a = 10, b = 5;
int resultado = a + b;   // 15

float p1 = 10.5, p2 = 2.5;
float total = p1 + p2;   // 13.0

// char: representar un símbolo (al nivel inicial)
char inicial = 'F';
```

---

## Tipos y memoria
- `char` suele ocupar menos que `int`.
- `int` suele ocupar menos que `double`.
- El tamaño exacto puede depender del compilador y la arquitectura.

---

## Variables y constantes tipadas

```c
int edad = 18;             // variable
const int diasSemana = 7;  // constante — misma idea de tipo, valor fijo
```

---

## Datos compuestos y estructuras de datos

Cuando un solo tipo primitivo no alcanza, existen formas más complejas de organizar datos:

| Categoría | Ejemplos |
|-----------|---------|
| Datos compuestos | arreglos, cadenas, registros |
| Estructuras dinámicas | listas, pilas, colas, árboles |

### Estáticas vs Dinámicas

| | Estática | Dinámica |
|-|---------|---------|
| Tamaño | Fijo / predefinido | Puede crecer durante la ejecución |

---

## Errores comunes
- Creer que todos los datos son iguales.
- Elegir el tipo sin pensar qué representa el dato.
- Confundir `'7'` (char) con `7` (int).
- Asumir que el tamaño de cada tipo es fijo en cualquier máquina.
- Confundir tipo con variable (el tipo describe el dato; la variable es el nombre del espacio).

---

## Resumen rápido
- El tipo define qué se guarda, qué operaciones aplican y cómo se representa en memoria.
- Tipos primitivos al empezar: `int`, `float`, `double`, `char`.
- Cada tipo tiene un dominio de valores posibles.
- Variables y constantes siempre tienen un tipo.
- Existen estructuras de datos estáticas y dinámicas para organizar conjuntos de datos.
