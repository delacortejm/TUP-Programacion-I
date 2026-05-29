📚 Programación I — TUP 2026
Repositorios y guía de estudio para el 2° Parcial · Comisión 3 (Noche)
Alumno: A. Nicolás Petean

📁 Repositorios
🔵 Mi repositorio — ANPetean/Suma
🔗 https://github.com/ANPetean/Suma

Repositorio personal con todos los programas desarrollados durante la cursada. Contiene ejercicios prácticos en lenguaje C que cubren los temas del segundo parcial.

Archivos principales:

Archivo	Descripción
suma.c	Algoritmo básico de suma, primer programa del curso
holamundo.c	Programa introductorio
edad.c	Manejo de variables y condicionales
arreglo busqueda.c	Búsqueda secuencial en arreglos
arreglo busqueda2.c	Variante de búsqueda en arreglos
burbuja.c	Algoritmo de ordenamiento Burbuja (Bubble Sort)
seleccion.c	Algoritmo de ordenamiento por Selección
insercion.c	Algoritmo de ordenamiento por Inserción
bus_binaria.c / busqueda binaria1.c	Búsqueda binaria (requiere arreglo ordenado)
Matrices.c	Operaciones con matrices bidimensionales
estruc 1.c … estruc 4.c	Ejercicios con estructuras (struct)
estruc ordenamiento.c	Ordenamiento de arreglos de estructuras
estru ord saldo.c	Ordenamiento de estructuras por campo saldo
estru ord cuenta2.c	Ordenamiento de estructuras por número de cuenta
estru ord 3.c	Variante de ordenamiento de estructuras
estructura de datos.c	Ejercicio integrador de estructuras
Trabajos Prácticos incluidos:

PEtean A. Nicolas Trabajo Practico N1.docx
PEtean A. Nicolas Trabajo Practico N3.docx
🟢 Repositorio del Profesor — facundouferer/cursodec
🔗 https://github.com/facundouferer/cursodec

Repositorio oficial de la cátedra con los programas base usados en los parciales. Los ejercicios del examen piden completar funciones dentro de estos archivos sin modificar el código existente.

📄 segundoParcialCliente.c
🔗 Ver archivo

Programa de gestión de clientes bancarios. Define la estructura:

struct Cliente {
    int dni;
    char nombre[30];
    char apellido[30];
    float saldo;
    int habilitado; // 1 = habilitado, 0 = inhabilitado
};
Funciones ya implementadas en el archivo:

ordenarClientes() — ordena por DNI con Bubble Sort
mostrarEstadisticas() — muestra cantidad de habilitados e inhabilitados
calcularSaldoPromedio() — calcula el promedio de saldos
eliminarCliente() — elimina un cliente por DNI
agregarCliente() — agrega un nuevo cliente al arreglo
mostrarMenu() — muestra el menú de opciones
Funciones a desarrollar en el examen:

Función	Qué debe hacer
buscarCliente()	Búsqueda binaria por DNI (el arreglo debe estar ordenado primero)
listarClientesPorSaldo()	Listar todos los clientes ordenados por saldo
listarClientesPorDNI()	Listar todos los clientes ordenados por DNI
listarClientesHabilitados()	Mostrar solo los clientes con habilitado == 1
deshabilitarCliente()	Poner habilitado = 0 al cliente con ese DNI
habilitarCliente()	Poner habilitado = 1 al cliente con ese DNI
modificarCliente()	Modificar los datos de un cliente por DNI
📄 segundoParcialAjedrez.c
🔗 Ver archivo

Programa de gestión de piezas de ajedrez. Define la estructura:

struct Pieza {
    int posicion[2];  // posicion[0] = fila, posicion[1] = columna
    char tipo[20];    // peon, torre, caballo, alfil, reina, rey
    char color;       // 'b' blanco, 'n' negro
    int valor;
    int activa;       // 1 = en juego, 0 = capturada
};
Funciones ya implementadas en el archivo:

ordenarPiezas() — ordena por posición (fila y columna) con Bubble Sort
restaurarPieza() — pone activa = 1 a la pieza en esa posición
mostrarEstadisticas() — muestra cuántas piezas están activas y capturadas
agregarPieza() — agrega una nueva pieza al arreglo
seleccionarTipoDePieza() / obtenerValorDePieza() — helpers de tipo y valor
mostrarMenu() — muestra el menú de opciones
Funciones a desarrollar en el examen:

Función	Qué debe hacer
buscarPieza()	Búsqueda binaria por posición (fila y columna)
listarPiezasPorValor()	Listar todas las piezas ordenadas por valor
listarPiezasPorPosicion()	Listar todas las piezas ordenadas por posición
listarPiezasActivas()	Mostrar solo las piezas con activa == 1
capturarPieza()	Poner activa = 0 a la pieza en esa posición
modificarPieza()	Modificar los datos de una pieza por posición
🧠 Temas del 2° Parcial
Arreglos
Un arreglo es un conjunto finito, ordenado y homogéneo de elementos.
Homogéneo: todos los elementos son del mismo tipo.
Ordenado: los elementos tienen posiciones definidas (0, 1, 2...).
Finito: tiene un número específico de elementos.
Declaración: tipo nombre[tamaño]; o con inicialización: tipo nombre[] = {v1, v2, v3};
La declaración char nombre[longitud]; corresponde a una cadena de caracteres, no a un arreglo genérico.
Búsqueda en Arreglos
Búsqueda secuencial: recorre el arreglo elemento por elemento hasta encontrar el valor.
for (int i = 0; i < n; i++) {
    if (arr[i] == buscado) { encontrado = 1; }
}
// Si se encontró, encontrado vale 1 (no el valor buscado)
Búsqueda binaria: solo aplica en arreglos ordenados. Divide el arreglo a la mitad en cada paso, lo que la hace mucho más eficiente.
Ordenamiento
Burbuja (Bubble Sort): compara pares adyacentes e intercambia si están en el orden incorrecto.
Selección: busca el mínimo en cada pasada y lo coloca en su posición.
Inserción: inserta cada elemento en su posición correcta respecto a los anteriores.
Las cadenas (char[]) no se pueden ordenar con los mismos métodos directos que los arreglos numéricos (se usa strcmp para comparar).
Estructuras (struct)
Una estructura agrupa variables de tipos distintos bajo un mismo nombre definido por el usuario.
struct Persona {
    char nombre[20];
    int edad;
};
Se accede a los campos con el operador punto: persona.nombre, persona.edad.
Se pueden hacer arreglos de estructuras: struct Persona personas[100];
Para recorrer un arreglo de estructuras:
for (int i = 0; i < n; i++) {
    printf("%s - %d\n", personas[i].nombre, personas[i].edad);
}
Matrices
Arreglo de dos dimensiones: tipo nombre[filas][columnas];
Para recorrer fila por fila se usan dos bucles anidados:
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        printf("%d ", mat[i][j]); // CORRECTO: mat[i][j], no mat[i,j]
    }
}
Funciones
Las funciones en C pueden ser definidas por el usuario o predefinidas por C (de bibliotecas como stdio.h, string.h).
Ventajas: el programa se divide en módulos, cada uno con una tarea específica; los módulos probados se reutilizan.
return fuerza la salida de la función y devuelve el control a la sentencia siguiente a la llamada (no a la siguiente dentro de la función).
Ejemplo completo:
int sumar(int a, int b) {
    return a + b;
}
int main() {
    int resultado = sumar(3, 4); // resultado = 7
}
Paso de parámetros
Por valor: la función recibe una copia; los cambios NO afectan la variable original.
Por referencia (puntero): la función recibe la dirección de memoria; los cambios SÍ afectan la variable original.
void modificar(int *x) { *x = 20; }
int main() {
    int a = 10;
    modificar(&a);
    printf("%d", a); // Imprime 20
}
Importante: los arreglos se pasan siempre por referencia implícitamente, por lo que modificar arr[0] dentro de una función sí cambia el arreglo original.
Funciones de cadenas (string.h)
Función	Descripción
strcmp(s1, s2)	Compara dos cadenas; devuelve 0 si son iguales
strchr(s, c)	Localiza la primera aparición de un carácter en un string
islower(c)	Devuelve verdadero si el carácter es una letra minúscula
⚠️ Errores frecuentes del desafío de preparación
Pregunta	Error	Respuesta correcta
P3 — Relaciones búsqueda binaria	Confusión en el mapeo	"El arreglo debe estar ordenado" → para realizar la búsqueda binaria
P6 — Ventajas de funciones	Se eligió "Ninguna opción"	La correcta es la opción c: un módulo bien probado se puede reusar
P7 — Relación islower/strchr	Funciones intercambiadas	islower(c) → letra minúscula; strchr() → localiza carácter en string
P9 — Sentencia return	Se respondió Falso	Es Verdadero: return vuelve a la instrucción siguiente a la llamada
P13 — Arrays pasan por referencia	Se respondió Falso	Es Verdadero: modificar arr[0] en la función cambia el arreglo original
P25 — Variable encontrado	Se respondió 5	Vale 1 (es un flag, no el valor encontrado)
P27 — Función sumar con arreglo	Límite del for incorrecto	El límite debe ser size, no arr; acumulador debe ser arr[i]
P29 — Modificación en arreglo	Se respondió 21	Imprime 100 (se reemplazó numeros[2] con 100)
P30 — Condicional en arreglo	Se respondió 2	datos[2] vale 0 porque 6 > 5, entonces se reemplaza por 0
Lenguaje: C · Materia: Programación I · Carrera: TUP · Año: 2026