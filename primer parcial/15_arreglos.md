# 15 · Arreglos

## ¿Qué es un arreglo?
Estructura que permite guardar **varios datos del mismo tipo** bajo un mismo nombre.  
Cada dato se accede mediante un **índice**.

```c
int notas[5];   // arreglo de 5 enteros
//      ^ nombre  ^ cantidad de posiciones
```

---

## Índices — FUNDAMENTAL

> En C, los arreglos **empiezan en el índice 0**.

```
Índice:   0    1    2    3    4
Valor:   [ ]  [ ]  [ ]  [ ]  [ ]
```

Si hay **5 elementos**: último índice = **4**, no 5.

---

## Declaración e inicialización

```c
// Solo declarar
int numeros[5];

// Declarar + inicializar
int numeros[5] = {10, 20, 30, 40, 50};
// numeros[0]=10  numeros[1]=20  ...  numeros[4]=50
```

---

## Acceder y modificar elementos

```c
int primero = numeros[0];    // leer
numeros[2] = 99;             // modificar
printf("%d\n", numeros[3]);  // mostrar
```

---

## Ejemplo completo — asignación manual

```c
#include <stdio.h>

int main() {
    int numeros[5];

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;
    numeros[3] = 40;
    numeros[4] = 50;

    printf("Primer valor: %d\n", numeros[0]);
    printf("Ultimo valor: %d\n", numeros[4]);

    return 0;
}
```

---

## Cargar y mostrar con ciclo (lo más útil)

```c
#include <stdio.h>

int main() {
    int numeros[5];
    int i;

    for (i = 0; i < 5; i = i + 1) {
        printf("Ingresa un numero: ");
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 5; i = i + 1) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }

    return 0;
}
```

---

## Arreglos multidimensionales (matrices)

Una **matriz** organiza datos en filas y columnas.

```c
int matriz[2][3];   // 2 filas, 3 columnas → 6 elementos
```

```
          Col 0  Col 1  Col 2
Fila 0   [ ]    [ ]    [ ]
Fila 1   [ ]    [ ]    [ ]
```

### Inicialización

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
// matriz[0][0]=1  matriz[0][2]=3  matriz[1][1]=5  etc.
```

### Acceso

```c
int valor = matriz[1][2];   // fila 1, columna 2 → 6
```

---

## Diferencia unidimensional vs bidimensional

| | Unidimensional | Bidimensional |
|-|---------------|---------------|
| Declaración | `int arr[5];` | `int mat[2][3];` |
| Acceso | `arr[2]` | `mat[1][2]` |
| Imagen mental | Fila de casilleros | Tabla con filas y columnas |

---

## Errores comunes

| Error | Correcto |
|-------|---------|
| Usar índice = cantidad (`numeros[5]` en arreglo de 5) | Último índice = cantidad - 1 |
| Confundir cantidad con último índice | `[5]` = 5 elementos, último = `[4]` |
| Pensar que la matriz se maneja con un índice | Necesita **dos** índices |

---

## Resumen rápido
- Arreglo = varios datos del mismo tipo, mismo nombre, acceso por índice.
- Índices empiezan en **0**.
- Unidimensional → fila. Bidimensional → tabla.
- Los ciclos son la forma natural de trabajar con arreglos.
