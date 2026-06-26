# Cheatsheet de Programación I — Examen

> Referencia rápida para usar durante el examen.
> Estilo: C estándar con `conio.h`, `getch()`, `gets()`. Variables y comentarios en español.
> **Alineado al estilo de los apuntes de cátedra.**

---

## 📑 Índice

1. [Errores típicos de sintaxis (LEER PRIMERO)](#1-errores-típicos-de-sintaxis)
2. [Búsqueda lineal](#2-búsqueda-lineal)
3. [Búsqueda binaria](#3-búsqueda-binaria)
4. [Ordenamiento - Bubble Sort](#4-ordenamiento---bubble-sort)
5. [Ordenamiento - Selección](#5-ordenamiento---selección)
6. [Ordenamiento - Inserción](#6-ordenamiento---inserción)
7. [Funciones y modularización](#7-funciones-y-modularización)
8. [Variables y parámetros](#8-variables-y-parámetros)
9. [Recursividad](#9-recursividad)
10. [Punteros y malloc](#10-punteros-y-malloc)
11. [Listas enlazadas simples](#11-listas-enlazadas-simples)
12. [Listas doblemente enlazadas](#12-listas-doblemente-enlazadas)
13. [Pilas (LIFO)](#13-pilas-lifo)
14. [Colas (FIFO)](#14-colas-fifo)
15. [Árboles binarios (BST/ABB)](#15-árboles-binarios)
16. [Plantilla base de programa](#16-plantilla-base)

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

```c
int posicion = -1;
for(i = 0; i < TAM; i++)
{
    if(arr[i] == buscado)
        posicion = i;
}

if(posicion == -1)
    printf("No encontrado");
else
    printf("Encontrado en posicion %d", posicion);
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

```c
int izq = 0;
int der = TAM - 1;
int medio;
int posicion = -1;

while(izq <= der && posicion == -1)
{
    medio = (izq + der) / 2;

    if(arr[medio] == buscado)
        posicion = medio;
    else if(buscado < arr[medio])
        der = medio - 1;
    else
        izq = medio + 1;
}
```

---

## 4. Ordenamiento - Bubble Sort

**Idea:** Comparar pares de elementos vecinos. Si están desordenados, intercambiar.

```c
int i, j, aux;

for(i = 0; i < TAM - 1; i++)
{
    for(j = 0; j < TAM - 1 - i; j++)
    {
        if(arr[j] > arr[j + 1])
        {
            aux = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = aux;
        }
    }
}
```

**Patrón de intercambio:**
```c
aux = a;
a = b;
b = aux;
```

---

## 5. Ordenamiento - Selección

```c
int i, j, posMin, aux;

for(i = 0; i < TAM - 1; i++)
{
    posMin = i;
    for(j = i + 1; j < TAM; j++)
    {
        if(arr[j] < arr[posMin])
            posMin = j;
    }
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

```c
int i, j, actual;

for(i = 1; i < TAM; i++)
{
    actual = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > actual)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = actual;
}
```

---

## 7. Funciones y modularización

**Modularizar** = dividir el programa en partes pequeñas con responsabilidad clara.

### Diferencia conceptual (importante para teoría)

- **Función:** subprograma que **devuelve un resultado**.
- **Procedimiento:** subprograma que **realiza una acción** (no devuelve valor útil).
- **En C:** todo se expresa con funciones. Los "procedimientos" se escriben con retorno `void`.

### Estructura general

```c
tipo_retorno nombre(parametros)
{
    instrucciones;
    return valor;   // si tiene retorno
}
```

### Función que devuelve valor

```c
int sumar(int a, int b)
{
    return a + b;
}
```

### "Procedimiento" (void, sin retorno)

```c
void mostrarSaludo()
{
    printf("Hola\n");
}
```

### Ejemplo completo

```c
#include <stdio.h>

int sumar(int a, int b)
{
    return a + b;
}

void mostrarResultado(int resultado)
{
    printf("El resultado es %d\n", resultado);
}

int main()
{
    int total = sumar(5, 3);
    mostrarResultado(total);
    return 0;
}
```

### Función que recibe un arreglo

```c
// Al pasar un arreglo: corchetes [] sin tamaño, y se pasa el tamaño aparte
float calcularPromedio(int arr[], int tam)
{
    int i, suma = 0;
    for(i = 0; i < tam; i++)
        suma = suma + arr[i];
    return (float)suma / tam;
}

// Uso en main:
// float prom = calcularPromedio(numeros, TAM);
```

---

## 8. Variables y parámetros

### Variables locales vs globales

- **Local:** declarada dentro de una función. Solo existe ahí.
- **Global:** declarada fuera de todas las funciones. Visible para todo el programa.

```c
int contador = 0;   // GLOBAL

void aumentar()
{
    contador = contador + 1;   // accede a la global
}

void saludar()
{
    int veces = 1;   // LOCAL: solo existe acá
    printf("Hola %d\n", veces);
}
```

**Recomendación:** preferí variables locales salvo razón clara para compartir.

### Parámetros nominales vs efectivos

- **Nominales:** los que aparecen en la **definición** de la función.
- **Efectivos:** los valores reales que se pasan en la **invocación**.

```c
int sumar(int a, int b) { ... }   // a y b son NOMINALES
sumar(5, 3);                       // 5 y 3 son EFECTIVOS
```

### Pasaje por VALOR (default en C)

La función recibe una **copia**. Si la modifica, el original NO cambia.

```c
void cambiar(int x)
{
    x = 100;   // modifica la copia, no el original
}

int main()
{
    int numero = 5;
    cambiar(numero);
    printf("%d", numero);   // imprime 5 (NO cambió)
    return 0;
}
```

### Pasaje por REFERENCIA (con punteros)

La función recibe la **dirección** del original. Sí puede modificarlo.

```c
void cambiar(int *x)
{
    *x = 100;   // modifica el original a traves del puntero
}

int main()
{
    int numero = 5;
    cambiar(&numero);          // paso la direccion
    printf("%d", numero);      // imprime 100 (SÍ cambió)
    return 0;
}
```

**Resumen rápido:**

| Pasaje | Recibe | ¿Modifica original? |
|---|---|---|
| Por valor | copia | No |
| Por referencia (puntero) | dirección | Sí |

---

## 9. Recursividad

### Reglas obligatorias

Toda función recursiva tiene:
1. **Caso base** → condición de salida (sin esto se cuelga).
2. **Caso recursivo (paso recursivo)** → se llama a sí misma con un parámetro **más chico**.

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

### Fibonacci

```c
int fibonacci(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Contar dígitos

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

### 📚 Teoría (por si te preguntan)

**Call Stack (Pila de llamadas):**
- Cada vez que se llama una función, se apila un "marco de pila" en memoria con sus variables locales y parámetros.
- Cuando la función termina, ese marco se desapila.
- En recursión, se van apilando muchos marcos hasta llegar al caso base, y después se desapilan resolviendo de adentro hacia afuera.

**Stack Overflow (desbordamiento de pila):**
- Si te olvidás del caso base, la función se llama infinitamente.
- Se llena la memoria de la pila → el programa CRASHEA con error fatal.
- Solución: SIEMPRE tener un caso base bien definido.

**Recursividad vs Iteración:**

| Criterio | Recursividad | Iteración (for/while) |
|---|---|---|
| Memoria | Más (consume el Call Stack) | Menos (constante) |
| Velocidad | Más lenta | Más rápida |
| Código | Más elegante en estructuras jerárquicas | Más directo en problemas lineales |
| Cuándo usar | Árboles, divide y vencerás | Recorrer arreglos, acumular, contar |

---

## 10. Punteros y malloc

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
```

### Regla `.` vs `->`

- Struct directo → punto: `alumno.nombre`
- Puntero a struct → flecha: `puntero->nombre`

---

## 11. Listas enlazadas simples

### Definición del nodo

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};
```

### Función auxiliar para crear un nodo

```c
struct Nodo* crearNodo(int valor)
{
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}
```

### Insertar al INICIO

```c
struct Nodo* insertarInicio(struct Nodo *lista, int valor)
{
    struct Nodo *nuevo = crearNodo(valor);
    nuevo->siguiente = lista;
    return nuevo;
}
// Uso: lista = insertarInicio(lista, 5);
```

### Insertar al FINAL

```c
struct Nodo* insertarFinal(struct Nodo *lista, int valor)
{
    struct Nodo *nuevo = crearNodo(valor);

    if(lista == NULL)
        return nuevo;

    struct Nodo *aux = lista;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    return lista;
}
```

### Recorrer / Mostrar

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
            return 1;
        aux = aux->siguiente;
    }
    return 0;
}
```

### Eliminar un valor

```c
struct Nodo* eliminar(struct Nodo *lista, int valor)
{
    if(lista == NULL)
        return NULL;

    // Caso especial: eliminar el primero
    if(lista->dato == valor)
    {
        struct Nodo *aux = lista->siguiente;
        free(lista);
        return aux;
    }

    struct Nodo *aux = lista;
    struct Nodo *anterior = NULL;

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

---

## 12. Listas doblemente enlazadas

**Diferencia:** Cada nodo tiene punteros a **siguiente** Y **anterior**.

### Definición del nodo

```c
struct NodoD
{
    int dato;
    struct NodoD *siguiente;
    struct NodoD *anterior;
};
```

### Función auxiliar

```c
struct NodoD* crearNodoD(int valor)
{
    struct NodoD *nuevo = (struct NodoD*) malloc(sizeof(struct NodoD));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}
```

### Insertar al INICIO

```c
struct NodoD* insertarInicio(struct NodoD *lista, int valor)
{
    struct NodoD *nuevo = crearNodoD(valor);
    nuevo->siguiente = lista;

    if(lista != NULL)
        lista->anterior = nuevo;

    return nuevo;
}
```

### Insertar al FINAL

```c
struct NodoD* insertarFinal(struct NodoD *lista, int valor)
{
    struct NodoD *nuevo = crearNodoD(valor);

    if(lista == NULL)
        return nuevo;

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

### Mostrar hacia atrás

```c
void mostrarAtras(struct NodoD *lista)
{
    if(lista == NULL) return;

    struct NodoD *aux = lista;
    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    while(aux != NULL)
    {
        printf("%d <-> ", aux->dato);
        aux = aux->anterior;
    }
    printf("NULL\n");
}
```

### Eliminar un valor

```c
struct NodoD* eliminar(struct NodoD *lista, int valor)
{
    if(lista == NULL) return NULL;

    struct NodoD *aux = lista;
    while(aux != NULL && aux->dato != valor)
        aux = aux->siguiente;

    if(aux == NULL) return lista;

    // Caso: es el primero
    if(aux == lista)
    {
        lista = aux->siguiente;
        if(lista != NULL)
            lista->anterior = NULL;
        free(aux);
        return lista;
    }

    aux->anterior->siguiente = aux->siguiente;
    if(aux->siguiente != NULL)
        aux->siguiente->anterior = aux->anterior;

    free(aux);
    return lista;
}
```

---

## 13. Pilas (LIFO)

**LIFO = Last In, First Out.** El último que entra es el primero que sale.
Pensalo como una pila de platos: agregás y sacás siempre desde **arriba** (el tope).

### Nodo de la pila

```c
struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};
```

### Variable principal

```c
struct Nodo *tope = NULL;   // si es NULL, la pila esta vacia
```

### PUSH (insertar)

```c
void push(struct Nodo **tope, int valor)
{
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *tope;   // el nuevo apunta al tope actual
    *tope = nuevo;              // el nuevo es el nuevo tope
}

// Uso: push(&tope, 10);
```

### POP (extraer)

```c
int pop(struct Nodo **tope)
{
    if(*tope == NULL)
        return -1;   // pila vacia

    struct Nodo *temp = *tope;
    int valor = temp->dato;
    *tope = (*tope)->siguiente;   // el tope avanza hacia abajo
    free(temp);
    return valor;
}
```

### Recorrer

```c
void recorrerPila(struct Nodo *tope)
{
    struct Nodo *actual = tope;
    while(actual != NULL)
    {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}
```

### Buscar

```c
int buscarEnPila(struct Nodo *tope, int buscado)
{
    struct Nodo *actual = tope;
    while(actual != NULL)
    {
        if(actual->dato == buscado)
            return 1;
        actual = actual->siguiente;
    }
    return 0;
}
```

### Main de ejemplo

```c
int main()
{
    struct Nodo *tope = NULL;

    push(&tope, 10);
    push(&tope, 20);
    push(&tope, 30);

    printf("Pila:\n");
    recorrerPila(tope);   // 30, 20, 10 (el ultimo entra primero)

    int extraido = pop(&tope);
    printf("Extraido: %d\n", extraido);   // 30

    return 0;
}
```

**Ojo con `**tope`:** se usa doble puntero porque la función necesita modificar el puntero original (no solo el dato). Por eso al llamarla se pasa `&tope`.

---

## 14. Colas (FIFO)

**FIFO = First In, First Out.** El primero que entra es el primero que sale.
Pensalo como una fila del supermercado: entrás por el **final**, salís por el **frente**.

### Nodo de la cola

```c
struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};
```

### Variables principales

```c
struct Nodo *frente = NULL;   // primer nodo
struct Nodo *final = NULL;    // ultimo nodo
// Si ambos son NULL, la cola esta vacia
```

### ENCOLAR (insertar al final)

```c
void encolar(struct Nodo **frente, struct Nodo **final, int valor)
{
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(*final == NULL)   // cola vacia
    {
        *frente = nuevo;
        *final = nuevo;
    }
    else
    {
        (*final)->siguiente = nuevo;   // el ultimo apunta al nuevo
        *final = nuevo;                // el nuevo es el nuevo final
    }
}
```

### DESENCOLAR (extraer del frente)

```c
int desencolar(struct Nodo **frente, struct Nodo **final)
{
    if(*frente == NULL)
        return -1;   // cola vacia

    struct Nodo *temp = *frente;
    int valor = temp->dato;
    *frente = (*frente)->siguiente;   // el frente avanza

    if(*frente == NULL)
        *final = NULL;   // si quedo vacia, actualizo el final tambien

    free(temp);
    return valor;
}
```

### Recorrer

```c
void recorrerCola(struct Nodo *frente)
{
    struct Nodo *actual = frente;
    while(actual != NULL)
    {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}
```

### Buscar

```c
int buscarEnCola(struct Nodo *frente, int buscado)
{
    struct Nodo *actual = frente;
    while(actual != NULL)
    {
        if(actual->dato == buscado)
            return 1;
        actual = actual->siguiente;
    }
    return 0;
}
```

### Main de ejemplo

```c
int main()
{
    struct Nodo *frente = NULL;
    struct Nodo *final = NULL;

    encolar(&frente, &final, 10);
    encolar(&frente, &final, 20);
    encolar(&frente, &final, 30);

    printf("Cola:\n");
    recorrerCola(frente);   // 10, 20, 30 (en orden de llegada)

    int extraido = desencolar(&frente, &final);
    printf("Extraido: %d\n", extraido);   // 10 (el primero que entro)

    return 0;
}
```

### 📋 Pila vs Cola

| | Pila (LIFO) | Cola (FIFO) |
|---|---|---|
| Insertar | `push` (al tope) | `encolar` (al final) |
| Extraer | `pop` (del tope) | `desencolar` (del frente) |
| Punteros | 1 (tope) | 2 (frente y final) |
| Analogía | Pila de platos | Fila del supermercado |

---

## 15. Árboles binarios

> **Estilo de cátedra:** campos `izquierdo` y `derecho`, función auxiliar `crearNodo`, búsqueda devuelve puntero al nodo.

### Anatomía del árbol

```
       [ Raíz: 50 ]
       /          \
  [ 30 ]          [ 70 ]
  /    \          /    \
[20]  [40]      [60]  [80]   <-- hojas (sin hijos)
```

- **Raíz**: nodo superior, sin padre.
- **Hijo**: nodo que cuelga de otro (en binario, máximo 2: izquierdo y derecho).
- **Padre**: nodo del que cuelga otro.
- **Hoja**: nodo sin hijos.
- **Subárbol**: cada hijo es a su vez una raíz de su propio árbol → recursividad.

### Regla del BST

Para cualquier nodo:
- Subárbol **izquierdo** = valores **menores**
- Subárbol **derecho** = valores **mayores**

### Definición del nodo

```c
struct Nodo
{
    int dato;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};
```

### Crear nodo (auxiliar)

```c
struct Nodo* crearNodo(int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}
```

### Insertar (recursivo)

```c
struct Nodo* insertar(struct Nodo *raiz, int valor)
{
    if(raiz == NULL)
        return crearNodo(valor);

    if(valor < raiz->dato)
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else if(valor > raiz->dato)
        raiz->derecho = insertar(raiz->derecho, valor);

    return raiz;
}
```

### Buscar (devuelve puntero al nodo o NULL)

```c
struct Nodo* buscar(struct Nodo *raiz, int valorBuscado)
{
    if(raiz == NULL || raiz->dato == valorBuscado)
        return raiz;

    if(valorBuscado < raiz->dato)
        return buscar(raiz->izquierdo, valorBuscado);

    return buscar(raiz->derecho, valorBuscado);
}
```

### Recorridos

**Truco:** la palabra (**PRE**/**IN**/**POST**) indica dónde está la **RAÍZ** en el recorrido.

**PREORDEN:** raíz → izq → der

```c
void preorden(struct Nodo *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->dato);
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}
```

**INORDEN:** izq → raíz → der
> 🎯 **En un BST, inorden devuelve los valores ORDENADOS de menor a mayor.**

```c
void inorden(struct Nodo *raiz)
{
    if(raiz != NULL)
    {
        inorden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inorden(raiz->derecho);
    }
}
```

**POSTORDEN:** izq → der → raíz

```c
void postorden(struct Nodo *raiz)
{
    if(raiz != NULL)
    {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        printf("%d ", raiz->dato);
    }
}
```

### Contar nodos

```c
int contarNodos(struct Nodo *raiz)
{
    if(raiz == NULL)
        return 0;
    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}
```

### Altura del árbol

```c
int altura(struct Nodo *raiz)
{
    if(raiz == NULL)
        return 0;

    int altIzq = altura(raiz->izquierdo);
    int altDer = altura(raiz->derecho);

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
    struct Nodo *raiz = NULL;

    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    printf("Preorden: ");  preorden(raiz);   printf("\n");
    printf("Inorden: ");   inorden(raiz);    printf("\n");
    printf("Postorden: "); postorden(raiz);  printf("\n");

    struct Nodo *encontrado = buscar(raiz, 40);
    if(encontrado != NULL)
        printf("Encontrado\n");
    else
        printf("No encontrado\n");

    getch();
    return 0;
}
```

---

## 16. Plantilla base

```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>   // para malloc, free (listas, pilas, colas, arboles)
#include <string.h>   // para strcpy, strlen, strcmp (cadenas)

#define TAM 5

// === STRUCTS aca arriba ===

// === FUNCIONES aca ===

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
- [ ] Pilas/colas: pasar punteros dobles (`**`) y al llamar usar `&`
- [ ] `getch();` y `return 0;` al final del main
