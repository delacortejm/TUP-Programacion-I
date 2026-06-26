# Cheatsheet de Programación I — Examen

> Referencia rápida para usar durante el examen.
> Estilo: C estándar con `conio.h`, `getch()`, `gets()`. Variables y comentarios en español.

---

## 📑 Índice

1. [Errores típicos de sintaxis (LEER PRIMERO)](#1-errores-típicos-de-sintaxis)
2. [Búsqueda lineal](#2-búsqueda-lineal)
3. [Búsqueda binaria](#3-búsqueda-binaria)
4. [Ordenamiento - Bubble Sort (burbuja)](#4-ordenamiento---bubble-sort)
5. [Ordenamiento - Selección](#5-ordenamiento---selección)
6. [Ordenamiento - Inserción](#6-ordenamiento---inserción)
7. [Recursividad](#7-recursividad)
8. [Punteros y malloc (lo mínimo)](#8-punteros-y-malloc)
9. [Listas enlazadas simples](#9-listas-enlazadas-simples)
10. [Listas doblemente enlazadas](#10-listas-doblemente-enlazadas)
11. [Árboles binarios (BST/ABB)](#11-árboles-binarios)
12. [Plantilla base de programa](#12-plantilla-base)

---

## 1. Errores típicos de sintaxis

**Revisar SIEMPRE antes de entregar:**

| ❌ Mal | ✅ Bien |
|---|---|
| `int x = 0` | `int x = 0;` |
| `for(i=0, i<5, i++)` | `for(i=0; i<5; i++)` |
| `if x == 5` | `if(x == 5)` |
| `if(x == 5);` | `if(x == 5)` (sin `;` después del if) |
| `scanf("%d", x)` | `scanf("%d", &x)` |
| `scanf("%.2f", &x)` | `scanf("%f", &x)` (el `.2` es solo para printf) |
| `struct Persona { ... }` | `struct Persona { ... };` (con `;` al final) |
| `x = 5` (comparar) | `x == 5` (con doble `=`) |

**Reglas oro:**
- `&` solo en `scanf`, NUNCA en `printf`.
- `gets()` para texto (sin `&`). `scanf("%d", &x)` para números.
- Antes de `gets()` después de un `scanf` numérico → `fflush(stdin);`
- `TAM` y `tam` son DISTINTOS (C distingue mayúsculas).

---

## 2. Búsqueda lineal

**Idea:** Recorrer el arreglo de principio a fin comparando cada elemento.

```c
#include <stdio.h>
#include <conio.h>
#define TAM 5

int main()
{
    int arr[TAM] = {10, 25, 7, 42, 18};
    int i, buscado;
    int posicion = -1;  // marcador de "no encontrado"

    printf("Ingrese numero a buscar: ");
    scanf("%d", &buscado);

    for(i = 0; i < TAM; i++)
    {
        if(arr[i] == buscado)
        {
            posicion = i;
        }
    }

    if(posicion == -1)
        printf("No encontrado");
    else
        printf("Encontrado en posicion %d", posicion);

    getch();
    return 0;
}
```

**Variante con while (corta cuando lo encuentra):**

```c
i = 0;
posicion = -1;
while(i < TAM && posicion == -1)
{
    if(arr[i] == buscado)
        posicion = i;
    i++;
}
```

---

## 3. Búsqueda binaria

**REQUISITO:** el arreglo TIENE que estar ordenado.

**Idea:** Mirar el medio, descartar la mitad, repetir.

```c
int izq = 0;
int der = TAM - 1;
int medio;
int posicion = -1;
int buscado;

scanf("%d", &buscado);

while(izq <= der && posicion == -1)
{
    medio = (izq + der) / 2;

    if(arr[medio] == buscado)
        posicion = medio;
    else if(buscado < arr[medio])
        der = medio - 1;   // buscar en mitad izquierda
    else
        izq = medio + 1;   // buscar en mitad derecha
}

if(posicion == -1)
    printf("No encontrado");
else
    printf("Encontrado en posicion %d", posicion);
```

---

## 4. Ordenamiento - Bubble Sort

**Idea:** Comparar pares de elementos vecinos. Si están desordenados, intercambiar. Repetir hasta que esté ordenado.

```c
#include <stdio.h>
#include <conio.h>
#define TAM 5

int main()
{
    int arr[TAM] = {30, 10, 50, 20, 40};
    int i, j, aux;

    // BUBBLE SORT (de menor a mayor)
    for(i = 0; i < TAM - 1; i++)
    {
        for(j = 0; j < TAM - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])  // si esta desordenado, intercambio
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

    // Mostrar
    for(i = 0; i < TAM; i++)
        printf("%d ", arr[i]);

    getch();
    return 0;
}
```

**Para ordenar de MAYOR a menor:** cambiar `>` por `<` en el if.

**Patrón de intercambio (memorizar):**
```c
aux = a;
a = b;
b = aux;
```

---

## 5. Ordenamiento - Selección

**Idea:** Buscar el mínimo de lo que queda y ponerlo al principio.

```c
int i, j, posMin, aux;

for(i = 0; i < TAM - 1; i++)
{
    posMin = i;  // supongo que el actual es el menor

    // Busco el menor desde i+1 hasta el final
    for(j = i + 1; j < TAM; j++)
    {
        if(arr[j] < arr[posMin])
            posMin = j;
    }

    // Intercambio el menor con la posicion i
    if(posMin != i)
    {
        aux = arr[i];
        arr[i] = arr[posMin];
        arr[posMin] = aux;
    }
}
```

---

## 6. Ordenamiento - Inserción

**Idea:** Como ordenar cartas en la mano. Cada elemento se "inserta" en el lugar correcto entre los anteriores.

```c
int i, j, actual;

for(i = 1; i < TAM; i++)
{
    actual = arr[i];   // el elemento que voy a insertar
    j = i - 1;

    // Corro hacia la derecha los mayores que "actual"
    while(j >= 0 && arr[j] > actual)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = actual;  // inserto en su lugar
}
```

---

## 7. Recursividad

**Reglas:** Toda función recursiva tiene:
1. **Caso base** → condición de salida (sin esto se cuelga).
2. **Caso recursivo** → se llama a sí misma con un parámetro **más chico**.

### Factorial: n! = n × (n-1)!

```c
int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
```

### Potencia: base^exp = base × base^(exp-1)

```c
int potencia(int base, int exp)
{
    if(exp == 0)
        return 1;
    return base * potencia(base, exp - 1);
}
```

### Suma de 1 a N

```c
int sumaHasta(int n)
{
    if(n == 0)
        return 0;
    return n + sumaHasta(n - 1);
}
```

### Fibonacci (n-ésimo término)

```c
int fibonacci(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Contar dígitos de un número

```c
int contarDigitos(int n)
{
    if(n < 10)
        return 1;
    return 1 + contarDigitos(n / 10);
}
```

### Patrón general

```c
tipo funcionRecursiva(parametros)
{
    if(/* CASO BASE */)
        return /* valor base */;
    return /* algo */ funcionRecursiva(/* parametro reducido */);
}
```

---

## 8. Punteros y malloc

### Símbolos clave

| Símbolo | Significado |
|---|---|
| `int *p` | declara p como puntero a int |
| `&x` | dirección de x |
| `*p` | valor al que apunta p |
| `p->campo` | accede al campo del struct apuntado por p |
| `NULL` | "no apunta a nada" |

### Pedir memoria con malloc

```c
#include <stdlib.h>

struct Nodo *nuevo;
nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));

// Verificar que no haya fallado
if(nuevo == NULL)
{
    printf("Error de memoria");
    return -1;
}
```

### Regla `.` vs `->`

- Struct directo → punto: `alumno.nombre`
- Puntero a struct → flecha: `puntero->nombre`

---

## 9. Listas enlazadas simples

### Definición del nodo

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Nodo
{
    int dato;
    struct Nodo *siguiente;  // puntero al siguiente nodo
};
```

### Insertar al INICIO

```c
struct Nodo* insertarInicio(struct Nodo *lista, int valor)
{
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = lista;  // el nuevo apunta a lo que era antes el inicio
    return nuevo;              // ahora el nuevo es el inicio
}

// Uso:
// lista = insertarInicio(lista, 5);
```

### Insertar al FINAL

```c
struct Nodo* insertarFinal(struct Nodo *lista, int valor)
{
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    // Si la lista esta vacia, el nuevo es el inicio
    if(lista == NULL)
        return nuevo;

    // Si no, recorro hasta el ultimo nodo
    struct Nodo *aux = lista;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;  // el ultimo apunta al nuevo
    return lista;
}
```

### Mostrar la lista

```c
void mostrarLista(struct Nodo *lista)
{
    struct Nodo *aux = lista;
    while(aux != NULL)
    {
        printf("%d -> ", aux->dato);
        aux = aux->siguiente;
    }
    printf("NULL\n");
}
```

### Buscar un valor

```c
int buscar(struct Nodo *lista, int valor)
{
    struct Nodo *aux = lista;
    while(aux != NULL)
    {
        if(aux->dato == valor)
            return 1;   // encontrado
        aux = aux->siguiente;
    }
    return 0;  // no encontrado
}
```

### Eliminar un valor

```c
struct Nodo* eliminar(struct Nodo *lista, int valor)
{
    struct Nodo *aux = lista;
    struct Nodo *anterior = NULL;

    // Caso especial: la lista esta vacia
    if(lista == NULL)
        return NULL;

    // Caso especial: eliminar el primero
    if(lista->dato == valor)
    {
        aux = lista->siguiente;
        free(lista);
        return aux;
    }

    // Buscar el nodo a eliminar
    while(aux != NULL && aux->dato != valor)
    {
        anterior = aux;
        aux = aux->siguiente;
    }

    if(aux != NULL)
    {
        anterior->siguiente = aux->siguiente;
        free(aux);
    }

    return lista;
}
```

### Contar elementos

```c
int contar(struct Nodo *lista)
{
    int cant = 0;
    struct Nodo *aux = lista;
    while(aux != NULL)
    {
        cant++;
        aux = aux->siguiente;
    }
    return cant;
}
```

### Main de ejemplo

```c
int main()
{
    struct Nodo *lista = NULL;  // lista vacia

    lista = insertarFinal(lista, 10);
    lista = insertarFinal(lista, 20);
    lista = insertarFinal(lista, 30);
    lista = insertarInicio(lista, 5);

    mostrarLista(lista);  // imprime: 5 -> 10 -> 20 -> 30 -> NULL

    if(buscar(lista, 20))
        printf("20 esta en la lista\n");

    lista = eliminar(lista, 20);
    mostrarLista(lista);  // imprime: 5 -> 10 -> 30 -> NULL

    printf("Cantidad: %d", contar(lista));

    getch();
    return 0;
}
```

---

## 10. Listas doblemente enlazadas

**Diferencia:** Cada nodo tiene punteros a **siguiente** Y **anterior**. Se puede recorrer en ambas direcciones.

### Definición del nodo

```c
struct NodoD
{
    int dato;
    struct NodoD *siguiente;
    struct NodoD *anterior;
};
```

### Insertar al INICIO

```c
struct NodoD* insertarInicio(struct NodoD *lista, int valor)
{
    struct NodoD *nuevo = (struct NodoD*) malloc(sizeof(struct NodoD));
    nuevo->dato = valor;
    nuevo->siguiente = lista;
    nuevo->anterior = NULL;

    if(lista != NULL)
        lista->anterior = nuevo;  // el viejo inicio apunta para atras al nuevo

    return nuevo;
}
```

### Insertar al FINAL

```c
struct NodoD* insertarFinal(struct NodoD *lista, int valor)
{
    struct NodoD *nuevo = (struct NodoD*) malloc(sizeof(struct NodoD));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(lista == NULL)
    {
        nuevo->anterior = NULL;
        return nuevo;
    }

    struct NodoD *aux = lista;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    nuevo->anterior = aux;

    return lista;
}
```

### Mostrar hacia adelante

```c
void mostrarAdelante(struct NodoD *lista)
{
    struct NodoD *aux = lista;
    while(aux != NULL)
    {
        printf("%d <-> ", aux->dato);
        aux = aux->siguiente;
    }
    printf("NULL\n");
}
```

### Mostrar hacia atrás (desde el final)

```c
void mostrarAtras(struct NodoD *lista)
{
    if(lista == NULL) return;

    // Ir al ultimo
    struct NodoD *aux = lista;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    // Recorrer hacia atras
    while(aux != NULL)
    {
        printf("%d <-> ", aux->dato);
        aux = aux->anterior;
    }
    printf("NULL\n");
}
```

### Eliminar un valor (doble)

```c
struct NodoD* eliminar(struct NodoD *lista, int valor)
{
    if(lista == NULL) return NULL;

    struct NodoD *aux = lista;

    // Buscar el nodo
    while(aux != NULL && aux->dato != valor)
        aux = aux->siguiente;

    if(aux == NULL) return lista;  // no estaba

    // Caso: es el primero
    if(aux == lista)
    {
        lista = aux->siguiente;
        if(lista != NULL)
            lista->anterior = NULL;
        free(aux);
        return lista;
    }

    // Reconectar: el anterior apunta al siguiente, el siguiente al anterior
    aux->anterior->siguiente = aux->siguiente;
    if(aux->siguiente != NULL)
        aux->siguiente->anterior = aux->anterior;

    free(aux);
    return lista;
}
```

---

## 11. Árboles binarios

**Concepto:** Cada nodo tiene un dato y hasta DOS hijos: izquierdo y derecho.

**BST/ABB (Árbol Binario de Búsqueda):** Los menores van a la izquierda, los mayores a la derecha.

### Definición del nodo

```c
struct NodoA
{
    int dato;
    struct NodoA *izq;
    struct NodoA *der;
};
```

### Insertar (recursivo)

```c
struct NodoA* insertar(struct NodoA *raiz, int valor)
{
    // Caso base: si el lugar esta vacio, crear nodo aca
    if(raiz == NULL)
    {
        struct NodoA *nuevo = (struct NodoA*) malloc(sizeof(struct NodoA));
        nuevo->dato = valor;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }

    // Si es menor, va a la izquierda
    if(valor < raiz->dato)
        raiz->izq = insertar(raiz->izq, valor);
    // Si es mayor, va a la derecha
    else if(valor > raiz->dato)
        raiz->der = insertar(raiz->der, valor);

    return raiz;
}
```

### Recorridos (los 3 son recursivos)

**PREORDEN:** raíz → izquierda → derecha

```c
void preorden(struct NodoA *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->dato);      // 1. raiz
        preorden(raiz->izq);            // 2. izquierda
        preorden(raiz->der);            // 3. derecha
    }
}
```

**INORDEN:** izquierda → raíz → derecha (devuelve ordenado en un BST)

```c
void inorden(struct NodoA *raiz)
{
    if(raiz != NULL)
    {
        inorden(raiz->izq);             // 1. izquierda
        printf("%d ", raiz->dato);      // 2. raiz
        inorden(raiz->der);             // 3. derecha
    }
}
```

**POSTORDEN:** izquierda → derecha → raíz

```c
void postorden(struct NodoA *raiz)
{
    if(raiz != NULL)
    {
        postorden(raiz->izq);           // 1. izquierda
        postorden(raiz->der);           // 2. derecha
        printf("%d ", raiz->dato);      // 3. raiz
    }
}
```

**Truco para recordar:** la palabra (PRE/IN/POST) indica dónde se ubica la RAÍZ en el recorrido.

### Buscar en BST

```c
int buscar(struct NodoA *raiz, int valor)
{
    if(raiz == NULL)
        return 0;  // no encontrado

    if(raiz->dato == valor)
        return 1;  // encontrado

    if(valor < raiz->dato)
        return buscar(raiz->izq, valor);
    else
        return buscar(raiz->der, valor);
}
```

### Contar nodos

```c
int contarNodos(struct NodoA *raiz)
{
    if(raiz == NULL)
        return 0;
    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
}
```

### Altura del árbol

```c
int altura(struct NodoA *raiz)
{
    if(raiz == NULL)
        return 0;

    int altIzq = altura(raiz->izq);
    int altDer = altura(raiz->der);

    if(altIzq > altDer)
        return 1 + altIzq;
    else
        return 1 + altDer;
}
```

### Main de ejemplo

```c
int main()
{
    struct NodoA *raiz = NULL;

    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    printf("Preorden: ");  preorden(raiz);   // 50 30 20 40 70 60 80
    printf("\nInorden: ");  inorden(raiz);   // 20 30 40 50 60 70 80 (ordenado!)
    printf("\nPostorden: "); postorden(raiz); // 20 40 30 60 80 70 50

    printf("\nNodos: %d", contarNodos(raiz));
    printf("\nAltura: %d", altura(raiz));

    getch();
    return 0;
}
```

---

## 12. Plantilla base

Para arrancar cualquier programa:

```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>   // para malloc, free (listas y arboles)
#include <string.h>   // para strcpy, strlen, strcmp (cadenas)

#define TAM 5

// === STRUCTS aca arriba ===
// struct Nodo { ... };

// === FUNCIONES aca ===
// tipo nombre(parametros) { ... }

int main()
{
    // declaracion de variables

    // carga de datos

    // procesamiento

    // mostrar resultados

    getch();
    return 0;
}
```

---

## 🎯 Checklist final antes de entregar

- [ ] `#include` arriba de todo
- [ ] Cada línea termina con `;`
- [ ] `for` con `;` entre las partes (no comas)
- [ ] `if`/`for`/`while` SIN `;` después de la condición
- [ ] `scanf` con `&` (excepto cadenas con `gets`)
- [ ] `printf` SIN `&`
- [ ] `fflush(stdin);` antes de `gets` si vino después de un `scanf` numérico
- [ ] Structs cerrados con `};`
- [ ] Variables declaradas con su tipo
- [ ] Mayúsculas/minúsculas consistentes (`TAM` ≠ `tam`)
- [ ] Caso base en funciones recursivas
- [ ] Inicializar contadores y acumuladores en 0
- [ ] Inicializar `posicion` en -1 en búsquedas
- [ ] Punteros a struct usan `->`, no `.`
- [ ] `getch();` y `return 0;` al final del main
