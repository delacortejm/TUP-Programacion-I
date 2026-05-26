# 07 · If-Else

## ¿Qué es una decisión?
Cuando el programa evalúa una condición y ejecuta un bloque u otro según el resultado.

> Una **condición** es una expresión que resulta verdadera o falsa: `edad >= 18`, `nota < 6`.

---

## `if` — ejecutar si es verdadero

```c
if (condicion) {
    instrucciones;
}
```

```c
int edad = 20;

if (edad >= 18) {
    printf("Es mayor de edad\n");
}
```

Si la condición es **falsa**, el bloque se **omite**.

---

## `if-else` — elegir entre dos caminos

```c
if (condicion) {
    instrucciones_si_verdadero;
} else {
    instrucciones_si_falso;
}
```

```c
int numero = 5;

if (numero % 2 == 0) {
    printf("El número es par\n");
} else {
    printf("El número es impar\n");
}
```

El programa **elige uno** de los dos bloques, nunca ejecuta ambos.

---

## Llaves `{}`
Delimitan el bloque de instrucciones de cada rama.

```c
if (edad >= 18) {
    printf("Mayor de edad\n");
    printf("Puede continuar\n");   // ambas pertenecen al if
}
```

> **Buena práctica:** usá llaves siempre, aunque haya una sola instrucción.

---

## Sentencias anidadas
Un `if` dentro de otro `if`.

```c
int numero = 0;

if (numero >= 0) {
    if (numero == 0) {
        printf("El número es cero\n");
    } else {
        printf("El número es positivo\n");
    }
} else {
    printf("El número es negativo\n");
}
```

Conviene anidar cuando una segunda decisión **depende** de la primera.  
No abusar: demasiados niveles hacen el código difícil de leer.

---

## Flujo del programa

```
se evalúa la condición
   ├─ verdadera → bloque del if
   └─ falsa     → bloque del else (si existe)
continúa el resto del programa
```

---

## Errores comunes
- Usar `=` en vez de `==` dentro de la condición.
- Olvidar llaves cuando el bloque crece.
- No pensar qué camino toma el programa en cada caso.
- Anidar más de lo necesario.

---

## Resumen rápido
- `if` ejecuta un bloque solo si la condición es verdadera.
- `if-else` permite elegir entre dos caminos.
- Las llaves delimitan cada bloque.
- Las sentencias anidadas permiten decisiones dentro de decisiones.
