#include <stdio.h>
#include <stdlib.h>   // para malloc() y NULL

/*
 * Cada nodo guarda:
 *   - dato: el valor entero almacenado.
 *   - izq:  puntero al hijo izquierdo (valores MENORES).
 *   - der:  puntero al hijo derecho  (valores MAYORES o iguales).
 */
struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
};

/*
 * crearNodo: reserva memoria para un nodo nuevo y lo inicializa.
 */
struct Nodo* crearNodo(int valor) {
    // Memoria del tamano de un Nodo.
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));

    nuevo->dato = valor;   // se guarda el valor
    nuevo->izq = NULL;     // todavia no tiene hijo izquierdo
    nuevo->der = NULL;     // todavia no tiene hijo derecho

    return nuevo;          // se devuelve el puntero al nodo creado
}


// insertar: agrega un valor al Arbol Binario de Busqueda (ABB) de forma recursiva.

struct Nodo* insertar(struct Nodo* raiz, int valor) {

    // CASO BASE: si se llega a un lugar vacio, se crea el nodo ahí
    if (raiz == NULL)
        return crearNodo(valor);

    // CASO RECURSIVO:
    // Si el valor es menor que el nodo actual, baja por la rama izquierda.
    if (valor < raiz->dato)
        raiz->izq = insertar(raiz->izq, valor);
    else
        // Si es mayor o igual, baja por la rama derecha.
        raiz->der = insertar(raiz->der, valor);

    return raiz;   // devolvemos la raiz (sin cambios en su direccion)
}

/*
 * inorden: recorre el arbol en orden Izquierda -> Raiz -> Derecha.
 * En un ABB, esto imprime los valores ORDENADOS de menor a mayor.
 */
void inorden(struct Nodo* raiz) {

    if (raiz != NULL) {
        inorden(raiz->izq);          // 1) primero todo el subarbol izquierdo

        printf("%d ", raiz->dato);   // 2) luego el dato del nodo actual

        inorden(raiz->der);          // 3) por ultimo el subarbol derecho
    }
}

/*
 * preorden: recorre el arbol en orden Raiz -> Izquierda -> Derecha.
 * Primero procesa el nodo y despues sus subarboles.
 */
void preorden(struct Nodo* raiz) {

    if (raiz != NULL) {
        printf("%d ", raiz->dato);   // 1) primero el dato del nodo actual

        preorden(raiz->izq);         // 2) luego el subarbol izquierdo

        preorden(raiz->der);         // 3) por ultimo el subarbol derecho
    }
}

/*
 * postorden: recorre el arbol en orden Izquierda -> Derecha -> Raiz.
 * Procesa primero los hijos y al final el nodo.
 */
void postorden(struct Nodo* raiz) {

    if (raiz != NULL) {
        postorden(raiz->izq);        // 1) primero el subarbol izquierdo

        postorden(raiz->der);        // 2) luego el subarbol derecho

        printf("%d ", raiz->dato);   // 3) por ultimo el dato del nodo actual
    }
}

/*
 * mostrarArbol: dibuja el arbol de costado
 * La raiz queda a la izquierda; los nodos mas a la derecha estan mas abajo.
 * El parametro 'nivel' indica la profundidad para saber cuanto indentar.
 */
void mostrarArbol(struct Nodo* raiz, int nivel) {

    if (raiz == NULL)
        return;   // nada que dibujar

    // Primero la rama derecha 
    mostrarArbol(raiz->der, nivel + 1);

    // Indentar segun el nivel para representar la profundidad.d
    for(int i = 0; i < nivel; i++)
        printf("     ");

    // Imprimimos el valor del nodo actual.
    printf("%d\n", raiz->dato);

    // Por ultimo dibujamos la rama izquierda (queda abajo en pantalla).
    mostrarArbol(raiz->izq, nivel + 1);
}

int main() {

    struct Nodo* raiz = NULL;   // el arbol arranca vacio

    int valor;
    int cantidad;

    // Pedimos cuantos nodos va a tener el arbol.
    printf("Cantidad de nodos: ");
    scanf("%d", &cantidad);

    // Leemos 'cantidad' valores y los vamos insertando.
    for(int i = 0; i < cantidad; i++) {

        printf("Ingrese un valor: ");
        scanf("%d", &valor);

        raiz = insertar(raiz, valor);   // insertamos y actualizamos la raiz
    }

    // Mostramos el arbol dibujado de costado.
    printf("\n\nARBOL BINARIO\n\n");
    mostrarArbol(raiz, 0);

    int opcion;   // guarda la opcion elegida en el menu

    // Mostramos el menu de recorridos.
    printf("\n\n=== MENU DE RECORRIDOS ===\n");
    printf("1) InOrden   (Izq - Raiz - Der)\n");
    printf("2) PreOrden  (Raiz - Izq - Der)\n");
    printf("3) PostOrden (Izq - Der - Raiz)\n");
    printf("4) Mostrar los 3 recorridos\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    printf("\n");

    // Un solo switch decide que recorrido(s) mostrar segun la opcion.
    switch (opcion) {

        case 1:   // solo InOrden
            printf("Recorrido InOrden: ");
            inorden(raiz);
            printf("\n");
            break;

        case 2:   // solo PreOrden
            printf("Recorrido PreOrden: ");
            preorden(raiz);
            printf("\n");
            break;

        case 3:   // solo PostOrden
            printf("Recorrido PostOrden: ");
            postorden(raiz);
            printf("\n");
            break;

        case 4:   // los 3 recorridos juntos
            printf("Recorrido InOrden:   ");
            inorden(raiz);
            printf("\n");

            printf("Recorrido PreOrden:  ");
            preorden(raiz);
            printf("\n");

            printf("Recorrido PostOrden: ");
            postorden(raiz);
            printf("\n");
            break;

        default:  // cualquier numero distinto de 1-4
            printf("Opcion invalida.\n");
            break;
    }

    return 0;
}
