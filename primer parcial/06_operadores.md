# 06 · Operadores

## ¿Qué es un operador?
Símbolo que representa una acción sobre uno o más valores.  
Una **expresión** es una combinación de valores, variables y operadores que produce un resultado.

---

## Operadores matemáticos

| Operador | Operación | Ejemplo | Resultado |
|----------|-----------|---------|-----------|
| `+` | Suma | `10 + 5` | `15` |
| `-` | Resta | `10 - 5` | `5` |
| `*` | Multiplicación | `4 * 3` | `12` |
| `/` | División | `10 / 2` | `5` |
| `%` | Resto (módulo) | `10 % 3` | `1` |

> ⚠️ **División entre enteros:** `5 / 2` da `2`, no `2.5`. El tipo de dato afecta el resultado.  
> `%` solo tiene sentido con enteros.

---

## Operadores de asignación

| Operador | Significado | Equivale a |
|----------|-------------|------------|
| `=` | Asignación simple | — |
| `+=` | Suma y asigna | `x = x + n` |
| `-=` | Resta y asigna | `x = x - n` |
| `*=` | Multiplica y asigna | `x = x * n` |
| `/=` | Divide y asigna | `x = x / n` |
| `%=` | Resto y asigna | `x = x % n` |

```c
int puntos = 10;
puntos += 5;   // puntos = 15

int edad = 18;
edad = edad + 1;   // edad = 19
```

> ⚠️ En C, `=` **asigna**. No es "igual" matemático.

---

## Operadores relacionales (comparan valores)

| Operador | Significado |
|----------|------------|
| `==` | Igual que |
| `!=` | Distinto de |
| `>` | Mayor que |
| `<` | Menor que |
| `>=` | Mayor o igual que |
| `<=` | Menor o igual que |

```c
edad == 18    // ¿es igual a 18?
nota >= 6     // ¿es 6 o más?
precio < 1000 // ¿es menor que 1000?
```

> ⚠️ `=` asigna · `==` compara — **no los confundas**.

---

## Operadores lógicos (combinan condiciones)

| Operador | Significado | Verdadero cuando... |
|----------|------------|-------------------|
| `&&` | Y (AND) | Ambas condiciones son verdaderas |
| `\|\|` | O (OR) | Al menos una es verdadera |
| `!` | NO (NOT) | La condición es falsa |

```c
edad >= 18 && edad <= 65     // entre 18 y 65
letra == 'a' || letra == 'A' // minúscula o mayúscula
!(edad == 18)                // no tiene 18
```

---

## Precedencia de operadores (orden de evaluación)

| Prioridad | Operadores |
|-----------|-----------|
| 1 (mayor) | `()` paréntesis |
| 2 | `*` `/` `%` |
| 3 | `+` `-` |
| 4 | `>` `<` `>=` `<=` |
| 5 | `==` `!=` |
| 6 | `&&` |
| 7 | `\|\|` |
| 8 (menor) | `=` y combinados |

```c
int resultado = 2 + 3 * 4;   // = 14  (primero 3*4=12, luego 2+12)
int resultado = (2 + 3) * 4; // = 20  (paréntesis primero)
```

> Usá paréntesis para aclarar la intención, no solo para cambiar el orden.

---

## Errores comunes
- Confundir `=` (asignación) con `==` (comparación).
- Olvidar la precedencia: `2 + 3 * 4` no da `20`.
- Creer que `/` siempre conserva decimales (con enteros no).
- No pensar en el tipo de dato al operar.

---

## Resumen rápido
- Operadores matemáticos: `+` `-` `*` `/` `%`
- Operadores de asignación: `=` `+=` `-=` etc.
- Operadores relacionales: `==` `!=` `>` `<` `>=` `<=`
- Operadores lógicos: `&&` `||` `!`
- `=` ≠ `==`
- Precedencia define el orden; paréntesis la controlan.
