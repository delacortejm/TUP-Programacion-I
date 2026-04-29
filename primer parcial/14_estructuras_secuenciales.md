# 14 · Estructuras Secuenciales

## ¿Qué es una estructura secuencial de datos?
Organización en la que los elementos se disponen **uno detrás de otro** siguiendo un orden.

```
8, 6, 10, 7, 9   → secuencia de notas
```

No son cinco variables separadas: son una **colección ordenada**.

---

## ¿Por qué no alcanzan variables sueltas?

```c
// ❌ Incómodo y rígido
int nota1 = 8;
int nota2 = 6;
int nota3 = 10;
int nota4 = 7;
int nota5 = 9;
```

Problemas:
- Difícil de recorrer ordenadamente.
- No se puede aplicar la misma operación a todos fácilmente.
- No escala si la cantidad de datos aumenta.

---

## Operaciones sobre una secuencia

| Operación | Qué hace |
|-----------|---------|
| **Recorrido** | Visitar los elementos uno por uno |
| **Búsqueda** | Encontrar un valor dentro de la secuencia |
| **Inserción** | Agregar un nuevo elemento |
| **Actualización** | Cambiar un elemento existente |

---

## Estructuras secuenciales que vas a estudiar

| Estructura | Tipo |
|-----------|------|
| Arreglos | Estática |
| Cadenas de caracteres | Estática |
| Listas | Dinámica |
| Pilas | Dinámica |
| Colas | Dinámica |

Todas organizan datos de forma secuencial, pero no todas funcionan igual.

---

## Resumen rápido
- Estructura secuencial = datos organizados en orden.
- Permite tratar una colección como un conjunto, no como variables aisladas.
- Facilita recorrido, búsqueda e inserción.
- Es la base para entender arreglos, cadenas y estructuras dinámicas.
