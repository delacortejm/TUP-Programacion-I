/*diseñar un prog que solicite al usuario un valor n no negativo y visualize la tabla
1   2   3 .... n
1   2   3 .... n-1
1   2   3 .... n-2
*/

#include <stdio.h>

int main(void) {
    int n, i, j;

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i = i + 1) {
        for (j = 1; j <= n - i + 1; j = j + 1) {
            printf("%3d ", j);
        }
        printf("\n");
    }

    return 0;
}