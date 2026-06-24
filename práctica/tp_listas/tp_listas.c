#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo
struct Nodo {
    char dato;
    struct Nodo* siguiente;
};

// Prototipos
struct Nodo* crearNodo(char valor);
void insertarAlFinal(struct Nodo** cabeza, char valor);
char recuperarElemento(struct Nodo* cabeza, int posicion);
int cantidadElementos(struct Nodo* cabeza);
void imprimirLista(struct Nodo* cabeza);
void liberarLista(struct Nodo* cabeza);

int main() {
    struct Nodo* lista = NULL;
    int opcion, posicion;
    char letra;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insertar letra al final\n");
        printf("2. Recuperar elemento por posicion\n");
        printf("3. Cantidad de elementos\n");
        printf("4. Mostrar lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese una letra: ");
            scanf(" %c", &letra);
            insertarAlFinal(&lista, letra);
            break;
        case 2:
            printf("Ingrese la posicion (desde 0): ");
            scanf("%d", &posicion);
            letra = recuperarElemento(lista, posicion);
            if (letra != '\0')
                printf("Elemento en posicion %d: %c\n", posicion, letra);
            break;
        case 3:
            printf("Cantidad de elementos: %d\n", cantidadElementos(lista));
            break;
        case 4:
            imprimirLista(lista);
            break;
        case 5:
            liberarLista(lista);
            printf("Memoria liberada. Adios.\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}

// Crea un nuevo nodo con una letra
struct Nodo* crearNodo(char valor) {
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Inserta una letra al final de la lista
void insertarAlFinal(struct Nodo** cabeza, char valor) {
    struct Nodo* nuevo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Recupera el elemento en la posicion indicada (desde 0)
char recuperarElemento(struct Nodo* cabeza, int posicion) {
    int i = 0;
    while (cabeza != NULL) {
        if (i == posicion)
            return cabeza->dato;
        cabeza = cabeza->siguiente;
        i++;
    }
    printf("Posicion invalida.\n");
    return '\0';
}

// Devuelve la cantidad de elementos en la lista
int cantidadElementos(struct Nodo* cabeza) {
    int cantidad = 0;
    while (cabeza != NULL) {
        cantidad++;
        cabeza = cabeza->siguiente;
    }
    return cantidad;
}

// Imprime todos los elementos de la lista
void imprimirLista(struct Nodo* cabeza) {
    printf("Lista: ");
    while (cabeza != NULL) {
        printf("%c -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

// Libera la memoria de la lista
void liberarLista(struct Nodo* cabeza) {
    struct Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}